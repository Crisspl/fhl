#ifndef FHL_BOOL_VEC_H
#define FHL_BOOL_VEC_H

#include <type_traits>
#include <utility>

namespace fhl
{

	template<std::size_t _N>
	class BoolVec
	{
		static_assert(_N > 1 && _N < 5, "fhl::BoolVec dimensions must fit between 2 and 4");

		using ubyte = unsigned char;
		using byte = char;

	public:
		enum { Dimensions = _N };

		BoolVec() : m_data(0u) {}

		template<typename ...Args>
		BoolVec(Args... _args) : BoolVec()
		{
			static_assert(sizeof...(Args) == _N, "Cannot initialize more than `Dimensions` bits");
			initBits(bool(_args)...);
		}

		constexpr operator bool() const { return all(); }

		constexpr bool operator[](std::size_t _idx) const
		{
			return static_cast<bool>( (m_data >> _idx) & 1 );
		}

		BoolVec & set(std::size_t _i, bool _val)
		{
			m_data ^= (-byte(_val) ^ m_data) & (1 << _i);
			return *this;
		}

		bool all() const
		{
			for (std::size_t i = 0u; i < _N; i++)
				if (!(*this)[i]) return false;
			return true;
		}

		bool none() const
		{
			for (std::size_t i = 0u; i < _N; i++)
				if ((*this)[i]) return false;
			return true;
		}

		bool any() const { return !none(); }

		constexpr BoolVec<_N> operator~() const
		{
			return negated(std::make_index_sequence<_N>{});
		}

	private:
		template<std::size_t ...Is>
		constexpr BoolVec<_N> negated(std::index_sequence<Is...>) const
		{
			return BoolVec<_N>(!(*this)[Is]...);
		}

		template<typename ...Rest>
		void initBits(bool _first, Rest... _rest)
		{
			static_assert(sizeof...(Rest) < _N, "fhl::BoolVec: Cannot initialize more then `Dimensions` bits");

			set(_N - sizeof...(Rest)-1, _first);
			initBits(bool(_rest)...);
		}
		void initBits(bool _val)
		{
			set(_N - 1, _val);
		}

		friend std::ostream & operator<<(std::ostream & _out, BoolVec<_N> _v)
		{
			_out << "{ ";
			for (std::size_t i = 0; i < _N; i++)
				_out << _v[i] << (i < _N - 1 ? ", " : " }");
			return _out;
		}

	private:
		ubyte m_data;
	};

}

#endif