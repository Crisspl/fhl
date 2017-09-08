#ifndef FHL_RENDERTEXTURE_H
#define FHL_RENDERTEXTURE_H

#include <algorithm>
#include <functional>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Texture.h>
#include <FHL/Graphics/Renderable.h>

namespace fhl
{

#define _FHL_GEN_GL_OBJECT_TRAITS_CLASS(Name, Create, Destroy, BindTarget, Bind) \
struct Name \
{ \
	static GLuint create() \
	{ \
		GLuint id; \
		Create(1, &id); \
		return id; \
	} \
	static void destroy(GLuint _id) \
	{ \
		Destroy(1, &_id); \
	} \
	static void bind(GLuint _id) \
	{ \
		Bind(BindTarget, _id); \
	} \
};

	namespace impl
	{
		_FHL_GEN_GL_OBJECT_TRAITS_CLASS(GlRboTraits, glGenRenderbuffers, glDeleteRenderbuffers, GL_RENDERBUFFER, glBindRenderbuffer)
		_FHL_GEN_GL_OBJECT_TRAITS_CLASS(GlFboTraits, glGenFramebuffers, glDeleteFramebuffers, GL_FRAMEBUFFER, glBindFramebuffer)
#undef _FHL_GEN_GL_OBJECT_TRAITS_CLASS

		template<typename _Traits>
		struct GlObject
		{
			GlObject() : id(_Traits::create()) {}
			GlObject(GlObject && _other) : id(_other) { _other.id = 0; }
			GlObject & operator=(GlObject && _other)
			{
				std::swap(id, _other.id);
				return *this;
			}
			virtual ~GlObject() { _Traits::destroy(id); }

			operator GLuint() const { return id; }

			void bind() const { _Traits::bind(id); }
			void unbind() const { _Traits::bind(0); }

			GLuint id;
		};

		struct GlRbo : GlObject<GlRboTraits>
		{
			void establishStorage(Vec2i _size) { glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _size.x(), _size.y()); }
		};
		struct GlFbo : GlObject<GlFboTraits>
		{
			void attachTexture(GLuint _texId) const { glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texId, 0); }
			void attachRbo(GLuint _rboId) const { glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _rboId); }
		};
	}


	class FHL_API RenderTexture
	{
	public:
		explicit RenderTexture(Texture & _tex);
		RenderTexture(const RenderTexture &) = delete;
		RenderTexture & operator=(const RenderTexture &) = delete;
		RenderTexture(RenderTexture &&) = default;
		RenderTexture & operator=(RenderTexture &&) = default;

		void clearColor(const Color & _color) const;
		void renderToTex(Renderable & _renderable, const RenderConf & _conf = RenderConf::default()) const;
		Texture & getTexture() { return m_tex; }

	private:
		void setUp();

	private:
		impl::GlFbo m_fbo;
		impl::GlRbo m_rbo;
		std::reference_wrapper<Texture> m_tex;
	};

}

#endif
