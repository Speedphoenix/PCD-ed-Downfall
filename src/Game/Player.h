#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "game_config.h"

#include <vector>
#include <map>

struct KeyboardEvent;
struct MouseEvent;
struct TouchEvent;

class Teleporter;
class Hero;

class Player
{
	protected:
		Hero *m_hero;

		unsigned m_maxTeleps;
		unsigned m_lastAsked;
		std::vector<Teleporter *> m_teleporters;
		std::map<int, unsigned> m_keyToEvent;

	public:
		Player(int _maxTeleps);
		virtual ~Player();

		virtual void update();

		virtual void onKeyboardEvent(const KeyboardEvent& event);
 		virtual void onMouseEvent(const MouseEvent& event);
		virtual void onTouchEvent(const TouchEvent& event);

		virtual void teleportHero(Hero *who, Teleporter *where);

		virtual Hero *hero() { return m_hero; }
};

#endif //PLAYER_H_INCLUDED
