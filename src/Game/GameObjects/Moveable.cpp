#include "Moveable.h"
#include "GameContainer.h"

#include "game_config.h"
#include "debugNerrors.h"

Moveable::Moveable(const Transform& source, double _maxSpeed, bool _isfixed)
	:GameObject(source), m_animator(this),
	m_destination(source.centerAbsX(), source.centerAbsY(), 0, 0, false),
	m_speed(0.0), m_maxSpeed(_maxSpeed), m_isFixed(_isfixed)
{

}

Moveable::Moveable(double _maxSpeed, double _x, double _y, double _w, double _h, bool _isfixed)
	:GameObject(_x, _y, _w, _h, 0.0), m_animator(this),
	m_destination(m_transform.centerAbsX(), m_transform.centerAbsY(), 0, 0, false),
	m_speed(0.0), m_maxSpeed(_maxSpeed), m_isFixed(_isfixed)
{

}

Moveable::Moveable(GameObject *_parent, double _maxSpeed, bool _dependsOnParent, double _x, double _y, double _w, double _h, bool _isfixed)
	:GameObject(_parent, _dependsOnParent, _x, _y, _w, _h), m_animator(this),
	m_destination(m_transform.centerAbsX(), m_transform.centerAbsY(), 0, 0, false),
	m_speed(0.0), m_maxSpeed(_maxSpeed), m_isFixed(_isfixed)
{

}

Moveable::~Moveable()
{

}

void Moveable::start()
{
	m_animator.launch();
}

void Moveable::update()
{
	double factor = GameContainer::deltaTime();

	if (m_isFixed)
		return;
	if (!m_transform.hasSamePos(m_destination))
	{
		m_transform.headTowards(m_destination, m_maxSpeed);
		m_transform.setMoving(true);
		m_speed = m_transform.speed();

		// false to 'not play once' (keep looping)
		// using anims here
		m_animator.makeActive(false);
	}
	else
	{
		m_transform.setMoving(false);
		m_speed = 0.0;
		// using anims here
		m_animator.makeIdle();
	}
	if (m_transform.isMoving())
	{
		m_transform.translate(factor);
	}
}

void Moveable::setDest(int x, int y)
{
	if (m_isFixed)
		return;
	if (m_destination.hasSamePos(x, y))
		return;
	m_destination.setAbsPos(x, y);
	m_transform.headTowards(m_destination, m_maxSpeed);
	m_animator.setDirection(m_transform);
}

void Moveable::stopMoving()
{
	m_destination.setAbsPos(m_transform.centerAbsX(), m_transform.centerAbsY());
}

void Moveable::setMaxSpeed(double val)
{
	if (val < 0.0)
		m_maxSpeed = 0.0;
	else
		m_maxSpeed = val;
}

