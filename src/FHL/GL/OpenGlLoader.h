#ifndef FHL_OPENGL_LOADER
#define FHL_OPENGL_LOADER

#ifdef FHL_PLATFORM_WINDOWS
	#define WIN32_LEAN_AND_MEAN 1
	#include <windows.h>
#endif

namespace fhl { namespace internal {

	class OpenGlLoader
	{
	public:
#if defined(FHL_PLATFORM_WINDOWS)
		using fptr = PROC;
#else 
		using fptr = void(*)();
#endif
		OpenGlLoader();
		~OpenGlLoader();

		fptr load(const char * _name);

	private:
#if defined(FHL_PLATFORM_WINDOWS)
		HMODULE m_gllib;
#else
		void * m_gllib;
#endif
	};

}}

#endif
