#ifndef FHL_DEBUG_H
#define FHL_DEBUG_H

#include <iostream>

#include <FHL/common.h>

namespace fhl
{

	class Debug
	{
		Debug() = default;

	public:
		std::ostream & operator()() { return *m_out; }
		void setOutStream(std::ostream * _out) { m_out = _out; }

	private:
		std::ostream * m_out = &std::cout;

	public:
		static Debug Log;
	};

}

#endif // FHL_DEBUG_H
