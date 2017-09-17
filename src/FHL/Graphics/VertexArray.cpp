#include <FHL/Graphics/VertexArray.h>

#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 VertexArray::VertexArray(Mode _mode) :
			UsingShader(&ResMgr::loadShader(simpleShaderName, shaderSrcs::coloredRect_Vertex, shaderSrcs::coloredRect_Fragment, Shader::FromString), nullptr),
			m_mode(_mode)
	 {
		 setUp();
	 }

	 VertexArray & VertexArray::addVertex(const Vertex & _vert)
	 {
		 m_vertices.push_back(_vert);
		 updateArray();

		 return *this;
	 }

	 VertexArray & VertexArray::addVertices(const std::initializer_list<Vertex> & _v)
	 {
		  m_vertices.insert(m_vertices.begin(), _v.begin(), _v.end());
		  updateArray();

		  return *this;
	 }

	 void VertexArray::render(const RenderConf &) const
	 {
		  if (!getShader())
				return;

		 Shader & shader = *getShader();
		 shader.use();

		 shader.setMat4f("projection", Configurator::projection())
				.setMat4f("view", Configurator::view());

		 m_vao.bind();
		 glDrawArrays(m_mode, 0, m_vertices.size());
		 m_vao.unbind();

		 Shader::unuse();
	 }

	 void VertexArray::setUp()
	 {
		 m_vao.bind();

		 internal::Buffer buffer(internal::Buffer::Usage::DynamicDraw);
		 buffer.bind(internal::Buffer::Target::ArrayBuffer);

		 m_vao.addBuffer("vertexBuffer", std::move(buffer));

		 glVertexAttribPointer((GLuint)AttLoc::Position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
		 glEnableVertexAttribArray((GLuint)AttLoc::Position);

		 glVertexAttribPointer((GLuint)AttLoc::Color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
		 glEnableVertexAttribArray((GLuint)AttLoc::Color);

		 m_vao.unbind();
	 }

	 void VertexArray::updateArray()
	 {
		  auto buffer = m_vao.getBuffer("vertexBuffer");
		  buffer->bind(internal::Buffer::Target::ArrayBuffer);
		  buffer->setData(sizeof(Vertex) * m_vertices.size(), m_vertices.data());
		  buffer->unbind(internal::Buffer::Target::ArrayBuffer);
	 }

}
