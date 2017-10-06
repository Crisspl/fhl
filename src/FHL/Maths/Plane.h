#ifndef FHL_MATHS_PLANE_H
#define FHL_MATHS_PLANE_H

#include <cmath>

#include <FHL/Maths/vectors.h>
#include <FHL/Maths/swizzle.h>
#include <FHL/Utility/Compare.h>

namespace fhl
{

	template<typename _T>
	class Plane
	{
	public:
		constexpr Plane(const Vec3<_T> & _normal, _T _d) : m_abcd{ Vec4<_T>{_normal, _d} / _normal.length() } {}

		/* from a point and normal vector */
		Plane(const Vec3<_T> & _point, const Vec3<_T> & _normal) : Plane(_normal, -_normal.dot(_point)) {}

		/* from three points */
		Plane(const Vec3<_T> & _p0, const Vec3<_T> & _p1, const Vec3<_T> & _p2)
		{
			const Vec3<_T> v0 = _p1 - _p0;
			const Vec3<_T> v1 = _p2 - _p1;
			const Vec3<_T> normal = v0.cross(v1);

			m_abcd = Vec4<_T>{ normal, -normal.dot(_p0) } / normal.length();
		}

		constexpr Vec3<_T> getNormal() const
		{
			using namespace swizzle;
			return get<X, Y, Z>(m_abcd);
		}

		constexpr _T getD() const { return m_abcd.w(); }

		bool isLyingOn(const Vec3<_T> & _p) const
		{
			return Compare<_T>::equal(getNormal().dot(_p) + m_abcd.w(), _T(0));
		}

		/* no need to divide by normal vector length since it's always normalized (see ctors) */
		_T signedDistanceFromPoint(const Vec3<_T> & _point) const { return getNormal().dot(_point) + getD(); }
		_T distanceFromPoint(const Vec3<_T> & _point) const { return std::abs(signedDistanceFromPoint(_point)); }

	private:
		Vec4<_T> m_abcd;
	};

}

#endif