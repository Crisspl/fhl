#ifndef FHL_LIGHT_H
#define FHL_LIGHT_H

#include <FHL/Graphics/Color.h>

namespace fhl
{

	 struct FHL_API Light
	 {
		  enum Type
		  {
				Infinite = 0,
				Point,
				Spot
		  };

		  Light(Type _t = Infinite);

		  bool operator==(const Light & _other) const;
		  bool operator!=(const Light & _other) const;

		  static Light infinite(Vec3f _dir, Color _color = Color::White, float _illu = 1.f);
		  static Light point(Vec3f _pos, Color _color = Color::White, float _illu = 1.f, float _linear = 0.045f, float _quadratic = 0.0075f);
		  static Light spot(Vec3f _pos, Vec3f _dir = Vec3f::forward(), Color _color = Color::White, float _cutOff = 30.f, float _illu = 1.f, float _linear = 0.045f, float _quadratic = 0.0075f);

		  Vec3f position, direction;
		  Color color;
		  float linear, quadratic;
		  float cutOffAngle;
		  float illuminance;
		  Type type;
	 };

} // ns

#endif // FHL_LIGHT_H
