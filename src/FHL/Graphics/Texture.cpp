#include <FHL/Graphics/Texture.h>

#include <utility>

#include <SOIL/SOIL.h>

namespace fhl
{

	Texture::Texture(const Vec2i & _size) : m_size(_size), m_isRepeated(false)
	{
		glGenTextures(1, &m_id);

		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _size.x(), _size.y(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		setRepeated(false);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture::Texture(const std::string & _filePath) : m_id(0u), m_size(Vec2i::zero()), m_isRepeated(false)
	{
		unsigned char * img = SOIL_load_image(_filePath.c_str(), &m_size.x(), &m_size.y(), 0, SOIL_LOAD_RGBA);

		if (img)
		{
			glGenTextures(1, &m_id);

			glBindTexture(GL_TEXTURE_2D, m_id);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x(), m_size.y(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			setRepeated(false);

			SOIL_free_image_data(img);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	Texture::Texture(Texture && _other) :
		m_id(_other.m_id),
		m_size(_other.m_size),
		m_isRepeated(_other.m_isRepeated)
	{
		_other.m_id = 0;
	}

	Texture & Texture::operator=(Texture && _other)
	{
		std::swap(m_id, _other.m_id);
		m_size = _other.m_size;
		m_isRepeated = _other.m_isRepeated;

		return *this;
	}


	Texture::~Texture()
	{
		glDeleteTextures(1, &m_id);
	}

	const Texture & Texture::setWrapOption(WrapOption _option) const
	{
		glBindTexture(GL_TEXTURE_2D, m_id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _option);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _option);

		glBindTexture(GL_TEXTURE_2D, 0);

		return *this;
	}

	Texture & Texture::setRepeated(bool _r)
	{
		if (m_isRepeated == _r) return *this;

		if (_r) setWrapOption(Repeat);
		else setWrapOption(ClampToBorder);
		m_isRepeated = _r;
		return *this;
	}

}
