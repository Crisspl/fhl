#ifndef FHL_VEC2
#define FHL_VEC2

#include <FHL/Maths/VecBase.h>

namespace fhl
{

	template<typename _T>
	class Vec2 : public internal::VecBase<2, _T>
	{
	public:
		using valueType = _T;
		enum { Dimensions = 2 };

		constexpr explicit Vec2(_T _value = _T(0)) : internal::VecBase<2, _T>(_value) {}
		constexpr Vec2(_T _x, _T _y) : internal::VecBase<2, _T>(_x, _y) {}
		template<typename _U>
		Vec2(const Vec2<_U> & _other) : internal::VecBase<2, _T>(static_cast<const internal::VecBase<2, _U> &>(_other)) {}
		Vec2(const internal::VecBase<2, _T> & _other) : internal::VecBase<2, _T>(_other) {}

		template<typename _U>
		Vec2<_T> & operator=(const Vec2<_U> & _other) { internal::VecBase<2, _T>::operator=(_other); return *this; }

		static constexpr Vec2<_T> up(_T n = _T(1)) { return{ 0, n }; }
		static constexpr Vec2<_T> down(_T n = _T(1)) { return{ 0, -n }; }
		static constexpr Vec2<_T> right(_T n = _T(1)) { return{ n, 0 }; }
		static constexpr Vec2<_T> left(_T n = _T(1)) { return{ -n, 0 }; }
		static constexpr Vec2<_T> zero() { return Vec2<_T>(_T(0)); }
		static constexpr Vec2<_T> one() { return Vec2<_T>(_T(1)); }

		constexpr Vec2<_T> perpendicular() const { return {y(), -x()}; }

		_T & x() { return (*this)[0]; }
		constexpr _T x() const { return (*this)[0]; }

		_T & y() { return (*this)[1]; }
		constexpr _T y() const { return (*this)[1]; }

		_FHL_VECTOR_OPERATORS_IMPLEMENTATION(_T, Vec2)
	};

	using Vec2f = Vec2<float>;
	using Vec2lf = Vec2<double>;
	using Vec2i = Vec2<int>;
	using Vec2u = Vec2<unsigned>;

}

#endif
