#include <FHL/Utility/Cube.h>

namespace fhl
{
	Cube::Cube(const Vec3f & _pos, const Vec3f & _size) :
		m_size{_size},
		m_verts{ { _pos, _pos + Vec3f::right() * _size.x(), _pos + Vec3f(_size.x(), _size.y(), 0), _pos + Vec3f::up() * _size.y(),
				_pos + Vec3f::forward() * _size.z(), _pos + Vec3f(_size.x(), 0, _size.z()), _pos + _size, _pos + Vec3f(0, _size.y(), _size.z()) } }
	{}

	Cube::Cube(const Vec3f & _size) : Cube(Vec3f::zero(), _size) {}

	bool Cube::contains(const Vec3f & _p) const
	{
		return
			(_p.x() < m_verts[BRR].x() && _p.x() > getPosition().x()) &&
			(_p.y() < m_verts[URR].y() && _p.y() > getPosition().y()) &&
			(_p.z() < m_verts[BRF].z() && _p.z() > getPosition().z());
	}

	bool Cube::overlaps(const Cube & _other) const
	{
		for (const Vec3f & vert : _other.getVerts())
			if (contains(vert)) return true;
		return false;
	}

	Cube & Cube::adjustX(float _offset)
	{
		m_verts[BRR].x() += _offset;
		m_verts[URR].x() += _offset;
		m_verts[BRF].x() += _offset;
		m_verts[URF].x() += _offset;
		return *this;
	}

	Cube & Cube::adjustY(float _offset)
	{
		m_verts[BLR].y() += _offset;
		m_verts[BRR].y() += _offset;
		m_verts[BLF].y() += _offset;
		m_verts[BRF].y() += _offset;
		return *this;
	}

	Cube & Cube::adjustZ(float _offset)
	{
		m_verts[BLF].z() += _offset;
		m_verts[BRF].z() += _offset;
		m_verts[URF].z() += _offset;
		m_verts[ULF].z() += _offset;
		return *this;
	}

	Cube & fhl::Cube::translate(const Vec3f & _offset)
	{
		for (Vec3f & vert : m_verts)
			vert += _offset;
		return *this;
	}

}