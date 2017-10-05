#ifndef FHL_UTILITY_CUBE_H
#define FHL_UTILITY_CUBE_H

#include <array>

#include <FHL/Maths/Vec3.h>
#include <FHL/common.h>

namespace fhl
{

	class FHL_API Cube
	{
		using Verts_t = std::array<Vec3f, 8>;

	public:
		enum VertexPos : std::size_t
		{
			LBB = 0, // left-bottom-back
			RBB, // right-bottom-back
			RTB, // right-top-back
			LTB, // left-top-rear
			LBF, // left-bottom-front
			RBF, // right-bottom-front
			RTF, // right-top-front
			LTF  // left-top-front
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

		const Vec3f & getPosition() const { return m_verts[LBB]; }
		Vec3f getSize() const { return m_verts[RTF] - m_verts[LBB]; }

		virtual Cube & adjustRight(float _offset);
		virtual Cube & adjustLeft(float _offset);
		virtual Cube & adjustTop(float _offset);
		virtual Cube & adjustBottom(float _offset);
		virtual Cube & adjustFront(float _offset);
		virtual Cube & adjustBack(float _offset);
		virtual Cube & translate(const Vec3f & _offset);

	protected:
		Cube & translateSide(VertexPos _a, VertexPos _b, VertexPos _c, VertexPos _d, const Vec3f & _offset);

	private:
		Verts_t m_verts;
	};

}

#endif
