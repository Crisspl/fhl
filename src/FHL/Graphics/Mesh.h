#ifndef FHL_MESH_H
#define FHL_MESH_H

#include <string>
#include <vector>
#include <tuple>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Buffer.h>
#include <FHL/Maths/vectors.h>


namespace fhl 
{ 
	 class Model;
	 class ModelData;

namespace internal
{

	class FHL_API Mesh
	{
		using tuple3pair_t = std::tuple<std::pair<float, float>, std::pair<float, float>, std::pair<float, float>>;
		friend class Model;
		friend class ModelData;

		struct Vertex
		{
			Vec3f position;
			Vec3f normal;
			Vec2f texCoords;
		};

		struct TexturesPair
		{
			GLuint diffuse, specular;
		};

	public:
		Mesh(const std::vector<Mesh::Vertex> & _vertices, const std::vector<GLuint> & _indices, TexturesPair _textures);

	private:
		void setUp(const std::vector<Mesh::Vertex> & _vertices, const std::vector<GLuint> & _indices);

		TexturesPair textures;
		std::size_t indicesCount;
		tuple3pair_t minMaxVerts;
		Buffer vbo, ebo;
	};

}}

#endif
