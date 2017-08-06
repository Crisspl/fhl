#include <FHL/Graphics/RenderConf.h>

namespace fhl
{

	 RenderConf RenderConf::Default;

	 RenderConf::RenderConf(const RenderMatrices & _tm, const Texture * _texture, const std::list<Light> & _lights)
		 : matrices(_tm),
		   texture(_texture),
		   lights(_lights)
	 {
	 }

	 RenderConf::RenderConf(const Texture * _t)
		  : RenderConf({}, _t)
	 {
	 }

	 RenderConf::RenderConf(const std::list<Light>& _lights)
		  : RenderConf({}, nullptr, _lights)
	 {
	 }

	 RenderConf & RenderConf::operator+=(const RenderMatrices & _tm)
	 {
		 matrices = _tm;
		 return *this;
	 }

	 RenderConf & RenderConf::operator+=(const Texture * _t)
	 {
		 texture = _t;
		 return *this;
	 }

	 RenderConf & RenderConf::operator+=(const std::list<Light> & _lights)
	 {
		  lights = _lights;
		  return *this;
	 }

	 bool RenderConf::operator==(const RenderConf & _other) const
	 {
		  if (this == &_other) 
				return true;
		  return
				texture == _other.texture &&
				matrices == _other.matrices &&
				lights == _other.lights;
	 }

	 bool RenderConf::operator!=(const RenderConf & _other) const
	 {
		 return !(*this == _other);
	 }


} // ns