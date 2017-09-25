#ifndef FHL_UNIFORM_LOC_MGR_H
#define FHL_UNIFORM_LOC_MGR_H

#include <map>

#include <FHL/GL/OpenGL.h>

namespace fhl { namespace impl
{

	/* Utility class for Shader */
	class UniformLocMgr
	{
	public:
		GLint getUniformLoc(GLuint _id, const GLchar * _name);

	private:
		std::size_t hash(const GLchar * _str);

	private:
		std::map<std::size_t, GLint> m_uniformLocs;
	};

}}

#endif
