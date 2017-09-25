#include "UniformLocMgr.h"

#include <cstring>

namespace fhl { namespace impl
{
	GLint UniformLocMgr::getUniformLoc(GLuint _id, const GLchar * _name)
	{
		const std::size_t h = this->hash(_name);
		const auto it = m_uniformLocs.find(h);

		if (it != m_uniformLocs.cend())
			return it->second;
		else
		{
			const GLint loc = glGetUniformLocation(_id, _name);
			if (loc >= 0) m_uniformLocs.insert({ h, loc });
			return loc;
		}
	}

	std::size_t UniformLocMgr::hash(const GLchar * _str)
	{
		constexpr std::size_t base = 2166136261u;
		constexpr std::size_t prime = 16777619u;

		const std::size_t len = std::strlen(_str);

		std::size_t h = base;
		for (int i = 0; i < len; ++i)
		{
			h ^= (std::size_t)_str[i];
			h *= prime;
		}
		return h;
	}

}}
