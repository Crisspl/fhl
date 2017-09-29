#ifndef FHL_GRAPHICS_TEXTURED_SIZEABLE_H
#define FHL_GRAPHICS_TEXTURED_SIZEABLE_H

#include <utility>

#include <FHL/Graphics/Sizeable.h>
#include <FHL/Graphics/Texture.h>
#include <FHL/Utility/Rect.h>

namespace fhl { namespace detail
{

	class FHL_API TexturedSizeable
		: public Sizeable
	{
	public:
		explicit TexturedSizeable(Texture * _tex, const Vec2f & _size = Vec2f::zero());
		TexturedSizeable(TexturedSizeable &&) = default; // move ctor and assign operator are not implicitly declared when the class has user-declared destructor
		TexturedSizeable & operator=(TexturedSizeable &&) = default;
		virtual ~TexturedSizeable() = default;

		const Texture * getTexture() const { return m_texture; }
		const Rect & getTextureRect() const { return m_texRect; }

		void setSize(const Vec2f & _size) override;
		void uploadTexCoordsArray();

		void setTexture(Texture & _tex, bool _changeSize = true);
		void setTextureRect(const Rect & _rect, bool _changeSize = false);

	private:
		std::array<Vec2f, 4> genTexCoordsArray(const Rect & _rect) const;
		template<std::size_t ...Is>
		std::array<Vec2f, 4> genTexCoordsArray_impl(std::index_sequence<Is...>, const Rect & _rect) const;
		void setUp();

	private:
		Texture * m_texture;
		Rect m_texRect;

		static constexpr const char * s_texCoordsBufferName = "txb";
	};

}

template<std::size_t ...Is>
inline std::array<Vec2f, 4> detail::TexturedSizeable::genTexCoordsArray_impl(std::index_sequence<Is...>, const Rect & _rect) const
{
	Vec2f div = m_texture ? m_texture->getSize() : Vec2f::one();
	return { { (_rect[Is] / div)... } };
}

}

#endif
