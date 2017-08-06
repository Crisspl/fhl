#include <FHL/Graphics/Transformable3D.h>

#include <FHL/Graphics/Configurator.h>

namespace fhl
{

	Transformable3D::Transformable3D() :
		m_rotation(),
		m_position(0.f),
		m_scale(1.f),
		m_transformChanged(true)
	{}

	Transformable3D & Transformable3D::rotate(float _angle, const Vec3f & _axis)
	{
		m_transformChanged = true;
		m_rotation = Quaternion(_axis, _angle) * m_rotation;
		return *this;
	}

	Transformable3D & Transformable3D::setRotation(float _angle, const Vec3f & _axis)
	{
		m_transformChanged = true;
		m_rotation = Quaternion(_axis, _angle);
		return *this;
	}

	Transformable3D & Transformable3D::move(const Vec3f & _offset)
	{
		return setPosition(m_position + _offset);
	}

	Transformable3D & Transformable3D::setPosition(const Vec3f & _pos)
	{
		m_transformChanged = true;
		m_position = _pos;
		return *this;
	}

	Transformable3D & Transformable3D::scale(const Vec3f & _scale)
	{
		return setScale(m_scale * _scale);
	}

	Transformable3D & Transformable3D::setScale(const Vec3f & _scale)
	{
		m_transformChanged = true;
		m_scale = _scale;
		return *this;
	}

	Transformable3D & Transformable3D::setOrigin(Vec3f _origin)
	{
		m_transformChanged = true;
		m_origin = _origin;
		return *this;
	}

	Mat4f Transformable3D::getTransform() const
	{
		if (m_transformChanged)
		{
			m_transformChanged = false;
			return
				m_transform = createTransformMatrix(m_position, m_scale, m_origin, m_rotation);
		}
		else return m_transform;
	}

	Mat4f Transformable3D::getMVP() const
	{
		return
			Configurator::projection() *
			getView().matrix *
			getTransform();
	}

	RenderMatrices Transformable3D::getMatrices() const
	{
		return{ getTransform(), getTransform().inverted(), getMVP(), getView().cameraPos };
	}

	RenderMatrices Transformable3D::createRenderMatrices(const Vec3f & _pos, const Vec3f & _scale, const Vec3f & _origin, const Quaternion & _rotation, const View & _view)
	{
		const Mat4f transform = createTransformMatrix(_pos, _scale, _origin, _rotation);
		return
		{
			 transform,
			 transform.inverted(),
			 Configurator::projection() * _view.matrix * transform,
			 _view.cameraPos
		};
	}

	RenderMatrices Transformable3D::calcModifiedRenderMatrices(const Vec3f & _mvOffset, const Vec3f & _scaleMlt, const Quaternion & _rotation) const
	{
		return createRenderMatrices(m_position + _mvOffset, m_scale * _scaleMlt, m_origin, _rotation * m_rotation, getView());
	}

	Mat4f Transformable3D::createTransformMatrix(const Vec3f & _pos, const Vec3f & _scale, const Vec3f & _origin, const Quaternion & _rotation)
	{
		return
			Mat4f::scale(_scale) *
			Mat4f::translate(_origin + (_pos - _origin) / _scale) *
			_rotation.toMat4f() *
			Mat4f::translate(-_origin);
	}

	View Transformable3D::getView() const
	{
		return m_viewName.empty() ? Configurator::global3DView() : Configurator::getView(m_viewName);
	}

}
