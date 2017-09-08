#ifndef FHL_RENDERER_H
#define FHL_RENDERER_H

#include <FHL/Graphics/Renderable.h>
#include <FHL/Graphics/RenderConf.h>
#include <FHL/Graphics/Color.h>

namespace fhl
{
	class FHL_API Renderer
	{
		Renderer() = delete;

	public:
		static void render(const Renderable & _drawable, const RenderConf & _conf = RenderConf::default());
		static void clearColor(Color _color = Color::Black());
	};

} // ns

#endif // FHL_RENDERER_H
