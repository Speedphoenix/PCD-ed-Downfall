#include "Player.h"

#include "Hero.h"
#include "Events.h"
#include "Teleporter.h"
#include "TransformBase.h"

#include "allegroImplem.h"
#include "game_config.h"
#include "debugNerrors.h"

using namespace std;

Player::Player(int _maxTeleps)
	:m_hero(new Hero(this, 0, 0)), m_maxTeleps(_maxTeleps), m_lastAsked(0),
	m_teleporters(vector<Teleporter *>(_maxTeleps, nullptr)),
	m_keyToEvent(defaultKeys)
{
	m_teleporters.at(0) = new Teleporter(this, 100, 100);
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
	if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		unsigned choice;
		if (!(m_keyToEvent.count(event.keycode)))
			return;
		else
			choice = m_keyToEvent.at(event.keycode);
		if (choice < m_maxTeleps)
		{
			Teleporter *chosen;
			ALLEGRO_MOUSE_STATE retState;

			m_lastAsked = choice;
			chosen = m_teleporters.at(choice);
			if (chosen == nullptr)
				return;
			al_get_mouse_state(&retState);
			chosen->setDest(retState.x, retState.y);
		}
		else
		{
			switch (choice)
			{
				case AskTeleport:
					teleportHero(m_hero, m_teleporters.at(m_lastAsked));
					break;
				default:
					break;
			}
		}
	}
}

void Player::onMouseEvent(const MouseEvent& event)
{
	if (m_hero && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		m_hero->setDest(event.x, event.y);
}

void Player::onTouchEvent(const TouchEvent& event)
{

}


void Player::teleportHero(Hero *who, Teleporter *where)
{
	if (where == nullptr || who == nullptr)
		return;
	TransformBase::swapPos(who->transform(), where->transform());
	who->stopMoving();
	where->stopMoving();
}
