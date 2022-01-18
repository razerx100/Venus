#include <VenusInstance.hpp>
#include <ThreadPool.hpp>

static IThreadPool* s_threadPool = nullptr;

IThreadPool* GetVenusInstance() noexcept {
	return s_threadPool;
}

void CreateVenusInstance(size_t threadCount) {
	if (!s_threadPool)
		s_threadPool = new ThreadPool(threadCount);
}

void CleanUpVenusInstance() noexcept {
	if (s_threadPool) {
		delete s_threadPool;
		s_threadPool = nullptr;
	}
}
