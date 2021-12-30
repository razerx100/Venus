#ifndef __THREAD_POOL_STANDARD_HPP__
#define __THREAD_POOL_STANDARD_HPP__
#include <IThreadPool.hpp>

class ThreadPoolSTD : public IThreadPool {
public:
	ThreadPoolSTD(std::uint32_t threadCount);
	~ThreadPoolSTD() noexcept;

	void SubmitWork(void* workFunction) override;
};
#endif
