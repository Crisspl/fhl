#ifndef FHL_TEXTURE_H
#define FHL_TEXTURE_H

#include <string>

#include <FHL/GL/OpenGL.h>
#include <FHL/Maths/vectors.h>
#include <FHL/common.h>

namespace fhl
{
	class ResMgr;

	class FHL_API Texture
	{
		friend class ResMgr;

		template<typename, typename>
		friend struct std::pair;

	private:
		enum WrapOption : GLenum
		{
			Repeat = GL_REPEAT,
			ClampToBorder = GL_CLAMP_TO_BORDER
		};

	private:
		Texture(const Texture &) = delete;
		Texture & operator=(const Texture &) = delete;
		Texture(Texture && _other);
		Texture & operator=(Texture && _other);
		explicit Texture(const Vec2i & _size);
		explicit Texture(const std::string & _filePath);
		~Texture();

		const Texture & setWrapOption(WrapOption _option) const;

	public:
		GLuint getId() const { return m_id; }
		Vec2i getSize() const { return m_size; }

		Texture & setRepeated(bool _r);
		bool isRepeated() const { return m_isRepeated; }

	private:
		GLuint m_id;
		Vec2i m_size;
		bool m_isRepeated;
	};

}

#endif
