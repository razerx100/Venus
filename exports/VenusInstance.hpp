#ifndef __VENUS_INSTANCE_HPP__
#define __VENUS_INSTANCE_HPP__
#include <IThreadPool.hpp>
#include <cstdint>

VENUS_DLL IThreadPool* __cdecl GetVenusInstance() noexcept;
VENUS_DLL void __cdecl CreateVenusInstance(size_t threadCount);
VENUS_DLL void __cdecl CleanUpVenusInstance() noexcept;
#endif
