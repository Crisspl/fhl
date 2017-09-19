#include <FHL/Graphics/Model.h>

#include <utility>

#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	Model::Model(ModelData & _data) :
		UsingShader(&ResMgr::loadShader(simpleShaderName, shaderSrcs::model_Vertex, shaderSrcs::model_Fragment, Shader::FromString), &ResMgr::loadShader(lightShaderName, shaderSrcs::model_LightVertex, shaderSrcs::model_LightFragment, Shader::FromString)),
		m_modelData(&_data),
		m_vaos(_data.getMeshes().size()),
		m_color(Color::Black()),
		m_useColorOnly(false)
	{
		setUp();
	}

	void Model::setModelData(ModelData & _data)
	{
		m_modelData = &_data;
		m_vaos.resize(_data.getMeshes().size());
		setUp();
	}

	fhl::Cube Model::getAABB() const
	{
		return fhl::Cube(getPosition() - getOrigin() + m_modelData->getLeftBottomRear(), getSize());
	}

	void Model::setUp()
	{
#define offsetOfVertexMember(m) (GLvoid*)offsetof(internal::Mesh::Vertex, m)
		constexpr GLsizei stride = sizeof(internal::Mesh::Vertex);

		const auto & meshes = m_modelData->getMeshes();
		for (int i = 0; i < meshes.size(); i++)
		{
			m_vaos[i].bind();

			meshes[i].vbo.bind(internal::Buffer::Target::ArrayBuffer);
			meshes[i].ebo.bind(internal::Buffer::Target::ElementArrayBuffer);

			glVertexAttribPointer(AttrLoc::Position, 3, GL_FLOAT, GL_FALSE, stride, offsetOfVertexMember(position));
			glEnableVertexAttribArray(AttrLoc::Position);

			glVertexAttribPointer(AttrLoc::Normal, 3, GL_FLOAT, GL_FALSE, stride, offsetOfVertexMember(normal));
			glEnableVertexAttribArray(AttrLoc::Normal);

			glVertexAttribPointer(AttrLoc::TexCoord, 2, GL_FLOAT, GL_FALSE, stride, offsetOfVertexMember(texCoords));
			glEnableVertexAttribArray(AttrLoc::TexCoord);

			m_vaos[i].unbind();
		}
#undef offsetOfVertexMember
	}

}
