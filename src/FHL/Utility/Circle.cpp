#include <FHL/Utility/Circle.h>

#include <vector>
#include <algorithm>

#include <FHL/Utility/Rect.h>

namespace fhl
{
	Projection Circle::project(const Vec2f & _axis) const
	{
		const float dot = m_center.dot(_axis);
		return{ dot - m_radius, dot + m_radius };
	}

	bool Circle::contains(const Vec2f & _point) const
	{
		return (_point - m_center).squaredLength() < m_radius * m_radius;
	}

	bool Circle::overlaps(const Circle & _other) const
	{
		const float maxDistance = m_radius + _other.getRadius();
		return (m_center - _other.getCenter()).squaredLength() < maxDistance * maxDistance;
	}

	bool Circle::overlaps(const Rect & _rect) const
	{
		/* Using separating axis theorem. Thanks goes to http://www.metanetsoftware.com/technique/tutorialA.html */
		std::vector<Vec2f> axes(std::begin(_rect.getAxes()), std::end(_rect.getAxes()));
		const auto closestVert = std::min_element(std::begin(_rect.getVerts()), std::end(_rect.getVerts()),
			[this](const Vec2f & a, const Vec2f & b) mutable { return (a - m_center).squaredLength() < (b - m_center).squaredLength(); }
		);
		axes.push_back((*closestVert - m_center).normalized());

		for (const Vec2f & axis : axes)
		{
			const Projection p1 = _rect.project(axis), p2 = this->project(axis);
			if (!p1.overlaps(p2) && !p2.overlaps(p1))
				return false;
		}
		return true;
	}

}