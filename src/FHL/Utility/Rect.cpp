#include <FHL/Utility/Rect.h>

#include <FHL/Utility/Circle.h>
#include <FHL/Graphics/Transformable.h>

namespace fhl
{

	constexpr std::array<Vec2f, 2> Rect::s_axes;

	Rect::Rect(const Vec2f & _botLeft, const Vec2f & _size) :
		m_verts{ { _botLeft, _botLeft + Vec2f(_size.x(), 0), _botLeft + _size, _botLeft + Vec2f(0, _size.y()) } }
	{}

	Rect::Rect(const Vec2f & _size) : Rect(Vec2f::zero(), _size) {}

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
		return (_p.x() < m_verts[RB].x() && _p.x() > getPosition().x()) && (_p.y() < m_verts[RT].y() && _p.y() > getPosition().y());
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

	Rect & Rect::adjustRight(float _x)
	{
		return translateSide(RB, RT, Vec2f::right(_x));
	}

	Rect & Rect::adjustLeft(float _x)
	{
		return translateSide(LB, LT, Vec2f::right(_x));
	}

	Rect & Rect::adjustTop(float _y)
	{
		return translateSide(LT, RT, Vec2f::up(_y));
	}

	Rect & Rect::adjustBottom(float _y)
	{
		return translateSide(LB, RB, Vec2f::up(_y));
	}

	Rect & Rect::translate(const Vec2f & _offset)
	{
		for (Vec2f & vert : m_verts)
			vert += _offset;
		return *this;
	}

	Rect & Rect::translateSide(VertexPos _a, VertexPos _b, const Vec2f & _offset)
	{
		m_verts[_a] += _offset;
		m_verts[_b] += _offset;
		return *this;
	}

}