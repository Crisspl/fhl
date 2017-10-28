#ifndef FHL_GRAPHICS_MODEL_DATA_H
#define FHL_GRAPHICS_MODEL_DATA_H

#include <string>
#include <vector>
#include <tuple>

#include <FHL/Graphics/Mesh.h>

struct aiMesh;
struct aiMaterial;
struct aiScene;
struct aiNode;

namespace fhl
{

	class Texture;

	class FHL_API ModelData
	{
		friend class ResMgr;
		template<typename, typename>
		friend struct std::pair;

		explicit ModelData(const std::string & _path);
		ModelData(const ModelData &) = delete;
		ModelData & operator=(const ModelData &) = delete;
		ModelData(ModelData &&) = default;
		ModelData & operator=(ModelData &&) = default;
		~ModelData();

	private:
		void load(const std::string & _path);
		void processNode(aiNode * _nodePtr, const aiScene * _scenePtr);
		detail::Mesh processMesh(aiMesh * _meshPtr, const aiScene * _scenePtr);
		std::tuple<Vec3f, Vec3f> calcExtents() const;
		Texture * loadTexture(aiMesh * _mesh, aiMaterial * _materialPtr, int _texType);

	public:
		const std::vector<detail::Mesh> & getMeshes() const { return m_meshes; }
		const Vec3f & getSize() const { return m_size; }
		const Vec3f & getLeftBottomRear() const { return m_leftBottomRearCorner; }

	private:
		std::vector<detail::Mesh> m_meshes;
		std::vector<std::string> m_texNames;
		std::string m_directory;
		std::size_t m_meshCount;
		Vec3f m_size;
		Vec3f m_leftBottomRearCorner; // a point {X_min, Y_min, Z_min}

		static std::size_t s_createdCount;
	};

}

#endif