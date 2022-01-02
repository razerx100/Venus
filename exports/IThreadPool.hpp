#ifndef __I_THREAD_POOL_HPP__
#define __I_THREAD_POOL_HPP__
#include <functional>

#ifdef BUILD_VENUS
#define VENUS_DLL __declspec(dllexport)
#else
#define VENUS_DLL __declspec(dllimport)
#endif

class VENUS_DLL IThreadPool {
public:
	virtual ~IThreadPool() = default;

	virtual void SubmitWork(std::function<void()> workFunction) noexcept = 0;
};
#endif
