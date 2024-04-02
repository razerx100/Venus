#ifndef THREAD_POOL_STANDARD_HPP_
#define THREAD_POOL_STANDARD_HPP_
#include <functional>
#include <future>
#include <condition_variable>
#include <memory>
#include <type_traits>
#include <queue>
#include <exception>

class ThreadPool
{
private:
	class ITask
	{
	public:
		virtual ~ITask() = default;

		virtual void RunTask() = 0;
	};

	template<typename T>
	class TaskImpl : public ITask
	{
	public:
		TaskImpl(std::function<T()> taskFunction) : m_promise{}, m_taskFuntion{ taskFunction } {}

		void RunTask()
		{
			if constexpr (std::is_same_v<T, void>)
			{
				try
				{
					m_taskFuntion();
					m_promise.set_value();
				}
				catch (...)
				{
					m_promise.set_exception(std::current_exception());
				}
			}
			else
			{
				try
				{
					m_promise.set_value(m_taskFuntion());
				}
				catch (...)
				{
					m_promise.set_exception(std::current_exception());
				}
			}
		}

		[[nodiscard]]
		std::future<T> GetFuture()
		{
			return m_promise.get_future();
		}

	private:
		std::promise<T>    m_promise;
		std::function<T()> m_taskFuntion;
	};

public:
	ThreadPool(size_t threadCount);
	~ThreadPool() noexcept;

	template<typename T>
	std::future<T> SubmitWork(std::function<T()> workFunction) noexcept
	{
		std::future<T> waitObject{};
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			auto task  = std::make_shared<TaskImpl<T>>(workFunction);
			waitObject = task->GetFuture();

			m_workQueue.push(std::move(task));
			++m_worksCount;
		}

		m_cVar.notify_one();

		return waitObject;
	}

private:
	void WorkThread();

private:
	std::atomic_bool                   m_worksDone;
	std::atomic_size_t                 m_threadRunningCounter;
	std::atomic_size_t                 m_worksCount;
	std::vector<std::thread>           m_threads;
	std::queue<std::shared_ptr<ITask>> m_workQueue;
	std::mutex                         m_mutex;
	std::condition_variable            m_cVar;

public:
	ThreadPool(const ThreadPool&) = delete;
	ThreadPool& operator=(const ThreadPool&) = delete;
};
#endif
