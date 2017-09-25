#ifndef FHL_SHADER_H
#define FHL_SHADER_H

#include <type_traits>
#include <vector>
#include <iterator>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Color.h>
#include <FHL/Graphics/Light.h>
#include <FHL/Graphics/impl/UniformLocMgr.h>
#include <FHL/Maths/Mat4.h>

namespace fhl
{

#define _FHL_DEFINE_UNFIORM_SETTER_FOR_VECTOR_SIZE(_size) \
template<typename T> \
struct UniformSetterForVec##_size; \
template<> \
struct UniformSetterForVec##_size<float> \
{ \
	static void set(GLint _loc, const Vec##_size<float> & _v) { glUniform##_size##fv(_loc, 1u, _v.data()); } \
}; \
template<> \
struct UniformSetterForVec##_size<int> \
{ \
	static void set(GLint _loc, const Vec##_size<int> & _v) { glUniform##_size##iv(_loc, 1u, _v.data()); } \
}; \
template<> \
struct UniformSetterForVec##_size<unsigned> \
{ \
	static void set(GLint _loc, const Vec##_size<unsigned> & _v) { glUniform##_size##uiv(_loc, 1u, _v.data()); } \
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

		Shader & setBoolean(const GLint _loc, const GLboolean _value);
		Shader & setBoolean(const GLchar * _name, const GLboolean _value);
		Shader & setFloat(const GLint _loc, const GLfloat _value);
		Shader & setFloat(const GLchar * _name, const GLfloat _value);
		Shader & setInt(const GLint _loc, const GLint _value);
		Shader & setInt(const GLchar * _name, const GLint _value);
		Shader & setUnsignedInt(const GLint _loc, const GLuint _value);
		Shader & setUnsignedInt(const GLchar * _name, const GLuint _value);
		Shader & setColor(const GLint _loc, const Color & _value);
		Shader & setColor(const GLchar * _name, const Color & _value);
		Shader & setMat4f(const GLint _loc, const Mat4f & _matrix);
		Shader & setMat4f(const GLchar * _name, const Mat4f & _matrix);

		template<typename _T>
		Shader & setVec2(const GLint _loc, const Vec2<_T> & _v);
		template<typename _T>
		Shader & setVec2(const GLchar * _name, const Vec2<_T> & _v);
		template<typename _T>
		Shader & setVec3(const GLint _loc, const Vec3<_T> & _v);
		template<typename _T>
		Shader & setVec3(const GLchar * _name, const Vec3<_T> & _v);
		template<typename _T>
		Shader & setVec4(const GLint _loc, const Vec4<_T> & _v);
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
		void compileShaderFromString(const GLchar * _src, GLenum _type, GLuint &) const;
		void compileShaderFromFile(const GLchar * _path, GLenum _type, GLuint &) const;

		GLint getUniformLoc(const GLchar * _name);

	private:
		GLuint m_id;
		impl::UniformLocMgr m_uniformLocMgr;
	};

	template<typename _T>
	inline Shader & Shader::setVec2(const GLint _loc, const Vec2<_T>& _v)
	{
		impl::UniformSetterForVec2<_T>::set(_loc, _v);
		return *this;
	}

	template<typename _T>
	inline Shader & Shader::setVec2(const GLchar * _name, const Vec2<_T> & _v)
	{
		return setVec2<_T>(getUniformLoc(_name), _v);
	}
	template<typename _T>
	inline Shader & Shader::setVec3(const GLint _loc, const Vec3<_T>& _v)
	{
		impl::UniformSetterForVec3<_T>::set(_loc, _v);
		return *this;
	}
	template<typename _T>
	inline Shader & Shader::setVec3(const GLchar * _name, const Vec3<_T> & _v)
	{
		return setVec3<_T>(getUniformLoc(_name), _v);
	}
	template<typename _T>
	inline Shader & Shader::setVec4(const GLint _loc, const Vec4<_T>& _v)
	{
		impl::UniformSetterForVec4<_T>::set(_loc, _v);
		return *this;
	}
	template<typename _T>
	inline Shader & Shader::setVec4(const GLchar * _name, const Vec4<_T> & _v)
	{
		return setVec4<_T>(getUniformLoc(_name), _v);
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
