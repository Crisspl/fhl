#ifndef FHL_VIEW_H
#define FHL_VIEW_H

#include <FHL/Maths/Mat4.h>

namespace fhl
{

	struct FHL_API View
	{
		Mat4f matrix;
		Vec3f cameraPos;
	};

}

#endif // FHL_VIEW_H
