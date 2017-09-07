#ifndef FHL_COMMON_H
#define FHL_COMMON_H

#ifdef _MSC_VER
	#pragma warning (disable:4251)
#endif

#ifdef FHL_PLATFORM_WINDOWS
	#ifdef FHL_SHARED
		#define FHL_API __declspec(dllexport)
	#else
		#define FHL_API __declspec(dllimport)
	#endif
#else
	#define FHL_API
#endif

#endif
