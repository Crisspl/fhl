#ifndef FHL_UTILITY_RECT_H
#define FHL_UTILITY_RECT_H

#include <array>

#include <FHL/Maths/vectors.h>
#include <FHL/common.h>

namespace fhl {

	 struct FHL_API Projection
	 {
		  constexpr bool overlaps(const Projection & _p) const
		  {
				return ((min > _p.min && min < _p.max) || (max < _p.max && max > _p.min));
		  }
		  float min, max;
	 };

	 class Circle;

	 class FHL_API Rect
	 {
		 using Verts_t = std::array<Vec2f, 4>;

	 public:
		 enum VerticlePos : std::size_t /* Note that Y axis can be inverted! */
		 {
			 BL = 0, // Bottom-left
			 BR, // Bottom-right
			 UR, // Upper-right
			 UL  // Upper-left
		 };

	 public:
		 Rect(const Vec2f & _botLeft, const Vec2f & _size) :
			 m_verts{ { _botLeft, _botLeft + Vec2f(_size.x(), 0), _botLeft + _size, _botLeft + Vec2f(0, _size.y()) } } {}
		 explicit Rect(const Vec2f & _size) : Rect(Vec2f::zero(), _size) {}
		 virtual ~Rect() = default;

	 public:
		 bool operator==(const Rect & _other) const;
		 bool operator!=(const Rect & _other) const;

		 virtual bool contains(const Vec2f & _p) const;
		 virtual bool overlaps(const Rect & _rect) const;
		 bool overlaps(const Circle & _circle) const;

		 const Vec2f & operator[](std::size_t _i) const { return m_verts[_i]; }
		 const Verts_t & getVerts() const { return m_verts; }

		 const Vec2f & getPosition() const { return m_verts[BL]; }
		 Vec2f getSize() const { return m_verts[UR] - m_verts[BL]; }
		 Projection project(const Vec2f & _axis) const;

		 virtual Rect & adjustX(float _width);
		 virtual Rect & adjustY(float _height);
		 Rect & translate(const Vec2f & _offset);

		 virtual const std::array<Vec2f, 2> & getAxes() const { return s_axes; }

	 protected:
		 Verts_t m_verts;

	 private:
		 constexpr static std::array<Vec2f, 2> s_axes{ { { 1, 0 }, { 0, 1 } } };
	 };

}

#endif