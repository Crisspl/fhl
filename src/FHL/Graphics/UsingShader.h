#ifndef FHL_USINGSHADER_H
#define FHL_USINGSHADER_H

#include <FHL/Graphics/Shader.h>

namespace fhl
{
	 class FHL_API UsingShader
	 {
	 protected:
		  struct SimpleShader_t {};
		  struct LightShader_t {};

	 public:
		  UsingShader(Shader * _simple, Shader * _light) : m_simpleShader(_simple), m_lightShader(_light), m_shader(_simple) { }
		  virtual ~UsingShader() = default;

		  void setShader(SimpleShader_t) { m_shader = m_simpleShader; }
		  virtual void setShader(LightShader_t) { m_shader = m_lightShader; }
		  void setShader(Shader & _shader) { m_shader = &_shader; }

		  void setSimpleShader(Shader & _shader) { m_simpleShader = &_shader; }
		  virtual void setLightShader(Shader & _shader) { m_lightShader = &_shader; }

	 protected:
		  Shader * getShader() const { return m_shader; }

	 public:
		  static SimpleShader_t Simple;
		  static LightShader_t Light;

	 private:
		  Shader * m_simpleShader, * m_lightShader;
		  Shader * m_shader;
	 };
}

#endif // FHL_USINGSHADER_H
