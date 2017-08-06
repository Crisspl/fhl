#ifndef FHL_MODELDATA_H
#define FHL_MODELDATA_H

#include <string>
#include <vector>

#include <FHL/Graphics/Mesh.h>

struct aiMesh;
struct aiMaterial;
struct aiScene;
struct aiNode;
enum aiTextureType;

namespace fhl
{

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
		internal::Mesh processMesh(aiMesh * _meshPtr, const aiScene * _scenePtr);
		void calcSize();
		GLuint loadTexture(aiMesh * _mesh, aiMaterial * _materialPtr, aiTextureType _texType);

	public:
		const std::vector<internal::Mesh> & getMeshes() const { return m_meshes; }
		Vec3f getSize() const { return m_size; }

	private:
		std::vector<internal::Mesh> m_meshes;
		std::vector<std::string> m_texNames;
		std::string m_directory;
		std::size_t m_meshCount;
		Vec3f m_size;

		static std::size_t s_createdCount;
	};

}

#endif