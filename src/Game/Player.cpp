#include "Player.h"

#include "Hero.h"
#include "Events.h"

#include "game_config.h"

Player::Player()
	:m_hero(new Hero(this, 0, 0))
{

}

Player::~Player()
{
	if (m_hero != nullptr)
		m_hero->setToRemove();
}

void Player::update()
{

}

void Player::onKeyboardEvent(const KeyboardEvent& event)
{

}

void Player::onMouseEvent(const MouseEvent& event)
{
	if (m_hero && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		m_hero->setDest(event.x, event.y);
}

void Player::onTouchEvent(const TouchEvent& event)
{

}
