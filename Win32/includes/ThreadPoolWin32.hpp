#ifndef __THREAD_POOL_WIN32_HPP__
#define __THREAD_POOL_WIN32_HPP__
#include <IThreadPool.hpp>
#include <CleanWin.hpp>

class ThreadPoolWin32 : public IThreadPool {
public:
	ThreadPoolWin32(std::uint32_t threadCount);
	~ThreadPoolWin32() noexcept;

	void SubmitWork(void* workFunction) override;

private:
	static void CALLBACK WorkCallBack(
		PTP_CALLBACK_INSTANCE instance,
		PVOID parameter,
		PTP_WORK work
	);

private:
	TP_CALLBACK_ENVIRON m_callbackEnv;
	PTP_POOL m_threadPool;
	PTP_CLEANUP_GROUP m_cleanUpGroup;
};
#endif
