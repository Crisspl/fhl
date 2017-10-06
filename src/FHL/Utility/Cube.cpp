#include <FHL/Utility/Cube.h>

namespace fhl
{
	Cube::Cube(const Vec3f & _pos, const Vec3f & _size) :
		m_verts{ { _pos, _pos + Vec3f::right(_size.x()), _pos + Vec3f(_size.x(), _size.y(), 0), _pos + Vec3f::up(_size.y()),
				_pos + Vec3f::back(_size.z()), _pos + Vec3f(_size.x(), 0, _size.z()), _pos + _size, _pos + Vec3f(0, _size.y(), _size.z()) } }
	{}

	Cube::Cube(const Vec3f & _size) : Cube(Vec3f::zero(), _size) {}

	bool Cube::contains(const Vec3f & _p) const
	{
		return
			(_p.x() < m_verts[RBB].x() && _p.x() > getPosition().x()) &&
			(_p.y() < m_verts[RTB].y() && _p.y() > getPosition().y()) &&
			(_p.z() < m_verts[RBF].z() && _p.z() > getPosition().z());
	}

	bool Cube::overlaps(const Cube & _other) const
	{
		if (_other.getSize() > getSize())
			return _other.overlaps(*this);

		for (const Vec3f & vert : _other.getVerts())
			if (contains(vert)) return true;
		return false;
	}

	Cube & Cube::adjustRight(float _offset)
	{
		return translateSide(RBB, RTB, RBF, RTF, Vec3f::right(_offset));
	}

	Cube & Cube::adjustLeft(float _offset)
	{
		return translateSide(LBB, LTB, LBF, LTF, Vec3f::right(_offset));
	}

	Cube & Cube::adjustTop(float _offset)
	{
		return translateSide(LBB, RBB, LBF, RBF, Vec3f::up(_offset));
	}

	Cube & Cube::adjustBottom(float _offset)
	{
		return translateSide(LTB, RTB, LTF, RTF, Vec3f::up(_offset));
	}

	Cube & Cube::adjustFront(float _offset)
	{
		return translateSide(LBF, RBF, RTF, LTF, Vec3f::forward(_offset));
	}

	Cube & Cube::adjustBack(float _offset)
	{
		return translateSide(LBB, RBB, RTB, LTB, Vec3f::forward(_offset));
	}

	Cube & fhl::Cube::translate(const Vec3f & _offset)
	{
		for (Vec3f & vert : m_verts)
			vert += _offset;
		return *this;
	}

	Cube & Cube::translateSide(VertexPos _a, VertexPos _b, VertexPos _c, VertexPos _d, const Vec3f & _offset)
	{
		for (auto i : {_a, _b, _c, _d})
			m_verts[i] += _offset;
		return *this;
	}

}