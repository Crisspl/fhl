#ifndef FHL_GRAPHICS_RENDERMATRICES_H
#define FHL_GRAPHICS_RENDERMATRICES_H

#include <FHL/Maths/Mat4.h>

namespace fhl
{

	 struct FHL_API RenderMatrices
	 {
		  bool operator==(const RenderMatrices & _other) const
		  {
				return transform == _other.transform && mvp == _other.mvp && cameraPosition == _other.cameraPosition;
		  }

		  bool operator!=(const RenderMatrices & _other) const
		  {
				return !(*this == _other);
		  }

		  Mat4f transform, inverseTransform, mvp;
		  Vec3f cameraPosition;
	 };

}

#endif