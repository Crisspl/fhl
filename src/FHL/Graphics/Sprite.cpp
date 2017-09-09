#include <FHL/Graphics/Sprite.h>

#include <iostream>
#include <algorithm>

#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 Sprite::Sprite() : 
		  TexturedSizeable(nullptr),
		  UsingShader(&ResMgr::loadShader(simpleShaderName, shaderSrcs::sprite_Vertex, shaderSrcs::sprite_Fragment, Shader::FromString),
					&ResMgr::loadShader(lightShaderName, shaderSrcs::sprite_LightVertex, shaderSrcs::sprite_LightFragment, Shader::FromString)),
		  m_color(Color::White())
	 {
		  setUp();
	 }

	 Sprite::Sprite(Texture & _tex) :
		  TexturedSizeable(&_tex, _tex.getSize()),
		  UsingShader(&ResMgr::loadShader(simpleShaderName, shaderSrcs::sprite_Vertex, shaderSrcs::sprite_Fragment, Shader::FromString),
						  &ResMgr::loadShader(lightShaderName, shaderSrcs::sprite_LightVertex, shaderSrcs::sprite_LightFragment, Shader::FromString)),
		  m_color(Color::White())
	 {
		  setUp();
	 }

	 void Sprite::render(const RenderConf & _conf) const
	 {
		  if (!getShader())
				return;

		  Shader & shader = *getShader();
		  shader.use();

		  glActiveTexture(GL_TEXTURE0);
		  shader.setInt("texSampler", 0);
		  shader.setColor("color", m_color);

		  bool useCustomConf = _conf != RenderConf::default();

		  if (useCustomConf && _conf.texture)
				glBindTexture(GL_TEXTURE_2D, _conf.texture->getId());
		  else if (getTexture())
				glBindTexture(GL_TEXTURE_2D, getTexture()->getId());

		  const auto & lights = useCustomConf ? _conf.lights : getLights();
		  const auto & matrices = useCustomConf ? _conf.matrices : getMatrices();

		  shader.setMat4f("mvp", matrices.mvp)
				.setMat4f("model", matrices.transform)
				.setVec3("cameraPos", matrices.cameraPosition)
				.setLights("light", lights.cbegin(), lights.cend());

		  getVao().bind();
		  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		  getVao().unbind();

		  glBindTexture(GL_TEXTURE_2D, 0);
		  Shader::unuse();
	 }

	 Rect Sprite::getAABB() const
	 {
		  return Rect(getPosition() - getOrigin(), getSize());
	 }

	 OrientedRect Sprite::getOBB() const
	 {
		  return OrientedRect(getSize(), getTransformData());
	 }

	 void Sprite::setUp()
	 {
		  getVao().bind();

		  Configurator::getRectShapeEbo().forcedBind(internal::Buffer::Target::ElementArrayBuffer);

		  getVao().unbind();
	 }

} // ns