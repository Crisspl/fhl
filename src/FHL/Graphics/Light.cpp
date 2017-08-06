#include <FHL/Graphics/Light.h>

namespace fhl
{

	Light::Light(Type _t)
		: direction(Vec3f::forward()),
		color(Color::White),
		cutOffAngle(30.f),
		illuminance(1.f),
		type(_t)
	{ }

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

	Light Light::infinite(Vec3f _dir, Color _color, float _illu)
	{
		Light light(Infinite);
		light.direction = _dir;
		light.color = _color;
		light.illuminance = _illu;

		return light;
	}

	Light Light::point(Vec3f _pos, Color _color, float _illu, float _linear, float _quadratic)
	{
		Light light(Point);
		light.position = _pos;
		light.linear = _linear;
		light.quadratic = _quadratic;
		light.color = _color;
		light.illuminance = _illu;

		return light;
	}

	Light Light::spot(Vec3f _pos, Vec3f _dir, Color _color, float _cutOff, float _illu, float _linear, float _quadratic)
	{
		Light light(Spot);
		light.position = _pos;
		light.direction = _dir;
		light.cutOffAngle = _cutOff;
		light.color = _color;
		light.illuminance = _illu;
		light.linear = _linear;
		light.quadratic = _quadratic;

		return light;
	}

} // ns
