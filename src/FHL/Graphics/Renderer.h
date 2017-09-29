#ifndef FHL_GRAPHICS_RENDERER_H
#define FHL_GRAPHICS_RENDERER_H

#include <FHL/Graphics/RenderConf.h>
#include <FHL/Graphics/Color.h>

namespace fhl
{

	class Renderable;
	class ColoredRect;
	class Sprite;
	class VertexArray;
	class Model;

	class Shader;

	class FHL_API Renderer
	{
		Renderer() = delete;

	public:
		static void render(const ColoredRect & _renderable, const RenderConf & _conf = RenderConf::default());
		static void render(const Sprite & _renderable, const RenderConf & _conf = RenderConf::default());
		static void render(const VertexArray & _renderable, const RenderConf & /* not used */);
		static void render(const Model & _renderable, const RenderConf & _conf = RenderConf::default());
		static void render(const Renderable & _renderable, const RenderConf & _conf = RenderConf::default());

		static void clearColor(const Color & _color = Color::Black());

	private:
		static bool isDefaultRenderConfInstance(const RenderConf & _rc);
	};

}

#endif
