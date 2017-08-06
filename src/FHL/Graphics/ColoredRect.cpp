#include <FHL/Graphics/ColoredRect.h>

#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/ResMgr.h>
#include <FHL/Graphics/ShaderSrcs.h>

namespace fhl
{

	 ColoredRect::ColoredRect(Vec2f _size, Color _color) :
		  Sizeable(_size),
		  UsingShader(&ResMgr::loadShader(simpleShaderName, shaderSrcs::coloredRect_Vertex, shaderSrcs::coloredRect_Fragment, Shader::FromString),
					&ResMgr::loadShader(lightShaderName, shaderSrcs::coloredRect_LightVertex, shaderSrcs::coloredRect_LightFragment, Shader::FromString)),
		  m_color(_color)
	 {
		  setUp();
	 }

	 void ColoredRect::render(const RenderConf & _conf) const
	 {
		  if (!getShader())
				return;

		  Shader & shader = *getShader();
		  shader.use();
	 
		  bool useCustomConf = _conf != RenderConf::Default;

		  const auto & lights = useCustomConf ? _conf.lights : getLights();
		  const auto & matrices = useCustomConf ? _conf.matrices : getMatrices();

		  shader.setMat4f("mvp", matrices.mvp)
				.setMat4f("model", matrices.transform)
				.setVec3("cameraPos", matrices.cameraPosition)
				.setVec4("vertColor", m_color.asVec4())
				.setLights("light", lights.cbegin(), lights.cend());

		  getVao().bind();
		  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		  getVao().unbind();

		  Shader::unuse();
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

		  Configurator::getRectShapeEbo().bind();

		  getVao().unbind();
	 }

}