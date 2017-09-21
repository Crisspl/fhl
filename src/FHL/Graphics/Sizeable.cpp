#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Sizeable.h>


namespace fhl { namespace detail
{

	Sizeable::Sizeable(const Vec2f & _size) : m_size(_size)
	{
		setUp();
	}

	void Sizeable::setSize(const Vec2f & _size)
	{
		if (m_size == _size)
			return;
		m_size = _size;
		uploadPosArray();
	}

	void Sizeable::uploadPosArray()
	{
		Buffer * posBuffer = m_vao.getBuffer(s_posBufferName);
		posBuffer->bind(Buffer::Target::CopyWriteBuffer);
		posBuffer->updateData(0, 4 * sizeof(Vec2f), genPosArray(m_size).data());
		posBuffer->unbind(Buffer::Target::CopyWriteBuffer);
	}

	std::array<Vec2f, 4> Sizeable::genPosArray(const Vec2f & _size) const
	{
		return{ { Vec2f::zero(), Vec2f::right(_size.x()), _size, Vec2f::up(_size.y()) } };
	}

	void Sizeable::setUp()
	{
		Buffer posBuffer(Buffer::Usage::DynamicDraw);

		m_vao.bind();

		posBuffer.bind(Buffer::Target::ArrayBuffer);
		posBuffer.setData(4 * sizeof(Vec2f), genPosArray(m_size).data());

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		m_vao.unbind();

		m_vao.addBuffer(s_posBufferName, std::move(posBuffer));
	}

}}
