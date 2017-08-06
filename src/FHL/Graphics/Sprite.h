#ifndef FHL_SPRITE_H
#define FHL_SPRITE_H


#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Texture.h>
#include <FHL/Graphics/Shader.h>
#include <FHL/Graphics/Color.h>
#include <FHL/Graphics/Configurator.h>
#include <FHL/Graphics/Transformable.h>
#include <FHL/Graphics/TexturedSizeable.h>
#include <FHL/Graphics/Renderable.h>
#include <FHL/Graphics/UsingShader.h>
#include <FHL/Graphics/Litable.h>
#include <FHL/Utility/OrientedRect.h>

namespace fhl
{
	class OrientedRect;
	class ResMgr;

	class FHL_API Sprite :
		public Transformable,
		public internal::TexturedSizeable,
		public UsingShader,
		public Renderable,
		public Litable
	{
		friend class ResMgr;

	public:
		Sprite();
		explicit Sprite(Texture & _tex);

	public:
		void setColor(const Color & _color) { m_color = _color; }
		const Color & getColor() const { return m_color; }

		void render(const RenderConf & _conf) const override;
		Rect getAABB() const;
		OrientedRect getOBB() const;

	private:
		void setUp();

	private:
		Color m_color;

		constexpr static const char * simpleShaderName = "_FHL_spriteSimpleShader";
		constexpr static const char * lightShaderName = "_FHL_spriteLightShader";
	};

} // ns

#endif // FHL_SPRITE_H