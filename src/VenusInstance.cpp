#include <VenusInstance.hpp>

#ifdef VENUS_WIN32
#include <ThreadPoolWin32.hpp>
#else
#include <ThreadPoolSTD.hpp>
#endif

IThreadPool* CreateVenusInstance() {
#ifdef VENUS_WIN32
	return new ThreadPoolWin32();
#else
	return new ThreadPoolSTD();
#endif
}
