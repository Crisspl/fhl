#include <FHL/Graphics/Texture.h>

#include <utility>

#include <SOIL/SOIL.h>

namespace fhl
{
	std::map<GLuint, GLuint> Texture::s_bonds;

	Texture::Texture(const Vec2i & _size) : m_size(_size), m_isRepeated(false)
	{
		glGenTextures(1, &m_id);

		fastBind();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _size.x(), _size.y(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		setRepeated(false);
	}

	Texture::Texture(const std::string & _filePath) : m_id(0u), m_size(Vec2i::zero()), m_isRepeated(false)
	{
		unsigned char * img = SOIL_load_image(_filePath.c_str(), &m_size.x(), &m_size.y(), 0, SOIL_LOAD_RGBA);

		if (img)
		{
			glGenTextures(1, &m_id);

			fastBind();
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x(), m_size.y(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			setRepeated(false);

			SOIL_free_image_data(img);
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
		fastBind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _option);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _option);

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

	void Texture::bind(GLuint _texUnit) const
	{
		if (_texUnit >= (GLuint)getMaxTextureUnits() || isBoundTo(_texUnit))
			return;

		s_bonds[_texUnit] = m_id;
		m_texUnits.insert(_texUnit);

		glActiveTexture(GL_TEXTURE0 + _texUnit);
		glBindTexture(GL_TEXTURE_2D, m_id);
	}

	void Texture::fastBind() const
	{
		bind(getMaxTextureUnits() - 1);
	}

	void Texture::unbind(GLuint _texUnit) const
	{
		if (_texUnit >= (GLuint)getMaxTextureUnits())
			return;
		{
		auto it = m_texUnits.find(_texUnit);
		if (it != m_texUnits.cend())
			m_texUnits.erase(it);
		}
		{
		auto it = s_bonds.find(_texUnit);
		if (it != s_bonds.end() && it->second)
			it->second = 0;
		}

		glActiveTexture(GL_TEXTURE0 + _texUnit);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	bool Texture::isBoundTo(GLuint _texUnit) const
	{
		auto it = s_bonds.find(_texUnit);
		if (it == s_bonds.cend())
			return false;
		return it->second == m_id;
	}

	GLint Texture::getMaxTextureUnits()
	{
		static GLint r{};
		if (!r)
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &r);
		return r;
	}

}
