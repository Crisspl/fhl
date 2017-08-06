#ifndef FHL_VEC3_H
#define FHL_VEC3_H

#include <FHL/Maths/Vec2.h>

namespace fhl
{

	template<typename _T>
	class Vec3 : public internal::VecBase<3, _T>
	{
	public:
		using valueType = _T;
		enum { Dimensions = 3 };

		constexpr explicit Vec3(_T _value = _T(0)) : internal::VecBase<3, _T>(_value) {}
		constexpr Vec3(_T _x, _T _y, _T _z) : internal::VecBase<3, _T>(_x, _y, _z) {}
		template<typename _U>
		Vec3(const Vec3<_U> & _other) : internal::VecBase<3, _T>(static_cast<const internal::VecBase<3, _U> &>(_other)) {}
		Vec3(const internal::VecBase<3, _T> & _other) : internal::VecBase<3, _T>(_other) {}
		constexpr Vec3(const Vec2<_T> & _v, _T _n) : internal::VecBase<3, _T>(_v.x(), _v.y(), _n) {}
		constexpr Vec3(_T _n, const Vec2<_T> & _v) : internal::VecBase<3, _T>(_n, _v.x(), _v.y()) {}

		template<typename _U>
		Vec3<_T> & operator=(const Vec3<_U> & _other) { internal::VecBase<3, _T>::operator=(_other); return *this; }

		static constexpr Vec3<_T> up(_T n = _T(1)) { return{ 0, n, 0 }; }
		static constexpr Vec3<_T> down(_T n = _T(1)) { return{ 0, -n, 0 }; }
		static constexpr Vec3<_T> right(_T n = _T(1)) { return{ n, 0, 0 }; }
		static constexpr Vec3<_T> left(_T n = _T(1)) { return{ -n, 0, 0 }; }
		static constexpr Vec3<_T> forward(_T n = _T(1)) { return{ 0, 0, -n }; }
		static constexpr Vec3<_T> back(_T n = _T(1)) { return{ 0, 0, n }; }
		static constexpr Vec3<_T> zero() { return Vec3<_T>(_T(0)); }
		static constexpr Vec3<_T> one() { return Vec3<_T>(_T(1)); }

		constexpr Vec3<_T> cross(const Vec3<_T> & _rhs) const
		{
			return
				Vec3<_T>(
					y() * _rhs.z() - z() * _rhs.y(),
					z() * _rhs.x() - x() * _rhs.z(),
					x() * _rhs.y() - y() * _rhs.x()
				);
		}

		_T & x() { return (*this)[0]; }
		constexpr _T x() const { return (*this)[0]; }

		_T & y() { return (*this)[1]; }
		constexpr _T y() const { return (*this)[1]; }

		_T & z() { return (*this)[2]; }
		constexpr _T z() const { return (*this)[2]; }

		_FHL_VECTOR_OPERATORS_IMPLEMENTATION(_T, Vec3)
	};

	using Vec3f = Vec3<float>;
	using Vec3lf = Vec3<double>;
	using Vec3i = Vec3<int>;
	using Vec3u = Vec3<unsigned>;

}

#endif
