#ifndef VENUS_INSTANCE_HPP_
#define VENUS_INSTANCE_HPP_
#include <IThreadPool.hpp>

#ifdef BUILD_VENUS
#define VENUS_DLL __declspec(dllexport)
#else
#define VENUS_DLL __declspec(dllimport)
#endif

VENUS_DLL IThreadPool* __cdecl CreateVenusInstance(size_t threadCount);
#endif
