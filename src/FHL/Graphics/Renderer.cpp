#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Renderer.h>


namespace fhl
{

	void Renderer::render(const Renderable & _drawable, const RenderConf & _conf)
	{
		_drawable.render(_conf);
	}

	void Renderer::clearColor(Color _color)
	{
		glClearColor(_color.r, _color.g, _color.b, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}
