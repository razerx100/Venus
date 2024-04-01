#include <VenusInstance.hpp>
#include <ThreadPool.hpp>

IThreadPool* CreateVenusInstance(size_t threadCount) {
	return new ThreadPool(threadCount);
}
