#include "Hero.h"
#include "GameContainer.h"

#include "game_config.h"
#include "debugNerrors.h"

using namespace std;

Hero::Hero(Player* _owner, double _x, double _y)
	:GameObject(_x, _y, heroWidth, heroHeight), m_animator(this),
	m_collider(this, m_transform), m_owner(_owner),
	m_destination(_x + heroWidth / 2, _y + heroHeight / 2, 0, 0, false),
	m_speed(0), m_maxspeed(heroSpeed), m_dead(false)
{

}

Hero::~Hero()
{

}

void Hero::start()
{
	m_animator.launch();
}

void Hero::update()
{
	double factor = GameContainer::deltaTime();

	if (m_collider.getCollidingList().size() != 0)
	{
		// do something
	}

	if (!m_transform.hasSamePos(m_destination))
	{
		m_transform.headTowards(m_destination, m_maxspeed);
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

void Hero::draw()
{
	Drawable::draw(m_animator, m_transform);
}

void Hero::setDest(int x, int y)
{
	m_destination.setAbsPos(x, y);
	m_transform.headTowards(m_destination, m_maxspeed);
	m_animator.setDirection(m_transform);
}
