#ifndef FHL_UTILITY_ORIENTED_CUBE_H
#define FHL_UTILITY_ORIENTED_CUBE_H

#include <FHL/Utility/Cube.h>
#include <FHL/Maths/Quaternion.h>
#include <FHL/Maths/Plane.h>

namespace fhl
{

	class OrientedCube : public Cube
	{
	private:
		enum Side : std::size_t
		{
			Left = 0,
			Right,
			Top,
			Bottom,
			Back,
			Front
		};

	public:
		OrientedCube(const Vec3f & _lbb, const Vec3f & _size, const Vec3f & _origin, const Quaternion & _rot);

		bool contains(const Vec3f & _point) const override;

		Vec3f getSize() const override;

		Cube & adjustRight(float _offset) override;
		Cube & adjustLeft(float _offset) override;
		Cube & adjustTop(float _offset) override;
		Cube & adjustBottom(float _offset) override;
		Cube & adjustFront(float _offset) override;
		Cube & adjustBack(float _offset) override;

	private:
		void rotate(const Vec3f & _origin, const Quaternion & _rotation);
		std::array<Plane<float>, 6> recalcSidePlanes();
		static Vec3f calcOffsetVector(const Vec3f & _v, const Quaternion & _rot);

	private:
		std::array<Plane<float>, 6> m_sides;
		Quaternion m_rotation;
	};

}

#endif