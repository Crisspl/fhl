#ifndef FHL_BUFFER_H
#define FHL_BUFFER_H

#include <set>
#include <map>

#include <FHL/GL/OpenGL.h>
#include <FHL/common.h>

namespace fhl { namespace internal
{

	struct FHL_API Buffer
	{
		enum class Usage : GLenum
		{
			StaticDraw = GL_STATIC_DRAW,
			StaticRead = GL_STATIC_READ,
			StaticCopy = GL_STATIC_COPY,
			DynamicDraw = GL_DYNAMIC_DRAW,
			DynamicRead = GL_DYNAMIC_READ,
			DynamicCopy = GL_DYNAMIC_COPY,
			StreamDraw = GL_STREAM_DRAW,
			StreamRead = GL_STREAM_READ,
			StreamCopy = GL_STREAM_COPY
		};

		enum class Target : GLenum
		{
			ArrayBuffer = GL_ARRAY_BUFFER,
			AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
			CopyReadBuffer = GL_COPY_READ_BUFFER,
			CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
			DispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
			DrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER,
			ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
			PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
			PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
			QueryBuffer = GL_QUERY_BUFFER,
			ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
			TextureBuffer = GL_TEXTURE_BUFFER,
			TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
			UniformBuffer = GL_UNIFORM_BUFFER
		};

		Buffer(Usage _usage);
		Buffer(const Buffer &) = delete;
		Buffer & operator=(const Buffer &) = delete;
		Buffer(Buffer && _other);
		Buffer & operator=(Buffer && _other);
		~Buffer();

		void bind(Target _target) const;
		/* calls glBindBuffer even if buffer is already bound to the target */
		void forcedBind(Target _target) const;
		void unbind(Target _target) const;

		void setData(GLsizei _size, const void * _data);
		void updateData(GLuint _offset, GLsizei _size, const void * _data);

		Usage getUsage() const { return m_usage; }
		GLsizei getSize() const { return m_size; }
		bool isBoundTo(Target _target) const;

	private:
		/* return any target to which the buffer is bound */
		Target anyTarget() const;

	private:
		GLuint m_id;
		Usage m_usage;
		GLsizei m_size;
		mutable std::set<Target> m_targets;

		static std::map<Target, GLuint> s_binds;
	};

}}

#endif
