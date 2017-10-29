#include <FHL/Graphics/ColoredRect.h>

#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 ColoredRect::ColoredRect(const Vec2f & _size, const Color & _color) :
		  Sizeable(_size),
		  UsingShader(ResMgr::loadShader(simpleShaderName(), shaderSrcs::coloredRect_Vertex, shaderSrcs::coloredRect_Fragment, Shader::FromString),
					ResMgr::loadShader(lightShaderName(), shaderSrcs::coloredRect_LightVertex, shaderSrcs::coloredRect_LightFragment, Shader::FromString)),
		  m_color(_color)
	 {
		  setUp();
	 }

	 Rect ColoredRect::getAABB() const
	 {
		 return Rect(getPosition() - getOrigin(), getSize() * getScale());
	 }

	 OrientedRect ColoredRect::getOBB() const
	 {
		 return OrientedRect(*this, getSize() * getScale());
	 }

	 void ColoredRect::setUp()
	 {
		  getVao().bind();

		  Configurator::getRectShapeEbo().forcedBind(detail::Buffer::Target::ElementArrayBuffer);

		  getVao().unbind();
	 }

}