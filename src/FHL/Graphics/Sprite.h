#ifndef FHL_SPRITE_H
#define FHL_SPRITE_H


#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Texture.h>
#include <FHL/Graphics/Shader.h>
#include <FHL/Graphics/Color.h>
#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/Transformable.h>
#include <FHL/Graphics/TexturedSizeable.h>
#include <FHL/Graphics/UsingShader.h>
#include <FHL/Graphics/Litable.h>
#include <FHL/Utility/OrientedRect.h>

namespace fhl
{
	class OrientedRect;
	class Renderer;

	class FHL_API Sprite :
		public Transformable,
		public detail::TexturedSizeable,
		public UsingShader,
		public Litable
	{
		friend class Renderer;

	public:
		Sprite();
		explicit Sprite(Texture & _tex);

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

		constexpr static const char * s_simpleShaderName = "_FHL_spriteSimpleShader";
		constexpr static const char * s_lightShaderName = "_FHL_spriteLightShader";
	};

}

#endif