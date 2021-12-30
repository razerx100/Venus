#include <VenusInstance.hpp>

#ifdef VENUS_WIN32
#include <ThreadPoolWin32.hpp>
#else
#include <ThreadPoolSTD.hpp>
#endif

static IThreadPool* s_threadPool = nullptr;

IThreadPool* GetVenusInstance() noexcept {
	return s_threadPool;
}

void CreateVenusInstance(std::uint32_t threadCount) {
	if (!s_threadPool)
#ifdef VENUS_WIN32
		s_threadPool = new ThreadPoolWin32(threadCount);
#else
		s_threadPool = new ThreadPoolSTD(threadCount);
#endif
}

void CleanUpVenusInstance() noexcept {
	if (s_threadPool) {
		delete s_threadPool;
		s_threadPool = nullptr;
	}
}
