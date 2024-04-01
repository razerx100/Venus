#ifndef I_THREAD_POOL_HPP_
#define I_THREAD_POOL_HPP_
#include <functional>

class IThreadPool {
public:
	virtual ~IThreadPool() = default;

	virtual void SubmitWork(std::function<void()> workFunction) noexcept = 0;
};
#endif
