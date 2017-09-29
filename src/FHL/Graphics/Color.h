#ifndef FHL_GRAPHICS_COLOR_H
#define FHL_GRAPHICS_COLOR_H

#include <algorithm>

#include <FHL/Utility/Debug.h>
#include <FHL/Maths/vectors.h>
#include <FHL/Maths/mathsFuncs.h>

namespace fhl
{

	struct FHL_API Color
	{
		constexpr Color(float _r = 0.f, float _g = 0.f, float _b = 0.f, float _a = 1.f);
		constexpr Color(const Vec4f & _color);
		constexpr Color(const Vec3f & _color);
		Color(std::initializer_list<float> _rgba);

		bool operator==(const Color & _other) const
		{
			return asVec4() == _other.asVec4();
		}
		bool operator!=(const Color & _other) const
		{
			return !(*this == _other);
		}

		constexpr Vec4f asVec4() const { return{ r, g, b, a }; }

		constexpr float operator[](size_t _i) const { return *(&r + _i); }
		float & operator[](size_t _i) { return *(&r + _i); }

		float r, g, b, a;

		static constexpr Color White() { return Vec4f::one(); }
		static constexpr Color Black() { return Color(); }
		static constexpr Color Red() { return Color(1.f, 0.f, 0.f); }
		static constexpr Color Green() { return Color(0.f, 1.f, 0.f); }
		static constexpr Color Blue() { return Color(0.f, 0.f, 1.f); }
		static constexpr Color Yellow() { return Color(1.f, 1.f, 0.f); }
		static constexpr Color Magenta() { return Color(1.f, 0.f, 1.f); }
		static constexpr Color Cyan() { return Color(0.f, 1.f, 1.f); }
		static constexpr Color Transparent() { return Vec4f::zero(); }
	};

	constexpr Color::Color(float _r, float _g, float _b, float _a)
		: r(_r), g(_g), b(_b), a(_a)
	{
	}

	constexpr Color::Color(const Vec4f & _color)
		: Color(_color.x(), _color.y(), _color.z(), _color.w())
	{
	}

	constexpr Color::Color(const Vec3f & _color)
		: Color(Vec4f(_color, 1.f))
	{
	}

}

#endif
