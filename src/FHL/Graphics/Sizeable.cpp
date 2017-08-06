#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Sizeable.h>


namespace fhl { namespace internal
{

	 Sizeable::Sizeable(Vec2f _size) :
		  m_size(_size)
	 {	  
		  setUp();
	 }

	 void Sizeable::setSize(Vec2f _size)
	 {
		 m_size = _size;

		 updatePosArray();
		 uploadPosArray();
	 }

	 void Sizeable::updatePosArray()
	 {
		 m_posArray[0] = { 0.f, 0.f };
		 m_posArray[1] = { m_size.x(), 0.f };
		 m_posArray[2] = m_size;
		 m_posArray[3] = { 0.f, m_size.y() };
	 }

	 void Sizeable::uploadPosArray()
	 {
		 Buffer * posBuffer = m_vao.getBuffer("posBuffer");
		 posBuffer->bind();
		 posBuffer->updateData(0, sizeof(m_posArray), m_posArray);
		 posBuffer->unbind();
	 }

	 void Sizeable::setUp()
	 {
		  updatePosArray();

		  Buffer * posBuffer = new Buffer(Buffer::Target::ArrayBuffer, Buffer::Usage::StaticDraw);
		  m_vao.addBuffer("posBuffer", posBuffer);

		  m_vao.bind();

		  posBuffer->bind();
		  posBuffer->setData(sizeof(m_posArray), m_posArray);

		  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (GLvoid*)0);
		  glEnableVertexAttribArray(0);

		  m_vao.unbind();
	 }

}} // ns
