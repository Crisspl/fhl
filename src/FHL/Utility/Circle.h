#ifndef FHL_CIRCLE_H
#define FHL_CIRCLE_H

#include <FHL/Maths/Vec2.h>
#include <FHL/common.h>

namespace fhl
{

	class Rect;
	class Projection;

	class FHL_API Circle
	{
	public:
		constexpr Circle(Vec2f _center, float _radius) : m_center{_center}, m_radius{_radius} {}
		constexpr explicit Circle(float _radius) : Circle(Vec2f::zero(), _radius) {}

		constexpr const Vec2f & getCenter() const { return m_center; }
		constexpr float getRadius() const { return m_radius; }

		Circle & setCenter(const Vec2f & _center) { m_center = _center; return *this; }
		Circle & setRadius(float _rad) { m_radius = _rad; return *this; }

		Projection project(const Vec2f & _axis) const;

		bool contains(const Vec2f & _point) const;

		bool overlaps(const Circle & _other) const;
		bool overlaps(const Rect & _rect) const;

	private:
		Vec2f m_center;
		float m_radius;
	};

}

#endif