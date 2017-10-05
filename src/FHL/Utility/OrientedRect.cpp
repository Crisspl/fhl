#include <FHL/Utility/OrientedRect.h>

#include <vector>
#include <cmath>

#include <FHL/Graphics/Transformable.h>
#include <FHL/Maths/mathsFuncs.h>

namespace fhl
{

	OrientedRect::OrientedRect(const Transformable & _data, const Vec2f & _size) : Rect(_size), m_radAngle{0.f}
	{
		applyTransformData(_data);
	}

	OrientedRect::OrientedRect(const Vec2f & _botLeft, const Vec2f & _size, const Vec2f & _origin, float _rot) :
		OrientedRect( Transformable{}.setPosition(_botLeft + _origin).setOrigin(_origin).setRotation(_rot), _size)
	{}

	bool OrientedRect::contains(const Vec2f & _p) const
	{
		for (short i = 0; i < 2; i++)
		{
			const float dot = m_axes[i].dot(_p);
			Projection p1 = { dot, dot }, p2 = project(m_axes[i]);
			if (!p1.overlaps(p2) && !p2.overlaps(p1))
				return false;
		}
		return true;
	}

	bool OrientedRect::overlaps(const Rect & _rect) const
	{
		std::vector<Vec2f> axes(std::begin(_rect.getAxes()), std::end(_rect.getAxes()));
		axes.insert(axes.begin(), _rect.getAxes().begin(), _rect.getAxes().end());

		for (const Vec2f & axis : axes)
		{
			Projection p1 = this->project(axis), p2 = _rect.project(axis);
			if (!p1.overlaps(p2) && !p2.overlaps(p1))
				return false;
		}
		return true;
	}

	Rect & OrientedRect::adjustRight(float _x)
	{
		return translateSide(RB, RT, calcOffsetVector(_x, m_radAngle));
	}

	Rect & OrientedRect::adjustLeft(float _x)
	{
		return translateSide(LB, LT, calcOffsetVector(_x, m_radAngle));
	}

	Rect & OrientedRect::adjustTop(float _y)
	{
		return translateSide(LT, RT, calcOffsetVector(_y, m_radAngle + toRadians(90.f)));
	}

	Rect & OrientedRect::adjustBottom(float _y)
	{
		return translateSide(LB, RB, calcOffsetVector(_y, m_radAngle + toRadians(90.f)));
	}

	void OrientedRect::rotate(const Vec2f & _origin, float _angle)
	{
		m_radAngle += toRadians(_angle);
		m_radAngle = std::fmod(m_radAngle, 2 * Constants<float>::Pi());

		const Mat4f mat = Mat4f::translate(Vec3f{_origin + getPosition(), 0.f}) * Mat4f::rotate(_angle, Vec3f::back()) * Mat4f::translate(Vec3f{-(_origin + getPosition()), 0.f});
		for (Vec2f & v : m_verts)
			v = Mat4f::transform(mat, v);

		recalcAxes();
	}

	void OrientedRect::applyTransformData(const Transformable & _data)
	{
		translate(_data.getPosition() - _data.getOrigin());
		rotate(_data.getOrigin(), _data.getRotation());
	}

	void OrientedRect::recalcAxes()
	{
		for (int i = 0; i < 2; i++)
		{
			const Vec2f edge = m_verts[i] - m_verts[i + 1];
			m_axes[i] = edge.perpendicular().normalized();
		}
	}

	Vec2f OrientedRect::calcOffsetVector(float _distance, float _angle)
	{
		return Vec2f{ _distance * std::cos(_angle), _distance * std::sin(_angle) };
	}

}