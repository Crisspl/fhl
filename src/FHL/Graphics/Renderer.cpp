#include <FHL/Graphics/Renderer.h>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/Renderable.h>
#include <FHL/Graphics/ColoredRect.h>
#include <FHL/Graphics/Sprite.h>
#include <FHL/Graphics/VertexArray.h>
#include <FHL/Graphics/Model.h>

namespace fhl
{
	void Renderer::render(const ColoredRect & _renderable, const RenderConf & _conf)
	{
		if (!_renderable.getShader())
			return;

		Shader & shader = *_renderable.getShader();
		shader.use();

		bool usingCustomRc = ! isDefaultRenderConfInstance(_conf);

		const auto & lights = usingCustomRc ? _conf.lights : _renderable.getLights();
		const auto & matrices = usingCustomRc ? _conf.matrices : _renderable.getMatrices();

		shader.setMat4f("mvp", matrices.mvp)
			.setMat4f("model", matrices.transform)
			.setVec3("cameraPos", matrices.cameraPosition)
			.setVec4("vertColor", _renderable.getColor().asVec4())
			.setLights("light", lights.cbegin(), lights.cend());

		_renderable.getVao().bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		_renderable.getVao().unbind();

		Shader::unuse();
	}

	void Renderer::render(const Sprite & _renderable, const RenderConf & _conf)
	{
		if (!_renderable.getShader())
			return;

		Shader & shader = *_renderable.getShader();
		shader.use();

		bool usingCustomRc = ! isDefaultRenderConfInstance(_conf);

		const auto & lights = usingCustomRc ? _conf.lights : _renderable.getLights();
		const auto & matrices = usingCustomRc ? _conf.matrices : _renderable.getMatrices();

		shader.setMat4f("mvp", matrices.mvp)
			.setMat4f("model", matrices.transform)
			.setVec3("cameraPos", matrices.cameraPosition)
			.setVec4("color", _renderable.getColor().asVec4())
			.setInt("texSampler", 0)
			.setLights("light", lights.cbegin(), lights.cend());

		glActiveTexture(GL_TEXTURE0);

		if (usingCustomRc && _conf.texture)
			glBindTexture(GL_TEXTURE_2D, _conf.texture->getId());
		else if (_renderable.getTexture())
			glBindTexture(GL_TEXTURE_2D, _renderable.getTexture()->getId());

		_renderable.getVao().bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		_renderable.getVao().unbind();

		glBindTexture(GL_TEXTURE_2D, 0);
		Shader::unuse();
	}

	void Renderer::render(const VertexArray & _renderable, const RenderConf &)
	{
		if (!_renderable.getShader())
			return;

		Shader & shader = *_renderable.getShader();
		shader.use();

		shader.setMat4f("projection", Configurator::projection())
			.setMat4f("view", Configurator::view());

		_renderable.getVao().bind();
		glDrawArrays(static_cast<GLenum>(_renderable.getMode()), 0, _renderable.getVerticesCount());
		_renderable.getVao().unbind();

		Shader::unuse();
	}

	void Renderer::render(const Model & _renderable, const RenderConf & _conf)
	{
		if (!_renderable.getShader())
			return;

		if (!Configurator::isDepthTestEnabled())
			glEnable(GL_DEPTH_TEST);

		Shader & shader = *_renderable.getShader();
		shader.use();

		bool usingCustomRc = !isDefaultRenderConfInstance(_conf);

		const auto & lights = usingCustomRc ? _conf.lights : _renderable.getLights();
		const auto & matrices = usingCustomRc ? _conf.matrices : _renderable.getMatrices();

		shader.setMat4f("mvp", matrices.mvp)
			.setMat4f("model", matrices.transform)
			.setMat4f("inverseModel", matrices.inverseTransform)
			.setVec3("cameraPos", matrices.cameraPosition)
			.setFloat("material.shininess", 5.f)
			.setLights("light", lights.cbegin(), lights.cend())
			.setBoolean("useColorOnly", _renderable.getUseColorOnly())
			.setColor("singleColor", _renderable.getColor());

		const auto & meshes = _renderable.getModelData()->getMeshes();
		const auto & vaos = _renderable.getVaos();
		for (int i = 0; i < meshes.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0);
			shader.setInt("material.texture_diffuse", 0);
			glBindTexture(GL_TEXTURE_2D, meshes[i].getDiffuseTextureId());
			glActiveTexture(GL_TEXTURE0 + 1);
			shader.setInt("material.texture_specular", 1);
			glBindTexture(GL_TEXTURE_2D, meshes[i].getSpecularTextureId());

			vaos[i].bind();
			glDrawElements(GL_TRIANGLES, meshes[i].getIndicesCount(), GL_UNSIGNED_INT, 0);
			vaos[i].unbind();
		}
		for (int j = 1; j >= 0; j--)
		{
			glActiveTexture(GL_TEXTURE0 + j);
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		Shader::unuse();

		if (!Configurator::isDepthTestEnabled())
			glDisable(GL_DEPTH_TEST);
	}

	void Renderer::render(const Renderable & _renderable, const RenderConf & _conf)
	{
		_renderable.render(_conf);
	}

	void Renderer::clearColor(const Color & _color)
	{
		glClearColor(_color.r, _color.g, _color.b, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Renderer::isDefaultRenderConfInstance(const RenderConf & _rc)
	{
		return &_rc == &RenderConf::default();
	}

}
