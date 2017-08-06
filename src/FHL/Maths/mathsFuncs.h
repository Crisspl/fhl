#ifndef FHL_MATHS_FUNCS
#define FHL_MATHS_FUNCS

#include <algorithm>

#include <FHL/Maths/Constants.h>
#include <FHL/common.h>

namespace fhl
{
	FHL_API constexpr double toRadians(double _deg) { return _deg * Constants<double>::Pi() / 180.; }
	FHL_API constexpr double toDegrees(double _rad) { return _rad * 180. / Constants<double>::Pi(); }

	template<typename T>
	constexpr T abs(T n) { return n < T{} ? -n : n; }

	template <typename T>
	constexpr T clamp(T n, T lo, T hi)
	{
		return std::max(lo, std::min(n, hi));
	}
}

#endif
