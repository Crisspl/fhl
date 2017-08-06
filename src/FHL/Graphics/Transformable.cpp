#include <FHL/Graphics/Transformable.h>

#include <cmath>

#include <FHL/Graphics/Configurator.h>

namespace fhl
{

	Transformable::Transformable() :
		m_rotation(0.f),
		m_position(0.f, 0.f),
		m_scale(1.f, 1.f),
		m_transformChanged(true),
		m_mvpChanged(true)
	{
	}

	Transformable & Transformable::rotate(float _angle)
	{
		return setRotation(m_rotation + _angle);
	}

	Transformable & Transformable::setRotation(float _angle)
	{
		m_transformChanged = m_mvpChanged = true;
		m_rotation = std::fmod(_angle, 360.f);
		return *this;
	}

	Transformable & Transformable::move(const Vec2f & _offset)
	{
		return setPosition(m_position + _offset);
	}

	Transformable & Transformable::setPosition(const Vec2f & _pos)
	{
		m_transformChanged = m_mvpChanged = true;
		m_position = _pos;
		return *this;
	}

	Transformable & Transformable::scale(const Vec2f & _scale)
	{
		return setScale(m_scale * _scale);
	}

	Transformable & Transformable::setScale(const Vec2f & _scale)
	{
		m_transformChanged = m_mvpChanged = true;
		m_scale = _scale;
		return *this;
	}

	Transformable & Transformable::setOrigin(const Vec2f & _origin)
	{
		m_transformChanged = m_mvpChanged = true;
		m_origin = _origin;
		return *this;
	}

	TransformData Transformable::getTransformData() const
	{
		return{
					m_position - m_origin,
					m_scale,
					m_origin,
					m_rotation
		};
	}

	Mat4f Transformable::getTransform() const
	{
		if (m_transformChanged)
		{
			m_transformChanged = false;
			return
				m_transform = createTransformMatrix(m_position, m_scale, m_origin, m_rotation);
		}
		else return m_transform;
	}

	Mat4f Transformable::getMVP() const
	{
		if (m_mvpChanged)
		{
			m_mvpChanged = false;
			return
				m_mvp =
				Configurator::projection() *
				Configurator::view() *
				getTransform();
		}
		else return m_mvp;
	}

	RenderMatrices Transformable::getMatrices() const
	{
		return{ getTransform(), Mat4f(), getMVP(), Configurator::cameraPos() };
	}

	RenderMatrices Transformable::createRenderMatrices(const Vec2f & _pos, const Vec2f & _scale, const Vec2f & _origin, float _angle)
	{
		const Mat4f transform = createTransformMatrix(_pos, _scale, _origin, _angle);
		return
		{
			 transform,
			 Mat4f(),
			 Configurator::projection() * Configurator::view() * transform,
			 Configurator::cameraPos()
		};
	}

	RenderMatrices Transformable::calcModifiedRenderMatrices(const Vec2f & _mvOffset, const Vec2f & _scaleMlt, float _angle) const
	{
		return createRenderMatrices(m_position + _mvOffset, m_scale * _scaleMlt, m_origin, m_rotation + _angle);
	}

	Mat4f Transformable::createTransformMatrix(const Vec2f & _pos, const Vec2f & _scale, const Vec2f & _origin, float _angle)
	{
		return
			Mat4f::scale(Vec3f(_scale, 1)) *
			Mat4f::translate(Vec3f(_origin, 0) + Vec3f(_pos - _origin, 0) / Vec3f(_scale, 1)) *
			Mat4f::rotate(_angle, Vec3f::back()) *
			Mat4f::translate(Vec3f(-_origin, 0));
	}

} // ns
