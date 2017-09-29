#ifndef FHL_GRAPHICS_USING_SHADER_H
#define FHL_GRAPHICS_USING_SHADER_H

namespace fhl
{

	class Shader;

	class FHL_API UsingShader
	{
	public:
		enum class Type
		{
			Simple,
			Light
		};

		UsingShader(Shader * _simple, Shader * _light) : m_simpleShader(_simple), m_lightShader(_light), m_shader(_simple) { }
		virtual ~UsingShader() = default;

		void setShader(Type _t) { m_shader = _t == Type::Simple ? m_simpleShader : m_lightShader; }
		void setShader(Shader & _shader) { m_shader = &_shader; }

		void setSimpleShader(Shader & _shader) { m_simpleShader = &_shader; }
		void setLightShader(Shader & _shader) { m_lightShader = &_shader; }

		Shader * getShader() const { return m_shader; }

	private:
		Shader * m_simpleShader, * m_lightShader;
		Shader * m_shader;
	};

}

#endif
