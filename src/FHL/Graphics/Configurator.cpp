#include <FHL/Graphics/Configurator.h>

#include <FHL/Utility/Debug.h>
#include <FHL/Maths/mathsFuncs.h>

using namespace fhl::detail;

namespace fhl
{
	bool Configurator::m_initialized{ false };
	std::unique_ptr<detail::Buffer> Configurator::m_rectShapeEbo(nullptr);
	Mat4f Configurator::m_projection;
	View * Configurator::m_currentGlobal3DView{ nullptr };

	const GLuint Configurator::m_rectShapeIndices[] =
	{
		 0, 1, 3,
		 1, 2, 3
	};
	Vec2i Configurator::m_vpSize;
	std::map<std::string, View> Configurator::m_views;
	bool Configurator::m_depthTestEnabled{ false };

	void Configurator::init(GLuint _width, GLuint _height)
	{
		if (m_initialized)
			return;

		::flextGLInit();

		glViewport(0, 0, _width, _height);
		m_vpSize = { static_cast<int>(_width), static_cast<int>(_height) };
		m_projection = Mat4f::perspective(-45.f, static_cast<float>(-m_vpSize.x()) / m_vpSize.y(), 1e-1f, 1e4f);

		m_rectShapeEbo = std::make_unique<detail::Buffer>(Buffer::Usage::StaticDraw);
		m_rectShapeEbo->bind(detail::Buffer::Target::ElementArrayBuffer);
		m_rectShapeEbo->setData(6 * sizeof(GLuint), m_rectShapeIndices);
		m_rectShapeEbo->unbind(detail::Buffer::Target::ElementArrayBuffer);

		setDefaultViewDistance(726.f);
		m_currentGlobal3DView = &m_views[m_defViewName];

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		m_initialized = true;
	}

	View Configurator::getView(const std::string & _name)
	{
		if (m_views.find(_name) != m_views.end())
			return m_views[_name];
		else
			return{ Mat4f::identity(), Vec3f::zero() };
	}

	void Configurator::setDefaultViewDistance(float _eyeZ)
	{
		Vec2f halfVp = Vec2f(m_vpSize) / 2.f;
		const Vec3f eye = Vec3f(Vec2f(m_vpSize) / 2.f, _eyeZ);
		m_views[m_defViewName] = { Mat4f::lookAt(eye, Vec3f(halfVp.x(), halfVp.y(), 0), Vec3f::up()), eye };
	}

	void Configurator::setGlobal3DView(const std::string & _name)
	{
		if (m_views.find(_name) != m_views.end())
			m_currentGlobal3DView = &m_views[_name];
	}

	void Configurator::setView(const std::string & _name, const Vec3f & _eye, const Vec3f & _center, const Vec3f & _up)
	{
		if (m_views.find(_name) != m_views.end())
			m_views[_name] = { Mat4f::lookAt(_eye, _center, _up), _eye };
	}

	void Configurator::addView(const std::string & _name, const Vec3f & _eye, const Vec3f & _center, const Vec3f & _up)
	{
		if (m_views.find(_name) == m_views.end())
			m_views[_name] = { Mat4f::lookAt(_eye, _center, _up), _eye };
	}

	void Configurator::setEnableDepthTest(bool _enable)
	{
		(m_depthTestEnabled = _enable) ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
	}

} // ns
