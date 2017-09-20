#include <FHL/Graphics/TexturedSizeable.h>

namespace fhl { namespace detail
{

	TexturedSizeable::TexturedSizeable(Texture * _tex, const Vec2f & _size) :
		Sizeable(_size),
		m_texture(_tex),
		m_texRect(Vec2f::zero(), Vec2f::one())
	{
		setUp();
	}

	void TexturedSizeable::setSize(const Vec2f & _size)
	{
		if (!m_texture)
			return;
		Sizeable::setSize(_size);
		m_texRect = Rect(Vec2f::zero(), getSize() / (Vec2f)m_texture->getSize());
		uploadTexCoordsArray();
	}

	void TexturedSizeable::uploadTexCoordsArray()
	{
		Buffer * txcBuffer = getVao().getBuffer(s_texCoordsBufferName);
		txcBuffer->bind(Buffer::Target::CopyWriteBuffer);
		txcBuffer->updateData(0, 4 * sizeof(Vec2f), genTexCoordsArray(m_texRect).data());
		txcBuffer->unbind(Buffer::Target::CopyWriteBuffer);
	}

	void TexturedSizeable::setTexture(Texture & _tex, bool _changeSize)
	{
		m_texture = &_tex;
		if (_changeSize)
			setSize(_tex.getSize());
	}

	void TexturedSizeable::setTextureRect(const Rect & _rect, bool _changeSize)
	{
		if (!m_texture)
			return;
		if (_changeSize)
			setSize(_rect.getSize());
		m_texRect = _rect;
		uploadTexCoordsArray();
	}

	std::array<Vec2f, 4> TexturedSizeable::genTexCoordsArray(const Rect & _rect) const
	{
		return genTexCoordsArray_impl(std::make_index_sequence<4>{}, _rect);
	}

	void TexturedSizeable::setUp()
	{
		Buffer txcBuffer(Buffer::Usage::DynamicDraw);

		getVao().bind();

		txcBuffer.bind(Buffer::Target::ArrayBuffer);
		txcBuffer.setData(4 * sizeof(Vec2f), genTexCoordsArray(m_texRect).data());

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (GLvoid*)0);
		glEnableVertexAttribArray(1);

		getVao().unbind();

		getVao().addBuffer(s_texCoordsBufferName, std::move(txcBuffer));
	}

}}
