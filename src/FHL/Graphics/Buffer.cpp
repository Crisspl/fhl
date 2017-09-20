#include <FHL/Graphics/Buffer.h>

#include <algorithm>

namespace fhl { namespace detail
{
	std::map<Buffer::Target, GLuint> Buffer::s_binds;

	Buffer::Buffer(Usage _usage) :
		m_usage(_usage),
		m_size(0)
	{
		glGenBuffers(1, &m_id);
	}

	Buffer::Buffer(Buffer && _other) :
		m_id(_other.m_id),
		m_usage(_other.m_usage),
		m_size(_other.m_size),
		m_targets(std::move(m_targets))
	{
		_other.m_id = 0;
	}

	Buffer & Buffer::operator=(Buffer && _other)
	{
		std::swap(m_id, _other.m_id);
		m_usage = _other.m_usage;
		m_size = _other.m_size;
		std::swap(m_targets, _other.m_targets);

		return *this;
	}

	Buffer::~Buffer()
	{
		for (auto t : m_targets)
			if (s_binds[t] == m_id) s_binds[t] = 0;
		glDeleteBuffers(1, &m_id);
	}

	void Buffer::bind(Target _target) const
	{
		if (s_binds[_target] == m_id) return;

		forcedBind(_target);
	}

	void Buffer::forcedBind(Target _target) const
	{
		s_binds[_target] = m_id;
		m_targets.insert(_target);

		glBindBuffer(static_cast<GLenum>(_target), m_id);
	}

	void Buffer::unbind(Target _target) const
	{
		auto it = m_targets.find(_target);
		if (it != m_targets.cend())
			m_targets.erase(it);

		if (s_binds[_target] == m_id)
			s_binds[_target] = 0;

		glBindBuffer(static_cast<GLenum>(_target), 0);
	}

	void Buffer::setData(GLsizei _size, const void* _data)
	{
		if (m_targets.empty()) return;

		m_size = _size;
		glBufferData(static_cast<GLenum>(anyTarget()), _size, _data, static_cast<GLenum>(m_usage));
	}

	void Buffer::updateData(GLuint _offset, GLsizei _size, const void* _data)
	{
		if (m_targets.empty()) return;

		glBufferSubData(static_cast<GLenum>(anyTarget()), _offset, _size, _data);
	}

	bool Buffer::isBoundTo(Target _target) const
	{
		auto it = s_binds.find(_target);
		if (it == s_binds.cend())
			return false;
		return it->second == m_id;
	}

	auto Buffer::anyTarget() const -> Target
	{
		for (auto t : m_targets)
			if (s_binds[t] == m_id)
				return t;
		throw std::runtime_error{"Buffer is not bound to any target"};
	}

}}
