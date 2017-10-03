#ifndef FHL_UTILITY_ORIENTED_RECT_H
#define FHL_UTILITY_ORIENTED_RECT_H

#include <FHL/Utility/Rect.h>

namespace fhl
{

	class Transformable;

	class FHL_API OrientedRect : public Rect
	{
	public:
		/* Gets position, origin and rotation angle from Transformable object */
		OrientedRect(const Transformable & _data, const Vec2f & _size);
		OrientedRect(const Vec2f & _botLeft, const Vec2f & _size, const Vec2f & _origin, float _rot);

		bool contains(const Vec2f & _p) const override;
		bool overlaps(const Rect & _rect) const override;

		Rect & adjustRight(float _x) override;
		Rect & adjustLeft(float _x) override;
		Rect & adjustTop(float _y) override;
		Rect & adjustBottom(float _y) override;

		const std::array<Vec2f, 2> & getAxes() const override { return m_axes; }

	private:
		void rotate(const Vec2f & _ori, float _angle);
		void applyTransformData(const Transformable & _data);
		void recalcAxes();
		static Vec2f calcOffsetVector(float _distance, float _angle);

	private:
		std::array<Vec2f, 2> m_axes;
		float m_radAngle;
	};


}

#endif