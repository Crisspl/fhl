#ifndef FHL_SHADER_H
#define FHL_SHADER_H

#include <algorithm>
#include <vector>
#include <string>
#include <type_traits>
#include <iterator>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Color.h>
#include <FHL/Graphics/Light.h>
#include <FHL/Maths/Mat4.h>

namespace fhl
{

#define _FHL_DEFINE_UNFIORM_SETTER_FOR_VECTOR_SIZE(_size) \
template<typename T> \
struct UniformSetterForVec##_size; \
template<> \
struct UniformSetterForVec##_size<float> \
{ \
	void operator()(GLint _loc, const Vec##_size<float> & _v) { glUniform##_size##fv(_loc, 1u, _v.data()); } \
}; \
template<> \
struct UniformSetterForVec##_size<int> \
{ \
	void operator()(GLint _loc, const Vec##_size<int> & _v) { glUniform##_size##iv(_loc, 1u, _v.data()); } \
}; \
template<> \
struct UniformSetterForVec##_size<unsigned> \
{ \
	void operator()(GLint _loc, const Vec##_size<unsigned> & _v) { glUniform##_size##uiv(_loc, 1u, _v.data()); } \
};

	namespace impl
	{
		_FHL_DEFINE_UNFIORM_SETTER_FOR_VECTOR_SIZE(2)
		_FHL_DEFINE_UNFIORM_SETTER_FOR_VECTOR_SIZE(3)
		_FHL_DEFINE_UNFIORM_SETTER_FOR_VECTOR_SIZE(4)
	};
#undef _FHL_DEFINE_UNFIORM_SETTER_FOR_VECTOR_SIZE

	class ResMgr;

	class FHL_API Shader
	{
		friend class ResMgr;

		template<typename, typename>
		friend struct std::pair;

	public:
		enum SourceFrom
		{
			FromFile = 0,
			FromString
		};

	private:
		Shader(const Shader &) = delete;
		Shader & operator=(const Shader &) = delete;
		Shader(Shader && _other);
		Shader & operator=(Shader && _other);
		Shader(const GLchar * _vert, const GLchar * _frag, const SourceFrom _srcFrom = SourceFrom::FromFile);

		~Shader();

	public:
		void use() const { glUseProgram(m_id); }
		static void unuse() { glUseProgram(0); }

		GLuint getId() const { return m_id; }

		Shader & setBoolean(const GLchar * _name, const GLboolean _value);
		Shader & setFloat(const GLchar * _name, const GLfloat _value);
		Shader & setInt(const GLchar * _name, const GLint _value);
		Shader & setUnsignedInt(const GLchar * _name, const GLuint _value);
		Shader & setColor(const GLchar * _name, const Color & _value);
		Shader & setMat4f(const GLchar * _name, const Mat4f & _matrix);

		template<typename _T>
		Shader & setVec2(const GLchar * _name, const Vec2<_T> & _v);
		template<typename _T>
		Shader & setVec3(const GLchar * _name, const Vec3<_T> & _v);
		template<typename _T>
		Shader & setVec4(const GLchar * _name, const Vec4<_T> & _v);

		Shader & setLight(const GLchar * _name, const Light & _light);
		Shader & setLight(const GLchar * _name, const Light & _light, size_t _num);
		Shader & setLights(const GLchar * _name, const std::vector<Light> & _lights);

		template<typename _It>
		Shader & setLights(const GLchar * _name, _It _begin, const _It _end);

		bool operator==(const Shader &);
		bool operator!=(const Shader &);

	private:
		void compileShaderFromString(const GLchar * _src, GLenum _type, GLuint &);
		void compileShaderFromFile(const GLchar * _path, GLenum _type, GLuint &);

	private:
		GLuint m_id;
	};

	template<typename _T>
	Shader & Shader::setVec2(const GLchar * _name, const Vec2<_T> & _v)
	{
		impl::UniformSetterForVec2<_T>{}(glGetUniformLocation(getId(), _name), _v);
		return *this;
	}
	template<typename _T>
	Shader & Shader::setVec3(const GLchar * _name, const Vec3<_T> & _v)
	{
		impl::UniformSetterForVec3<_T>{}(glGetUniformLocation(getId(), _name), _v);
		return *this;
	}
	template<typename _T>
	Shader & Shader::setVec4(const GLchar * _name, const Vec4<_T> & _v)
	{
		impl::UniformSetterForVec4<_T>{}(glGetUniformLocation(getId(), _name), _v);
		return *this;
	}

	template<typename _It>
	Shader & Shader::setLights(const GLchar * _name, _It _begin, const _It _end)
	{
		static_assert(std::is_same<typename std::iterator_traits<_It>::value_type, Light>::value,
			"_begin and _end must be iterators of containers of fhl::Light objects");

		std::size_t n = 0u;
		while (_begin != _end)
			setLight(_name, *(_begin++), n++);
		return setInt("lightsCount", n);
	}

}

#endif
