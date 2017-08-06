#ifndef FHL_TEXTUREDSIZEABLE_H
#define FHL_TEXTUREDSIZEABLE_H

#include <FHL/Graphics/Sizeable.h>
#include <FHL/Graphics/Texture.h>
#include <FHL/Utility/Rect.h>

namespace fhl { namespace internal
{

	 class FHL_API TexturedSizeable
		 : public Sizeable
	 {
	 public:
		  explicit TexturedSizeable(Texture * _tex, Vec2f _size = Vec2f::zero());
		  TexturedSizeable(TexturedSizeable &&) = default; // move ctor and assign operator are not implicitly declared when the class has user-declared destructor
		  TexturedSizeable & operator=(TexturedSizeable &&) = default;
		  virtual ~TexturedSizeable() = default;

		  const Texture * getTexture() const { return m_texture; }
		  const Rect & getTextureRect() const { return m_texRect; }

		  void setSize(Vec2f _size) override;
		  void uploadTexCoordsArray();

		  void setTexture(Texture & _tex, bool _changeSize = true);
		  void setTextureRect(const Rect & _rect, bool _changeSize = false);

	 private:
		  void fillTxcArray(Vec2f _v);
		  void setUp();

	 private:
		  Texture * m_texture;
		  Rect m_texRect;
		  Vec2f m_texCoordsArray[4];
	 };

}} // ns


#endif // FHL_TEXTUREDSIZEABLE_H
