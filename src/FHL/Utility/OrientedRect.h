#ifndef FHL_UTILITY_ORIENTED_RECT_H
#define FHL_UTILITY_ORIENTED_RECT_H

#include <FHL/Utility/Rect.h>
#include <FHL/Graphics/Transformable.h>

namespace fhl
{

	class FHL_API OrientedRect : public Rect
	{
	public:
		OrientedRect(const Vec2f & _size, const TransformData & _data);
		OrientedRect(const Vec2f & _botLeft, const Vec2f & _size, const Vec2f & _origin, float _rot);

		bool contains(const Vec2f & _p) const override;
		bool overlaps(const Rect & _rect) const override;

		Rect & adjustX(float _width) override;
		Rect & adjustY(float _height) override;

		const std::array<Vec2f, 2> & getAxes() const override { return m_axes; }

	private:
		void rotate(const Vec2f & _ori, float _angle);
		void applyTransformData(const TransformData & _data);
		void recalcAxes();

	private:
		std::array<Vec2f, 2> m_axes;
		float m_radAngle;
	};


}

#endif