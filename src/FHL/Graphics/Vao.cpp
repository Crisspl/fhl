#include <FHL/Graphics/Vao.h>

#include <algorithm>

namespace fhl { namespace internal
{

	 Vao::Vao()
	 {
		 glGenVertexArrays(1, &m_id);
	 }

	 Vao::Vao(Vao && _other)
		 : m_id(_other.m_id),
		   m_buffers(std::move(_other.m_buffers))
	 {
		  for (auto & el : _other.m_buffers)
				el.second = nullptr;
		  _other.m_id = 0;
	 }

	 Vao & Vao::operator=(Vao && _other)
	 {
		  std::swap(m_buffers, _other.m_buffers);
		  std::swap(m_id, _other.m_id);

		  return *this;
	 }

	 Vao::~Vao()
	 {
		  for (auto & el : m_buffers)
				delete el.second;
		  glDeleteVertexArrays(1, &m_id);
	 }

	 void Vao::bind() const
	 {
		  glBindVertexArray(m_id);
	 }

	 void Vao::unbind() const
	 {
		  glBindVertexArray(0);
	 }

	 Buffer* Vao::getBuffer(std::string _key)
	 {
		  return m_buffers[_key];
	 }

	 void Vao::addBuffer(std::string _key, Buffer* _buffer)
	 {
		  m_buffers[_key] = _buffer;
	 }

}} // ns
