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
		m_color(Color::Black),
		m_useColorOnly(false)
	{
		setUp();
	}

	void Model::render(const RenderConf & _conf) const
	{
		if (!getShader())
			return;

		if (!Configurator::isDepthTestEnabled())
			glEnable(GL_DEPTH_TEST);

		Shader & shader = *getShader();
		shader.use();

		bool useCustomConf = _conf != RenderConf::Default;

		const auto & lights = useCustomConf ? _conf.lights : getLights();
		const auto & matrices = useCustomConf ? _conf.matrices : getMatrices();

		shader.setMat4f("mvp", matrices.mvp)
			.setMat4f("model", matrices.transform)
			.setMat4f("inverseModel", matrices.inverseTransform)
			.setVec3("cameraPos", matrices.cameraPosition)
			.setFloat("material.shininess", 5.f)
			.setLights("light", lights.cbegin(), lights.cend())
			.setBoolean("useColorOnly", m_useColorOnly)
			.setColor("singleColor", m_color);

		renderMeshes();

		Shader::unuse();

		if (!Configurator::isDepthTestEnabled())
			glDisable(GL_DEPTH_TEST);
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

			meshes[i].vbo.bind();
			meshes[i].ebo.bind();

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

	void Model::renderMeshes() const
	{
		const auto & meshes = m_modelData->getMeshes();
		for (int i = 0; i < meshes.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0);
			getShader()->setInt("material.texture_diffuse", 0);
			glBindTexture(GL_TEXTURE_2D, meshes[i].textures.diffuse);
			glActiveTexture(GL_TEXTURE1);
			getShader()->setInt("material.texture_specular", 1);
			glBindTexture(GL_TEXTURE_2D, meshes[i].textures.specular);

			m_vaos[i].bind();
			glDrawElements(GL_TRIANGLES, meshes[i].indicesCount, GL_UNSIGNED_INT, 0);
			m_vaos[i].unbind();

			for (GLuint j = 0; j < 2u; j++)
			{
				glActiveTexture(GL_TEXTURE0 + j);
				glBindTexture(GL_TEXTURE_2D, 0);
			}
			glActiveTexture(GL_TEXTURE0);
		}
	}

}
