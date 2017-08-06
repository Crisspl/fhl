#ifndef FHL_VAO_H
#define FHL_VAO_H


#include <map>
#include <string>
#include <utility>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Buffer.h>

namespace fhl { namespace internal
{

	 class FHL_API Vao
	 {
	 public:
		  Vao();
		  Vao(const Vao &) = delete;
		  Vao & operator=(const Vao &) = delete;
		  Vao(Vao && _other);
		  Vao & operator=(Vao && _other);
		  ~Vao();

		  void bind() const;
		  void unbind() const;

		  GLuint getId() const { return m_id; }

		  Buffer* getBuffer(std::string _key);
		  void addBuffer(std::string _key, Buffer* _buffer);

	 private:
		  GLuint m_id;
		  std::map<std::string, Buffer *> m_buffers;
	 };

}}

#endif // FHL_VAO_H