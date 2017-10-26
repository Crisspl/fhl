#ifndef FHL_GRAPHICS_VERTEX_H
#define FHL_GRAPHICS_VERTEX_H

#include <FHL/Graphics/Color.h>

namespace fhl
{

	struct FHL_API Vertex
	{
		Vertex(const Vec2f & _pos = Vec2f::zero(), const Color & _col = Color::Transparent()) :
			position(_pos),
			color(_col)
		{}

		Vec2f position;
		Color color;
	};

}

#endif
