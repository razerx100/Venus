#ifndef __THREAD_POOL_STANDARD_HPP__
#define __THREAD_POOL_STANDARD_HPP__
#include <IThreadPool.hpp>

class ThreadPoolSTD : public IThreadPool {
public:
	void Create(std::uint32_t threadCount) noexcept override;
	void CleanUp() noexcept override;
	void SubmitWork(void* workFunction) override;
};
#endif
