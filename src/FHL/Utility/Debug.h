#ifndef FHL_UTILITY_DEBUG_H
#define FHL_UTILITY_DEBUG_H

#include <ostream>

#include <FHL/common.h>

namespace fhl
{

	class FHL_API Debug
	{
		Debug() = default;
		Debug(const Debug &) = delete;
		Debug & operator=(const Debug &) = delete;

	public:
		template<typename T>
		Debug & operator<<(const T & o);

		void setOutStream(std::ostream & _out);

	private:
		std::ostream * m_out = nullptr;

	public:
		static Debug & Log();
	};

	template<typename T>
	inline Debug & Debug::operator<<(const T & o)
	{
		if (m_out) *m_out << o;
		return *this;
	}

}

#endif
