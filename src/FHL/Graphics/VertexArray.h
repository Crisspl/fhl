#ifndef FHL_VERTEXARRAY_H
#define FHL_VERTEXARRAY_H


#include <vector>
#include <memory>
#include <initializer_list>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Renderable.h>
#include <FHL/Graphics/Vertex.h>
#include <FHL/Graphics/Shader.h>
#include <FHL/Graphics/Vao.h>
#include <FHL/Graphics/UsingShader.h>

namespace fhl
{

	class ResMgr;

	class FHL_API VertexArray
		: public Renderable,
		public UsingShader
	{
		friend class ResMgr;

	public:
		enum Mode : GLenum
		{
			Points = GL_POINTS,
			LineStrip = GL_LINE_STRIP,
			LineLoop = GL_LINE_LOOP,
			Lines = GL_LINES,
			LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
			LinesAdjacency = GL_LINES_ADJACENCY,
			TriangleStrip = GL_TRIANGLE_STRIP,
			TriangleFan = GL_TRIANGLE_FAN,
			Triangles = GL_TRIANGLES,
			TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
			TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
		};

	private:
		enum class AttLoc : GLuint
		{
			Position,
			Color
		};

	public:
		explicit VertexArray(Mode _mode);

		void render(const RenderConf &) const override;

		Vertex operator[](unsigned _i) const { return m_vertices[_i]; }
		Vertex & operator[](unsigned _i) { return m_vertices[_i]; }

		VertexArray & setMode(Mode _mode) { m_mode = _mode; return *this; }

		VertexArray & addVertex(const Vertex & _vert);
		VertexArray & addVertices(const std::initializer_list<Vertex> & _v);

	private:
		void setUp();
		void updateArray();

	private:
		Mode m_mode;
		std::vector<Vertex> m_vertices;
		internal::Vao m_vao;

		constexpr static const char * simpleShaderName = "_FHL_vertexArraySimpleShader";
	};

}

#endif
