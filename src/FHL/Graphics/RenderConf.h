#ifndef FHL_RENDERCONF_H
#define FHL_RENDERCONF_H

#include <list>

#include <FHL/Graphics/Transformable.h>
#include <FHL/Graphics/Light.h>

namespace fhl
{
	class Texture;

	struct FHL_API RenderConf
	{
		  RenderConf(const RenderMatrices & _tm = {}, const Texture * _texture = nullptr, const std::list<Light> & _lights = {});
		  RenderConf(const Texture * _t);
		  RenderConf(const std::list<Light> & _lights);

		  RenderConf & operator+=(const RenderMatrices & _tm);
		  RenderConf & operator+=(const Texture * _t);
		  RenderConf & operator+=(const std::list<Light> & _lights);

		  bool operator==(const RenderConf & _other) const;
		  bool operator!=(const RenderConf & _other) const;

		  static const RenderConf & default();

		  RenderMatrices matrices;
		  const Texture * texture;
		  std::list<Light> lights;
	};

} // ns

#endif // FHL_RENDERCONF_H
