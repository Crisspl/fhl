#include <FHL/Graphics/Light.h>

namespace fhl
{

	bool Light::operator==(const Light & _other) const
	{
		auto common = [this, &_other]() {
			return color == _other.color && illuminance == _other.illuminance;
		};

		if (type != _other.type)
			return false;

		switch (type)
		{
		case Infinite:
			return direction == _other.direction && common();
		case Point:
			return
				position == _other.position &&
				linear == _other.linear &&
				quadratic == _other.quadratic &&
				common();
		case Spot:
			return
				position == _other.position &&
				linear == _other.linear &&
				quadratic == _other.quadratic &&
				direction == _other.direction &&
				cutOffAngle == _other.cutOffAngle &&
				common();
		default: return false;
		}
	}

	bool Light::operator!=(const Light & _other) const
	{
		return !(*this == _other);
	}

}
