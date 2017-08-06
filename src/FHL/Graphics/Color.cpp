#include <FHL/Graphics/Color.h>

namespace fhl
{

	const Color Color::White = Color(Vec4f::one());
	const Color Color::Black;
	const Color Color::Red = Color(1.f, 0.f, 0.f);
	const Color Color::Green = Color(0.f, 1.f, 0.f);
	const Color Color::Blue = Color(0.f, 0.f, 1.f);
	const Color Color::Yellow = Color(1.f, 1.f, 0.f);
	const Color Color::Magenta = Color(1.f, 0.f, 1.f);
	const Color Color::Cyan = Color(0.f, 1.f, 1.f);
	const Color Color::Transparent = Color(Vec4f::zero());

	Color::Color(std::initializer_list<float> _rgba)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i <= _rgba.size() - 1)
				(*this)[i] = clamp(*(_rgba.begin() + i), 0.f, 1.f);
			else
				(*this)[i] = 1.f;
		}
	}

} // ns
