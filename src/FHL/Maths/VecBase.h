#ifndef FHL_VEC_BASE_H
#define FHL_VEC_BASE_H

#include <type_traits>
#include <algorithm>
#include <cmath>
#include <ostream>
#include <iterator>

#include <FHL/Maths/BoolVec.h>
#include <FHL/Utility/Compare.h>

namespace fhl { namespace internal
{

	namespace impl
	{
		template<typename _T>
		constexpr _T repeatValue(_T _value, std::size_t) { return _value; }
	}

	template<std::size_t _N, typename _T>
	class VecBase
	{
		static_assert(std::is_pod<_T>::value, "fhl::internal::VecBase value type must be POD");
		static_assert(_N > 1 && _N < 5, "fhl::internal::VecBase dimensions must fit between 2 and 4");

	public:
		using valueType = _T;
		enum { Dimensions = _N };

		template<typename ...Args>
		constexpr VecBase(_T _first, Args... _args) : m_data{ _first, _T(_args)... }
		{
			static_assert(sizeof...(Args) == _N - 1, "Arguments count must be equal to `Dimensions`");
		}
		constexpr VecBase(_T _value) : VecBase(std::make_index_sequence<_N>{}, _T(_value)) {}
	private:
		template<std::size_t... Is> /* helper ctor for one value constexpr init */
		constexpr VecBase(std::index_sequence<Is...>, _T _value) : m_data{ impl::repeatValue(_value, Is)... } {}

	public:
		template<typename _U>
		VecBase(const VecBase<_N, _U> & _other) { *this = _other; }

		constexpr VecBase() : VecBase(0) {}

		template<typename _U>
		VecBase<_N, _T> & operator=(const VecBase<_N, _U> & _other)
		{
			for (std::size_t i = 0; i < _N; i++)
				m_data[i] = _T(_other[i]);
			return *this;
		}

		BoolVec<_N> operator==(const VecBase<_N, _T> & _other) const
		{
			return getComparisonVector<EqualTo<_T>>(_other, std::make_index_sequence<_N>{});
		}
		BoolVec<_N> operator!=(const VecBase<_N, _T> & _other) const
		{
			return ~(*this == _other);
		}

		BoolVec<_N> operator<(const VecBase<_N, _T> & _other) const
		{
			return getComparisonVector<Less<_T>>(_other, std::make_index_sequence<_N>{});
		}
		BoolVec<_N> operator<=(const VecBase<_N, _T> & _other) const
		{
			return getComparisonVector<LessEqual<_T>>(_other, std::make_index_sequence<_N>{});
		}

		BoolVec<_N> operator>(const VecBase<_N, _T> & _other) const
		{
			return getComparisonVector<Greater<_T>>(_other, std::make_index_sequence<_N>{});
		}
		BoolVec<_N> operator>=(const VecBase<_N, _T> & _other) const
		{
			return getComparisonVector<GreaterEqual<_T>>(_other, std::make_index_sequence<_N>{});
		}

		VecBase<_N, _T> operator+(const VecBase<_N, _T> & _other) const { return VecBase<_N, _T>(*this) += _other; }

		VecBase<_N, _T> operator-(const VecBase<_N, _T> & _other) const { return VecBase<_N, _T>(*this) -= _other; }

		VecBase<_N, _T> operator*(const VecBase<_N, _T> & _other) const { return VecBase<_N, _T>(*this) *= _other; }
		VecBase<_N, _T> operator*(_T _scalar) const { return VecBase<_N, _T>(*this) *= _scalar; }
		friend VecBase<_N, _T> operator*(_T _scalar, const VecBase<_N, _T> & _vec) { return _vec * _scalar; }

		VecBase<_N, _T> operator/(const VecBase<_N, _T> & _other) const { return VecBase<_N, _T>(*this) /= _other; }
		VecBase<_N, _T> operator/(_T _scalar) const { return VecBase<_N, _T>(*this) /= _scalar; }

		VecBase<_N, _T> operator-() const
		{
			VecBase<_N, _T> ret;
			for (std::size_t i = 0u; i < _N; i++)
				ret.m_data[i] = -m_data[i];
			return ret;
		}

		VecBase<_N, _T> & operator+=(const VecBase<_N, _T> & _other)
		{
			for (std::size_t i = 0u; i < _N; i++)
				m_data[i] += _other[i];
			return *this;
		}
		VecBase<_N, _T> & operator-=(const VecBase<_N, _T> & _other)
		{
			for (std::size_t i = 0u; i < _N; i++)
				m_data[i] -= _other[i];
			return *this;
		}
		VecBase<_N, _T> & operator*=(const VecBase<_N, _T> & _other)
		{
			for (std::size_t i = 0u; i < _N; i++)
				m_data[i] *= _other[i];
			return *this;
		}
		VecBase<_N, _T> & operator*=(_T _scalar)
		{
			for (std::size_t i = 0u; i < _N; i++)
				m_data[i] *= _scalar;
			return *this;
		}
		VecBase<_N, _T> & operator/=(const VecBase<_N, _T> & _other)
		{
			for (std::size_t i = 0u; i < _N; i++)
				m_data[i] /= _other[i];
			return *this;
		}
		VecBase<_N, _T> & operator/=(_T _scalar)
		{
			for (std::size_t i = 0u; i < _N; i++)
				m_data[i] /= _scalar;
			return *this;
		}

		_T dot(const VecBase<_N, _T> & _other) const
		{
			_T dot = 0;
			for (std::size_t i = 0; i < _N; i++)
				dot += m_data[i] * _other[i];
			return dot;
		}
		_T length() const { return std::sqrt(squaredLength()); }
		_T squaredLength() const { return dot(*this); }
		VecBase<_N, _T> normalized() const { return *this / length(); }

		_T & operator[](std::size_t _idx) { return m_data[_idx]; }
		constexpr _T operator[](std::size_t _idx) const { return m_data[_idx]; }

		constexpr const _T * data() const { return m_data; }

	private:
		template<typename Op>
		/*constexpr */bool idxCompare(const VecBase<_N, _T> & _other, std::size_t _idx) const { return Op{}(m_data[_idx], _other[_idx]); }

		template<typename Op, std::size_t... Is>
		/*constexpr */BoolVec<_N> getComparisonVector(const VecBase<_N, _T> & _other, std::index_sequence<Is...>) const
		{
			return BoolVec<_N>(idxCompare<Op>(_other, Is)...);
		}

	public:
		friend std::ostream & operator<<(std::ostream & _out, const VecBase<_N, _T> & _v)
		{
			_out << "{ ";
			std::copy(std::begin(_v.m_data), std::end(_v.m_data), std::ostream_iterator<_T>(_out, ", "));
			return _out << '}';
		}

	private:
		_T m_data[_N];
	};

}}

/* put inside class definition in public scope */
/* implements also normalized() method */
#define _FHL_VECTOR_OPERATORS_IMPLEMENTATION(ValueType, VecType) \
VecType<ValueType> operator+(const VecType<ValueType> & _other) const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator+(_other); } \
\
VecType<ValueType> operator-(const VecType<ValueType> & _other) const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator-(_other); } \
\
VecType<ValueType> operator*(const VecType<ValueType> & _other) const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator*(_other); } \
VecType<ValueType> operator*(_T _scalar) const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator*(_scalar); } \
\
VecType<ValueType> operator/(const VecType<ValueType> & _other) const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator/(_other); } \
VecType<ValueType> operator/(_T _scalar) const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator/(_scalar); } \
\
VecType<ValueType> operator-() const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator-(); } \
\
VecType<ValueType> & operator+=(const VecType<ValueType> & _other) \
{ \
	fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator+=(_other); \
	return *this; \
} \
VecType<ValueType> & operator-=(const VecType<ValueType> & _other) \
{ \
	fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator-=(_other); \
	return *this; \
} \
VecType<ValueType> & operator*=(const VecType<ValueType> & _other) \
{ \
	fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator*=(_other); \
	return *this; \
} \
VecType<ValueType> & operator*=(_T _scalar) \
{ \
	fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator*=(_scalar); \
	return *this; \
} \
VecType<ValueType> & operator/=(const VecType<ValueType> & _other) \
{ \
	fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator/=(_other); \
	return *this; \
} \
VecType<ValueType> & operator/=(_T _scalar) \
{ \
	fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::operator/=(_scalar); \
	return *this; \
} \
VecType<ValueType> normalized() const { return fhl::internal::VecBase<VecType<ValueType>::Dimensions, ValueType>::normalized(); }

#endif
