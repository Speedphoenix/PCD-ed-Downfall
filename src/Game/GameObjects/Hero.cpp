#include "Hero.h"
#include "GameContainer.h"
#include "CreateAnimator.h"

#include "game_config.h"
#include "debugNerrors.h"

using namespace std;

Hero::Hero(Player* _owner, double _x, double _y)
	:Moveable(heroSpeed, _x, _y, heroWidth, heroHeight),
	m_collider(this, m_transform), m_owner(_owner), m_dead(false)
{
	CreateAnimator::heroAnimator(m_animator);
}

Hero::~Hero()
{

}

void Hero::update()
{
	//double factor = GameContainer::deltaTime();

	if (m_collider.getCollidingList().size() != 0)
	{
		// do something
	}
	Moveable::update();
}

