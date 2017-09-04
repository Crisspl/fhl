#ifndef FHL_MODEL_H
#define FHL_MODEL_H

#include <FHL/Graphics/Vao.h>
#include <FHL/Graphics/Renderable.h>
#include <FHL/Graphics/Transformable3D.h>
#include <FHL/Graphics/Litable.h>
#include <FHL/Graphics/UsingShader.h>
#include <FHL/Graphics/ModelData.h>
#include <FHL/Graphics/Color.h>
#include <FHL/Utility/Cube.h>

namespace fhl
{
	class ResMgr;

	class FHL_API Model :
		public Renderable,
		public Transformable3D,
		public Litable,
		public UsingShader
	{
		friend class ResMgr;

		enum AttrLoc : GLuint
		{
			Position = 0,
			Normal,
			TexCoord
		};

	public:
		explicit Model(ModelData & _data);
		Model(const Model &) = delete;
		Model & operator=(const Model &) = delete;

		void render(const RenderConf & _conf) const override;

		void setModelData(ModelData & _data);
		void setUseColorOnly(bool _val) { m_useColorOnly = _val; } // render textures or only single color
		void setColor(const Color & _color) { m_color = _color; }

		Vec3f getSize() const { return m_modelData->getSize(); }
		const ModelData * getModelData() const { return m_modelData; }
		bool getUseColorOnly() const { return m_useColorOnly; }
		const Color & getColor() const { return m_color; }

		fhl::Cube getAABB() const;

	private:
		void setUp();
		void renderMeshes() const;

	private:
		ModelData * m_modelData;
		std::vector<internal::Vao> m_vaos;
		Color m_color;
		bool m_useColorOnly;

		constexpr static const char * simpleShaderName = "_FHL_modelSimpleShader";
		constexpr static const char * lightShaderName = "_FHL_modelLightShader";
	};

}

#endif
