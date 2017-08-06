#ifndef FHL_LITABLE_H
#define FHL_LITABLE_H

#include <list>
#include <vector>
#include <type_traits>
#include <iterator>

#include <FHL/Graphics/Light.h>

namespace fhl
{

	class FHL_API Litable
	{
	public:
		Litable() = default;
		Litable(Litable &&) = default;
		Litable & operator=(Litable &&) = default;
		virtual ~Litable() = default;

		virtual void addLight(const Light & _light)
		{
			m_lights.push_back(_light);
		}
		virtual void addLights(const std::vector<Light> & _lights)
		{
			m_lights.insert(m_lights.cbegin(), _lights.cbegin(), _lights.cend());
		}
		template<typename _It>
		void addLights(_It _begin, const _It _end);

		virtual void setLight(const Light & _light)
		{
			m_lights.clear();
			addLight(_light);
		}
		virtual void setLights(const std::vector<Light> & _lights)
		{
			m_lights.clear();
			addLights(_lights);
		}
		template<typename _It>
		void setLights(_It _begin, const _It _end);

		std::size_t getLightsCount() const { return m_lights.size(); }
		const std::list<Light> & getLights() const { return m_lights; }

	private:
		std::list<Light> m_lights;
	};

	template<typename _It>
	void Litable::addLights(_It _begin, const _It _end)
	{
		static_assert(std::is_same<typename std::iterator_traits<_It>::value_type, Light>::value,
			"fhl::Litable::addLights: _begin and _end must be iterators of containers of fhl::Light objects");

		while (_begin != _end)
			addLight(*(_begin++));
	}

	template<typename _It>
	void Litable::setLights(_It _begin, const _It _end)
	{
		static_assert(std::is_same<typename std::iterator_traits<_It>::value_type, Light>::value,
			"fhl::Litable::addLights: _begin and _end must be iterators of containers of fhl::Light objects");

		m_lights.clear();
		addLights(_begin, _end);
	}

}

#endif // FHL_LITABLE_H
