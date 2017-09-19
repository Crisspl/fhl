#ifndef FHL_SIZEABLE_H
#define FHL_SIZEABLE_H

#include <FHL/Graphics/Buffer.h>
#include <FHL/Graphics/Vao.h>
#include <FHL/Maths/vectors.h>

namespace fhl { namespace internal
{

	 class FHL_API Sizeable
	 {
	 public:
		  explicit Sizeable(Vec2f _size = { 1, 1 });
		  Sizeable(Sizeable &&) = default; // move ctor and assign operator are not implicitly declared when the class has user-declared destructor
		  Sizeable & operator=(Sizeable &&) = default;
		  virtual ~Sizeable() = default;

		  virtual void setSize(Vec2f _size);
		  Vec2f getSize() const { return m_size; }

	 protected:
		  void updatePosArray();
		  void uploadPosArray();

		  Vao & getVao() { return m_vao; }
		  const Vao & getVao() const { return m_vao; }

	 private:
		  void setUp();

	 private:
		  Vao m_vao;
		  Vec2f m_size;
		  Vec2f m_posArray[4];
	 };

}}

#endif
