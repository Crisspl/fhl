#include <FHL/Utility/Debug.h>

namespace fhl
{

	void Debug::setOutStream(std::ostream & _out)
	{
		m_out = &_out;
	}

	Debug & Debug::Log()
	{
		static Debug d;
		return d;
	}

}