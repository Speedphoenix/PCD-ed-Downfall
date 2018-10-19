#include "Enemy.h"

#include "CreateAnimator.h"
#include "game_config.h"

Enemy::Enemy(double _x, double _y)
	:Moveable(0.0, _x, _y, enemyWidth, enemyHeight, true),
	m_collider(this, m_transform)
{
	CreateAnimator::enemAnimator(m_animator);

}

Enemy::~Enemy()
{

}
