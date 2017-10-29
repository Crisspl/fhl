#include <FHL/Graphics/ResMgr.h>

#include <FHL/Graphics/ColoredRect.h>
#include <FHL/Graphics/Model.h>
#include <FHL/Graphics/Sprite.h>
#include <FHL/Graphics/VertexArray.h>

namespace fhl
{

	std::map<std::string, Shader> ResMgr::m_shaders;
	std::map<std::string, Texture> ResMgr::m_textures;
	std::map<std::string, ModelData> ResMgr::m_models;

	Shader * ResMgr::loadShader(const std::string & _name, const std::string & _vert, const std::string & _frag, Shader::SourceFrom _srcFrom)
	{
		if (!isShaderLoaded(_name))
			m_shaders.emplace(std::piecewise_construct, std::make_tuple(_name), std::make_tuple(_vert.c_str(), _frag.c_str(), _srcFrom));
		return getShader(_name);
	}

	Texture * ResMgr::loadTexture(const std::string & _name, const std::string & _path)
	{
		if (!isTextureLoaded(_name))
			m_textures.emplace(std::piecewise_construct, std::make_tuple(_name), std::make_tuple(_path));
		return getTexture(_name);
	}

	Texture * ResMgr::createTexture(const std::string & _name, Vec2i _size)
	{
		if (!isTextureLoaded(_name))
			m_textures.emplace(std::piecewise_construct, std::make_tuple(_name), std::make_tuple(_size));
		return getTexture(_name);
	}

	ModelData * ResMgr::loadModelData(const std::string & _name, const std::string & _path)
	{
		if (!isModelDataLoaded(_name))
			m_models.emplace(std::piecewise_construct, std::make_tuple(_name), std::make_tuple(_path));
		return getModelData(_name);
	}

	Shader * ResMgr::getShader(const std::string & _name)
	{
		auto it = m_shaders.find(_name);
		return it != m_shaders.cend() ? &it->second : nullptr;
	}

	Texture * ResMgr::getTexture(const std::string & _name)
	{
		auto it = m_textures.find(_name);
		return it != m_textures.cend() ? &it->second : nullptr;
	}

	ModelData * ResMgr::getModelData(const std::string & _name)
	{
		auto it = m_models.find(_name);
		return it != m_models.cend() ? &it->second : nullptr;
	}

	template<typename _T>
	Shader * ResMgr::getDefaultSimpleShader()
	{
		return getShader(_T::simpleShaderName());
	}

	template FHL_API Shader * ResMgr::getDefaultSimpleShader<ColoredRect>();
	template FHL_API Shader * ResMgr::getDefaultSimpleShader<Model>();
	template FHL_API Shader * ResMgr::getDefaultSimpleShader<Sprite>();
	template FHL_API Shader * ResMgr::getDefaultSimpleShader<VertexArray>();

	template<typename _T>
	Shader * ResMgr::getDefaultLightShader()
	{
		return getShader(_T::lightShaderName());
	}

	template FHL_API Shader * ResMgr::getDefaultLightShader<ColoredRect>();
	template FHL_API Shader * ResMgr::getDefaultLightShader<Model>();
	template FHL_API Shader * ResMgr::getDefaultLightShader<Sprite>();

	bool ResMgr::isShaderLoaded(const std::string & _name)
	{
		return getShader(_name) != nullptr;
	}

	bool ResMgr::isTextureLoaded(const std::string & _name)
	{
		return getTexture(_name) != nullptr;
	}

	bool ResMgr::isModelDataLoaded(const std::string & _name)
	{
		return getModelData(_name) != nullptr;
	}

	void ResMgr::removeShader(const std::string & _name)
	{
		m_shaders.erase(_name);
	}

	void ResMgr::removeTexture(const std::string & _name)
	{
		m_textures.erase(_name);
	}

	void ResMgr::removeModelData(const std::string & _name)
	{
		m_models.erase(_name);
	}

	void ResMgr::removeAllShaders()
	{
		m_shaders.clear();
	}

	void ResMgr::removeAllTextures()
	{
		m_textures.clear();
	}

	void ResMgr::removeAllModelData()
	{
		m_models.clear();
	}

	void ResMgr::clear()
	{
		removeAllShaders();
		removeAllTextures();
		removeAllModelData();
	}

}
