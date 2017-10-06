#include <FHL/Utility/OrientedCube.h>

namespace fhl
{

	OrientedCube::OrientedCube(const Vec3f & _lbb, const Vec3f & _size, const Vec3f & _origin, const Quaternion & _rot) :
		Cube(_lbb, _size), m_sides{{ Plane<float>::yz(_lbb.x()), Plane<float>::yz(_lbb.x() + _size.x()), Plane<float>::xz(_lbb.y() + _size.y()), Plane<float>::xz(_lbb.y()), Plane<float>::xy(_lbb.z()), Plane<float>::xy(_lbb.z() + _size.z()) }}
	{
		rotate(_origin, _rot);
	}

	bool OrientedCube::contains(const Vec3f & _point) const
	{
		auto isBetweenPlanes =
		[this](const Vec3f & _pnt, Side _pl1, Side _pl2, float _cmp)
		{
			return m_sides[_pl1].distanceFromPoint(_pnt) < _cmp && m_sides[_pl2].distanceFromPoint(_pnt) < _cmp;
		};

		const Vec3f size = getSize();
		return isBetweenPlanes(_point, Side::Left, Side::Right, size.x()) && isBetweenPlanes(_point, Side::Bottom, Side::Top, size.y()) && isBetweenPlanes(_point, Side::Back, Side::Front, size.z());
	}

	Vec3f OrientedCube::getSize() const
	{
		return { (m_verts[RBF] - m_verts[LBF]).length(), (m_verts[RTF] - m_verts[RBF]).length(), (m_verts[LBF] - m_verts[LBB]).length() };
	}

	Cube & OrientedCube::adjustRight(float _offset)
	{
		return translateSide(RTF, RTB, RBB, RBF, calcOffsetVector(Vec3f::right(_offset), m_rotation));
	}

	Cube & OrientedCube::adjustLeft(float _offset)
	{
		return translateSide(LTF, LTB, LBB, LBF, calcOffsetVector(Vec3f::right(_offset), m_rotation));
	}

	Cube & OrientedCube::adjustTop(float _offset)
	{
		return translateSide(LTF, RTF, RTB, LTB, calcOffsetVector(Vec3f::up(_offset), m_rotation));
	}

	Cube & OrientedCube::adjustBottom(float _offset)
	{
		return translateSide(LBF, RBF, RBB, LBB, calcOffsetVector(Vec3f::up(_offset), m_rotation));
	}

	Cube & OrientedCube::adjustFront(float _offset)
	{
		return translateSide(LTF, LBF, RBF, RTF, calcOffsetVector(Vec3f::forward(_offset), m_rotation));
	}

	Cube & OrientedCube::adjustBack(float _offset)
	{
		return translateSide(LTB, LBB, RBB, RTB, calcOffsetVector(Vec3f::forward(_offset), m_rotation));
	}

	void OrientedCube::rotate(const Vec3f & _origin, const Quaternion & _rotation)
	{
		m_rotation = _rotation;

		const Mat4f mat = Mat4f::translate(_origin + getPosition()) * _rotation.toMat4f() * Mat4f::translate(-(_origin + getPosition()));
		for (Vec3f & v : m_verts)
			v = Mat4f::transform(mat, v);

		recalcSidePlanes();
	}

	void OrientedCube::recalcSidePlanes()
	{
		m_sides =
		{ {
			Plane<float>(m_verts[LTB], m_verts[LTF], m_verts[LBF]), // left
			Plane<float>(m_verts[RTB], m_verts[RTF], m_verts[RBF]), // right
			Plane<float>(m_verts[LTB], m_verts[RTB], m_verts[RTF]), // top
			Plane<float>(m_verts[LBB], m_verts[RBB], m_verts[RBF]), // bottom
			Plane<float>(m_verts[LTB], m_verts[LBB], m_verts[RBB]), // back
			Plane<float>(m_verts[LTF], m_verts[LBF], m_verts[RBF])  // front
		} };
	}

	Vec3f OrientedCube::calcOffsetVector(const Vec3f & _v, const Quaternion & _rot)
	{
		return Mat4f::transform(_rot.toMat4f(), _v);
	}

}