#include <FHL/Graphics/ColoredRect.h>

#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 ColoredRect::ColoredRect(Vec2f _size, Color _color) :
		  Sizeable(_size),
		  UsingShader(&ResMgr::loadShader(simpleShaderName(), shaderSrcs::coloredRect_Vertex, shaderSrcs::coloredRect_Fragment, Shader::FromString),
					&ResMgr::loadShader(lightShaderName(), shaderSrcs::coloredRect_LightVertex, shaderSrcs::coloredRect_LightFragment, Shader::FromString)),
		  m_color(_color)
	 {
		  setUp();
	 }

	 Rect ColoredRect::getAABB() const
	 {
		 return Rect(getPosition() - getOrigin(), getSize());
	 }

	 OrientedRect ColoredRect::getOBB() const
	 {
		 return OrientedRect(getSize(), getTransformData());
	 }

	 void ColoredRect::setUp()
	 {
		  getVao().bind();

		  Configurator::getRectShapeEbo().forcedBind(internal::Buffer::Target::ElementArrayBuffer);

		  getVao().unbind();
	 }

}