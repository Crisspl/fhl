#include <FHL/Graphics/Color.h>

namespace fhl
{

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

}
