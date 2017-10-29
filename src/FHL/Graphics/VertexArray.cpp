#include <FHL/Graphics/VertexArray.h>

#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 VertexArray::VertexArray(Mode _mode) :
			UsingShader(ResMgr::loadShader(simpleShaderName(), shaderSrcs::coloredRect_Vertex, shaderSrcs::coloredRect_Fragment, Shader::FromString), nullptr),
			m_mode(_mode)
	 {
		 setUp();
	 }

	 VertexArray & VertexArray::updateBuffer()
	 {
		 auto buffer = m_vao.getBuffer(s_bufferName);
		 buffer->bind(detail::Buffer::Target::CopyWriteBuffer);
		 buffer->setData(sizeof(Vertex) * m_vertices.size(), m_vertices.data());
		 buffer->unbind(detail::Buffer::Target::CopyWriteBuffer);
		 return *this;
	 }

	 VertexArray & VertexArray::addVertex(const Vertex & _vert)
	 {
		 m_vertices.push_back(_vert);
		 return *this;
	 }

	 VertexArray & VertexArray::addVertices(const std::vector<Vertex> & _v)
	 {
		  m_vertices.insert(m_vertices.begin(), _v.begin(), _v.end());
		  return *this;
	 }

	 void VertexArray::setUp()
	 {
		 m_vao.bind();

		 detail::Buffer buffer(detail::Buffer::Usage::DynamicDraw);
		 buffer.bind(detail::Buffer::Target::ArrayBuffer);

		 m_vao.addBuffer(s_bufferName, std::move(buffer));

		 glVertexAttribPointer((GLuint)AttLoc::Position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
		 glEnableVertexAttribArray((GLuint)AttLoc::Position);

		 glVertexAttribPointer((GLuint)AttLoc::Color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
		 glEnableVertexAttribArray((GLuint)AttLoc::Color);

		 m_vao.unbind();
	 }

}
