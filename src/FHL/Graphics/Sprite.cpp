#include <FHL/Graphics/Sprite.h>

#include <iostream>
#include <algorithm>

#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 Sprite::Sprite() : 
		  TexturedSizeable(nullptr),
		  UsingShader(&ResMgr::loadShader(simpleShaderName(), shaderSrcs::sprite_Vertex, shaderSrcs::sprite_Fragment, Shader::FromString),
					&ResMgr::loadShader(lightShaderName(), shaderSrcs::sprite_LightVertex, shaderSrcs::sprite_LightFragment, Shader::FromString)),
		  m_color(Color::White())
	 {
		  setUp();
	 }

	 Sprite::Sprite(Texture & _tex) :
		  TexturedSizeable(&_tex, _tex.getSize()),
		  UsingShader(&ResMgr::loadShader(simpleShaderName(), shaderSrcs::sprite_Vertex, shaderSrcs::sprite_Fragment, Shader::FromString),
						  &ResMgr::loadShader(lightShaderName(), shaderSrcs::sprite_LightVertex, shaderSrcs::sprite_LightFragment, Shader::FromString)),
		  m_color(Color::White())
	 {
		  setUp();
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