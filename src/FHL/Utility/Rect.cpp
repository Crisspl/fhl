#include <FHL/Utility/Rect.h>

#include <FHL/Utility/Circle.h>
#include <FHL/Graphics/Transformable.h>

namespace fhl
{
	constexpr std::array<Vec2f, 2> Rect::s_axes;

	bool Rect::operator==(const Rect & _other) const
	{
		for (int i = 0; i < 4; ++i)
			if ((*this)[i] != _other[i]) return false;
		return true;
	}

	bool Rect::operator!=(const Rect & _other) const
	{
		return !(*this == _other);
	}

	bool Rect::contains(const Vec2f & _p) const
	{
		return (_p.x() < m_verts[BR].x() && _p.x() > getPosition().x()) && (_p.y() < m_verts[UR].y() && _p.y() > getPosition().y());
	}

	bool Rect::overlaps(const Rect & _rect) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->contains(_rect[i]))
				return true;
		}
		return false;
	}

	bool Rect::overlaps(const Circle & _circle) const
	{
		return _circle.overlaps(*this);
	}

	Projection Rect::project(const Vec2f & _axis) const
	{
		float min = m_verts[0].dot(_axis);
		float max = min;

		for (short i = 1; i < 4; i++)
		{
			float p = m_verts[i].dot(_axis);
			if (p < min)
				min = p;
			else if (p > max)
				max = p;
		}

		return{ min, max };
	}

	Rect & Rect::adjustX(float _width)
	{
		m_verts[BR].x() += _width;
		m_verts[UR].x() += _width;
		return *this;
	}

	Rect & Rect::adjustY(float _height)
	{
		m_verts[UL].y() += _height;
		m_verts[UR].y() += _height;
		return *this;
	}

	Rect & Rect::translate(const Vec2f & _offset)
	{
		for (Vec2f & vert : m_verts)
			vert += _offset;
		return *this;
	}

}