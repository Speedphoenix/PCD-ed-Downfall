#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include "GameObject.h"
#include "Drawable.h"

#include "Collider.h"
#include "HeroAnimator.h"
#include "TransformBase.h"

class Player;

class Hero : public GameObject, Drawable
{
	protected:
		//will use a normal Animator once they work properly
		HeroAnimator m_animator;

		Collider m_collider;

		Player *m_owner;

		TransformBase m_destination;

		double m_speed;
		double m_maxspeed;

		bool m_dead;

	public:
		Hero(Player* _owner, double _x, double _y);
		~Hero();

		virtual void start();
		virtual void update();

		virtual void draw();

		Player *owner() { return m_owner; }
		void setOwner(Player *val) { m_owner = val; }

		virtual void setDest(int x, int y);

		virtual void setDead(bool val = true) { m_dead = val; }
		virtual bool isDead() { return m_dead; }
};

#endif //HERO_H_INCLUDED
