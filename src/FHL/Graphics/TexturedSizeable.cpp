#include <FHL/Graphics/TexturedSizeable.h>

namespace fhl { namespace internal
{

	TexturedSizeable::TexturedSizeable(Texture * _tex, Vec2f _size) :
		Sizeable(_size),
		m_texture(_tex),
		m_texRect(Vec2f::zero(), Vec2f::one())
	{
		fillTxcArray(Vec2f::one());
		setUp();
	}

	void TexturedSizeable::setSize(Vec2f _size)
	{
		if (!m_texture)
			return;

		Sizeable::setSize(_size);
		fillTxcArray(getSize() / Vec2f(m_texture->getSize()));
		uploadTexCoordsArray();
	}

	void TexturedSizeable::uploadTexCoordsArray()
	{
		Buffer * txcBuffer = getVao().getBuffer("texCoordsBuffer");
		txcBuffer->bind(Buffer::Target::ArrayBuffer);
		txcBuffer->updateData(0, sizeof(m_texCoordsArray), m_texCoordsArray);
		txcBuffer->unbind(Buffer::Target::ArrayBuffer);
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

		m_texRect = _rect;

		if (_changeSize)
			setSize(_rect.getSize());

		for (int i = 0; i < 4; i++)
			m_texCoordsArray[i] = _rect[i] / Vec2f(m_texture->getSize());

		uploadTexCoordsArray();
	}

	void TexturedSizeable::fillTxcArray(Vec2f _v)
	{
		m_texCoordsArray[0] = { 0, 0 };
		m_texCoordsArray[1] = { _v.x(), 0 };
		m_texCoordsArray[2] = _v;
		m_texCoordsArray[3] = { 0, _v.y() };
	}

	void TexturedSizeable::setUp()
	{
		Buffer texCoordsBuffer(Buffer::Usage::DynamicDraw);

		getVao().bind();

		texCoordsBuffer.bind(Buffer::Target::ArrayBuffer);
		texCoordsBuffer.setData(sizeof(m_texCoordsArray), m_texCoordsArray);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vec2f), (GLvoid*)0);
		glEnableVertexAttribArray(1);

		getVao().unbind();

		getVao().addBuffer("texCoordsBuffer", std::move(texCoordsBuffer));
	}

}}
