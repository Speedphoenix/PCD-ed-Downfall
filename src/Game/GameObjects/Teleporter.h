#ifndef TELEPORTER_H_INCLUDED
#define TELEPORTER_H_INCLUDED

#include "Moveable.h"

#include "Collider.h"
#include "game_config.h"

class Player;

class Teleporter : public Moveable
{
	friend class Player;
	friend class Hero;

	private:
		Collider m_collider;

		Player *m_owner;

	public:
		Teleporter(Player *_owner, double _x, double _y);
		virtual ~Teleporter();

		virtual Player *owner() { return m_owner; }
		virtual void setOwner(Player *val) { m_owner = val; }
};

#endif //TELEPORTER_H_INCLUDED
