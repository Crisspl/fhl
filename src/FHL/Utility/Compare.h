#ifndef FHL_COMPARE_H
#define FHL_COMPARE_H

#include <limits>
#include <type_traits>
#include <cmath>

namespace fhl
{

	namespace impl
	{
		/* works like trinary operator */
		template<bool Condition, typename IfTrue, typename IfFalse>
		struct Conditional;

		template<typename IfTrue, typename IfFalse>
		struct Conditional<true, IfTrue, IfFalse> { using Type = IfTrue; };

		template<typename IfTrue, typename IfFalse>
		struct Conditional<false, IfTrue, IfFalse> { using Type = IfFalse; };
	}


	namespace detail
	{
		template<typename _T>
		struct FloatingPointCompare
		{
			static bool equal(const _T & _a, const _T & _b)
			{
				/*thanks goes to: http://floating-point-gui.de/errors/comparison/ */
				if (_a == _b) return true;

				const _T absDiff = std::abs(_a - _b);

				if (_a == _T(0) || _b == _T(0) || absDiff < std::numeric_limits<_T>::epsilon())
					return absDiff < std::numeric_limits<_T>::epsilon();

				return absDiff / (std::abs(_a) + std::abs(_b)) < std::numeric_limits<_T>::epsilon();
			}
		};

		template<typename T>
		struct IntegerCompare
		{
			constexpr static bool equal(const T & a, const T & b) { return a == b; }
		};
	}


#define _FHL_COMPARE_PARENT impl::Conditional<std::is_floating_point<_T>::value, detail::FloatingPointCompare<_T>, detail::IntegerCompare<_T>>::Type
	template<typename _T>
	struct Compare : _FHL_COMPARE_PARENT
	{
		static bool equal(const _T & a, const _T & b)
		{
			return _FHL_COMPARE_PARENT::equal(a, b);
		}
#undef _FHL_COMPARE_PARENT
		static bool notEqual(const _T & a, const _T & b)
		{
			return !equal(a, b);
		}

		constexpr static bool less(const _T & a, const _T & b)
		{
			return a < b;
		}

		constexpr static bool greater(const _T & a, const _T & b)
		{
			return a > b;
		}

		static bool lessEqual(const _T & a, const _T & b)
		{
			return less(a, b) || equal(a, b);
		}

		static bool greaterEqual(const _T & a, const _T & b)
		{
			return greater(a, b) || equal(a, b);
		}
	};


	template<typename T>
	struct EqualTo
	{
		bool operator()(const T & a, const T & b) { return Compare<T>::equal(a, b); }
	};

	template<typename T>
	struct NotEqualTo
	{
		bool operator()(const T & a, const T & b) { return Compare<T>::notEqual(a, b); }
	};

	template<typename T>
	struct Less
	{
		bool operator()(const T & a, const T & b) { return Compare<T>::less(a, b); }
	};

	template<typename T>
	struct Greater
	{
		bool operator()(const T & a, const T & b) { return Compare<T>::greater(a, b); }
	};

	template<typename T>
	struct LessEqual
	{
		bool operator()(const T & a, const T & b) { return Compare<T>::lessEqual(a, b); }
	};

	template<typename T>
	struct GreaterEqual
	{
		bool operator()(const T & a, const T & b) { return Compare<T>::greaterEqual(a, b); }
	};

}

#endif
