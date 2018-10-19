#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include "Moveable.h"

#include "Collider.h"

class Player;

class Hero : public Moveable
{
	friend class Player;
	friend class Teleporter;

	protected:
		Collider m_collider;

		Player *m_owner;

		bool m_dead;

	public:
		Hero(Player* _owner, double _x, double _y);
		~Hero();

		virtual void update();

		Player *owner() { return m_owner; }
		void setOwner(Player *val) { m_owner = val; }

		virtual void setDead(bool val = true) { m_dead = val; }
		virtual bool isDead() { return m_dead; }
};

#endif //HERO_H_INCLUDED
