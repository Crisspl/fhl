#ifndef FHL_COMMON_H
#define FHL_COMMON_H

#if !defined(_WIN32) && !defined(FHL_PLATFORM_WINDOWS) // needed for user-compilation to properly define FHL_IMPORT on Windows
	#define FHL_PLATFORM_WINDOWS
#endif

#ifdef FHL_PLATFORM_WINDOWS
	#ifdef _MSC_VER
		#pragma warning (disable:4251)
	#endif
	#define FHL_EXPORT __declspec(dllexport)
	#define FHL_IMPORT __declspec(dllimport)
#else
	#define FHL_EXPORT
	#define FHL_IMPORT
#endif

#ifdef FHL_SHARED
	#define FHL_API FHL_EXPORT
#else
	#define FHL_API FHL_IMPORT
#endif

#endif
