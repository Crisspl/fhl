#include <FHL/Utility/OrientedRect.h>

#include <FHL/Graphics/Transformable.h>
#include <FHL/Maths/mathsFuncs.h>

namespace fhl
{

	OrientedRect::OrientedRect(const Vec2f & _size, const TransformData & _data) : Rect(_size), m_radAngle(0)
	{
		applyTransformData(_data);
	}

	OrientedRect::OrientedRect(const Vec2f & _botLeft, const Vec2f & _size, const Vec2f & _origin, float _rot) : OrientedRect(_size, { _botLeft, Vec2f::one(), _origin, _rot }) {}

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

	Rect & OrientedRect::adjustX(float _width)
	{
		m_size.x() += _width;
		const Vec2f offset = { _width * cos(m_radAngle), _width * std::sin(m_radAngle) };
		m_verts[BR] += offset;
		m_verts[UR] += offset;
		return *this;
	}

	Rect & OrientedRect::adjustY(float _height)
	{
		m_size.y() += _height;
		const float angle = m_radAngle + toRadians(90.f);
		const Vec2f offset = { _height * std::cos(angle), _height * std::sin(angle) };
		m_verts[UL] += offset;
		m_verts[UR] += offset;
		return *this;
	}

	Rect & OrientedRect::translate(const Vec2f & _offset)
	{
		const Vec2f x = { _offset.x() * std::cos(m_radAngle), _offset.x() * std::sin(m_radAngle) };
		const float angle = m_radAngle + toRadians(90.f);
		const Vec2f y = { _offset.y() * std::cos(angle), _offset.y() * std::sin(angle) };

		const Vec2f offset = x + y;

		return Rect::translate(offset);
	}

	void OrientedRect::applyTransformData(const TransformData & _data)
	{
		rotate(_data.origin, _data.rotation);
		Rect::translate(_data.botLeft);

		m_radAngle = toRadians(_data.rotation);

		calcAxes();
	}

	void OrientedRect::rotate(const Vec2f & _origin, float _angle)
	{
		const float angle = toRadians(_angle);
		const float s = std::sin(angle);
		const float c = std::cos(angle);

		translate(-_origin);

		for (Vec2f & vert : m_verts)
		{
			Vec2f nu;
			nu.x() = vert.x() * c - vert.y() * s;
			nu.y() = vert.x() * s + vert.y() * c;
			vert = nu;
		}

		translate(_origin);
	}

	void OrientedRect::calcAxes()
	{
		for (int i = 0; i < 2; i++)
		{
			const Vec2f edge = m_verts[i] - m_verts[i + 1];
			m_axes[i] = edge.perpendicular().normalized();
		}
	}

}