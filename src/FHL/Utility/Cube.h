#ifndef FHL_CUBE_H
#define FHL_CUBE_H

#include <array>

#include <FHL/Maths/Vec3.h>
#include <FHL/common.h>

namespace fhl
{

	class FHL_API Cube
	{
		using Verts_t = std::array<Vec3f, 8>;

	public:
		enum VerticlePos : std::size_t
		{
			BLR = 0, // bottom-left-rear
			BRR, // bottom-right-rear
			URR, // upper-right-rear
			ULR, // upper-left-rear
			BLF, // bottom-left-front
			BRF, // bottom-right-front
			URF, // upper-right-front
			ULF // upper-left-front
		};

	public:
		Cube(const Vec3f & _position, const Vec3f & _size);
		explicit Cube(const Vec3f & _size);
		virtual ~Cube() = default;

	public:
		virtual bool contains(const Vec3f & _p) const;
		virtual bool overlaps(const Cube & _other) const;

		const Vec3f & operator[](std::size_t _i) const { return m_verts[_i]; }
		const Verts_t & getVerts() const { return m_verts; }

		const Vec3f & getPosition() const { return m_verts[BLR]; }
		const Vec3f & getSize() const { return m_size; }

		virtual Cube & adjustX(float _offset);
		virtual Cube & adjustY(float _offset);
		virtual Cube & adjustZ(float _offset);
		virtual Cube & translate(const Vec3f & _offset);

	private:
		Vec3f m_size;
		Verts_t m_verts;
	};

}

#endif
