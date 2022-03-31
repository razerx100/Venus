#ifndef __I_THREAD_POOL_HPP__
#define __I_THREAD_POOL_HPP__
#include <functional>

class IThreadPool {
public:
	virtual ~IThreadPool() = default;

	virtual void SubmitWork(std::function<void()> workFunction) noexcept = 0;
};
#endif
