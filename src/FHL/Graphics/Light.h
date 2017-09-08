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

		  bool operator==(const Light & _other) const;
		  bool operator!=(const Light & _other) const;

		  static constexpr Light infinite(const Vec3f & _dir, const Color & _color = Color::White(), float _illu = 1.f);
		  static constexpr Light point(const Vec3f & _pos, const Color & _color = Color::White(), float _illu = 1.f, float _linear = 0.045f, float _quadratic = 0.0075f);
		  static constexpr Light spot(const Vec3f & _pos, const Vec3f & _dir = Vec3f::forward(), const Color & _color = Color::White(), float _cutOff = 30.f, float _illu = 1.f, float _linear = 0.045f, float _quadratic = 0.0075f);

		  Vec3f position, direction;
		  Color color;
		  float linear, quadratic;
		  float cutOffAngle;
		  float illuminance;
		  Type type;
	 };

	 constexpr Light Light::infinite(const Vec3f & _dir, const Color & _color, float _illu)
	 {
		 return
		 {
			 Vec3f{},	// position
			 _dir,		// direction
			 _color,	// color
			 float{},	// linear
			 float{},	// quadratic
			 float{},	// cutOffAngle
			 _illu,		// illuminance
			 Infinite	// type
		 };
	 }

	 constexpr Light Light::point(const Vec3f & _pos, const Color & _color, float _illu, float _linear, float _quadratic)
	 {
		 return
		 {
			 _pos,		// position
			 Vec3f{},	// direction
			 _color,	// color
			 _linear,	// linear
			 _quadratic,// quadratic
			 float{},	// cutOffAngle
			 _illu,		// illuminance
			 Point		// type
		 };
	 }

	 constexpr Light Light::spot(const Vec3f & _pos, const Vec3f & _dir, const Color & _color, float _cutOff, float _illu, float _linear, float _quadratic)
	 {
		 return
		 {
			 _pos,		// position
			 _dir,		// direction
			 _color,	// color
			 _linear,	// linear
			 _quadratic,// quadratic
			 _cutOff,	// cutOffAngle
			 _illu,		// illuminance
			 Spot		// type
		 };
	 }

}

#endif
