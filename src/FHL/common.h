#ifndef FHL_COMMON_H
#define FHL_COMMON_H

#pragma warning (disable:4251)

#ifdef FHL_SHARED
	#define FHL_API __declspec(dllexport)
#else
	#define FHL_API __declspec(dllimport)
#endif

#endif
