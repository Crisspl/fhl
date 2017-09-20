#ifndef FHL_COLOREDRECT_H
#define FHL_COLOREDRECT_H

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Vao.h>
#include <FHL/Graphics/Transformable.h>
#include <FHL/Graphics/Sizeable.h>
#include <FHL/Graphics/Vertex.h>
#include <FHL/Graphics/Litable.h>
#include <FHL/Graphics/UsingShader.h>
#include <FHL/Utility/OrientedRect.h>

namespace fhl
{
	class Renderer;

	class FHL_API ColoredRect :
		public Transformable,
		public detail::Sizeable,
		public UsingShader,
		public Litable
	{
		friend class Renderer;

	public:
		explicit ColoredRect(Vec2f _size, Color _color = Color::Transparent());

	public:
		void setColor(const Color & _color) { m_color = _color; }
		const Color & getColor() const { return m_color; }

		Rect getAABB() const;
		OrientedRect getOBB() const;

		static constexpr const char * simpleShaderName() { return s_simpleShaderName; }
		static constexpr const char * lightShaderName() { return s_lightShaderName; }

	private:
		void setUp();

	private:
		Color m_color;

		constexpr static const char * s_simpleShaderName = "_FHL_rectSimpleShader";
		constexpr static const char * s_lightShaderName = "_FHL_rectLightShader";
	};

}

#endif