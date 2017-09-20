#ifndef FHL_SIZEABLE_H
#define FHL_SIZEABLE_H

#include <array>

#include <FHL/Graphics/Buffer.h>
#include <FHL/Graphics/Vao.h>
#include <FHL/Maths/vectors.h>

namespace fhl { namespace internal
{

	class FHL_API Sizeable
	{
	public:
		explicit Sizeable(const Vec2f & _size = Vec2f::one());
		Sizeable(Sizeable &&) = default; // move ctor and assign operator are not implicitly declared when the class has user-declared destructor
		Sizeable & operator=(Sizeable &&) = default;
		virtual ~Sizeable() = default;

		virtual void setSize(const Vec2f & _size);
		Vec2f getSize() const { return m_size; }

	protected:
		void uploadPosArray();

		Vao & getVao() { return m_vao; }
		const Vao & getVao() const { return m_vao; }

	private:
		std::array<Vec2f, 4> genPosArray(const Vec2f & _size) const;
		void setUp();

	private:
		Vao m_vao;
		Vec2f m_size;
		Vec2f m_posArray[4];

		static constexpr const char * s_posBufferName = "posb";
	};

}}

#endif
