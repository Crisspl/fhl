#include <FHL/Graphics/Mesh.h>

#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace fhl { namespace detail
{

	Mesh::Mesh(const std::vector<Mesh::Vertex> & _vertices, const std::vector<GLuint> & _indices, TexturesPair _textures) :
		textures(_textures),
		indicesCount(_indices.size()),
		vbo(Buffer::Usage::StaticDraw),
		ebo(Buffer::Usage::StaticDraw)
	{
		setUp(_vertices, _indices);
	}

	void Mesh::setUp(const std::vector<Mesh::Vertex> & _vertices, const std::vector<GLuint> & _indices)
	{
		vbo.bind(Buffer::Target::ArrayBuffer);
		vbo.setData(_vertices.size() * sizeof(Vertex), _vertices.data());

		ebo.bind(Buffer::Target::ElementArrayBuffer);
		ebo.setData(_indices.size() * sizeof(GLuint), _indices.data());

		vbo.unbind(Buffer::Target::ArrayBuffer);
		ebo.unbind(Buffer::Target::ElementArrayBuffer);

#define comp(dim) [](const Vertex & a, const Vertex & b) { return a.position.dim() < b.position.dim(); }

		auto minMaxX = std::minmax_element(_vertices.begin(), _vertices.end(), comp(x));
		auto minMaxY = std::minmax_element(_vertices.begin(), _vertices.end(), comp(y));
		auto minMaxZ = std::minmax_element(_vertices.begin(), _vertices.end(), comp(z));

		minMaxVerts = std::make_tuple
		(
			std::make_pair(minMaxX.first->position.x(), minMaxX.second->position.x()),
			std::make_pair(minMaxY.first->position.y(), minMaxY.second->position.y()),
			std::make_pair(minMaxZ.first->position.z(), minMaxZ.second->position.z())
		);
#undef comp
	}

}}
