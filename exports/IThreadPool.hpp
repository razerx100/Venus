#ifndef __I_THREAD_POOL_HPP__
#define __I_THREAD_POOL_HPP__
#include <cstdint>

#ifdef BUILD_VENUS
#define VENUS_DLL __declspec(dllexport)
#else
#define VENUS_DLL __declspec(dllimport)
#endif

class VENUS_DLL IThreadPool {
public:
	virtual ~IThreadPool() = default;

	virtual void Create(std::uint32_t threadCount) noexcept = 0;
	virtual void CleanUp() noexcept = 0;
	virtual void SubmitWork(void* workFunction) = 0;
};
#endif
