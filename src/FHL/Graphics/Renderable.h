#ifndef FHL_RENDERABLE_H
#define FHL_RENDERABLE_H

#include <FHL/Graphics/RenderConf.h>

namespace fhl
{
	class Renderer;

	class FHL_API Renderable
	{
		friend class Renderer;

	public:
		virtual ~Renderable() = default;

	protected:
		virtual void render(const RenderConf &) const = 0;
	};

} // ns

#endif // FHL_RENDERABLE_H
