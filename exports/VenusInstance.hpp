#ifndef __VENUS_INSTANCE_HPP__
#define __VENUS_INSTANCE_HPP__
#include <IThreadPool.hpp>
#include <cstdint>

#ifdef BUILD_VENUS
#define VENUS_DLL __declspec(dllexport)
#else
#define VENUS_DLL __declspec(dllimport)
#endif

VENUS_DLL IThreadPool* __cdecl GetVenusInstance() noexcept;
VENUS_DLL void __cdecl CreateVenusInstance(size_t threadCount);
VENUS_DLL void __cdecl CleanUpVenusInstance() noexcept;
#endif
