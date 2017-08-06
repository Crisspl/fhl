#ifndef FHL_VERTEX_H
#define FHL_VERTEX_H

#include <FHL/Graphics/Color.h>

namespace fhl
{

	struct FHL_API Vertex
	{
		Vertex(Vec2f _pos, Color _col = Color::Transparent) :
			position(_pos),
			color(_col)
		{}

		Vec2f position;
		Color color;
	};

} // ns

#endif // FHL_VERTEX_H
