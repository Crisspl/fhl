#include <FHL/Graphics/Buffer.h>

#include <algorithm>

namespace fhl { namespace internal
{

	 Buffer::Buffer(Target _target, Usage _usage)
		: target(_target),
		 usage(_usage),
		 size(0)
	 {
		  glGenBuffers(1, &m_id);
	 }

	 Buffer::Buffer(Buffer && _other)
		 : m_id(_other.m_id),
		 target(_other.target),
		 usage(_other.usage),
		 size(_other.size)
	 {
		  _other.m_id = 0;
	 }

	 Buffer & Buffer::operator=(Buffer && _other)
	 {
		  std::swap(m_id, _other.m_id);
		  target = _other.target;
		  usage = _other.usage;
		  size = _other.usage;

		  return *this;
	 }

	 Buffer::~Buffer()
	 {
		  glDeleteBuffers(1, &m_id);
	 }

	 void Buffer::bind() const
	 {
		  glBindBuffer(target, m_id);
	 }

	 void Buffer::unbind() const
	 {
		  glBindBuffer(target, 0);
	 }

	 void Buffer::setData(GLsizei _size, const void* _data)
	 {
		  size = _size;
		  glBufferData(target, _size, _data, usage);
	 }

	 void Buffer::updateData(GLuint _offset, GLsizei _size, const void* _data)
	 {
		  glBufferSubData(target, _offset, _size, _data);
	 }

}} // ns
