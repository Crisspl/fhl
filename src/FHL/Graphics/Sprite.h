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
	class ResMgr;
	class Renderer;

	class FHL_API Sprite :
		public Transformable,
		public internal::TexturedSizeable,
		public UsingShader,
		public Litable
	{
		friend class ResMgr;
		friend class Renderer;

	public:
		Sprite();
		explicit Sprite(Texture & _tex);

	public:
		void setColor(const Color & _color) { m_color = _color; }
		const Color & getColor() const { return m_color; }

		Rect getAABB() const;
		OrientedRect getOBB() const;

	private:
		void setUp();

	private:
		Color m_color;

		constexpr static const char * simpleShaderName = "_FHL_spriteSimpleShader";
		constexpr static const char * lightShaderName = "_FHL_spriteLightShader";
	};

}

#endif