#ifndef MOVEABLE8H8INCLUDED
#define MOVEABLE8H8INCLUDED

#include "GameObject.h"

#include "TransformBase.h"
#include "Animator.h"

class Player;

class Moveable : public GameObject
{
	protected:
		Animator m_animator;
		TransformBase m_destination;

		double m_speed;
		double m_maxSpeed;
		bool m_isFixed;

	public:
		Moveable(const Transform& source, double _maxSpeed, bool _isfixed = false);
		Moveable(double _maxSpeed = 0, double _x = 0, double _y = 0, double _w = 0, double _h = 0, bool _isfixed = false);
		Moveable(GameObject *_parent, double _maxSpeed, bool _dependsOnParent = true, double _x = 0, double _y = 0, double _w = 0, double _h = 0, bool _isfixed = false);
		~Moveable();

		virtual void start();
		virtual void update();

		virtual void setDest(int x, int y);
		virtual void stopMoving();

		virtual double maxSpeed() { return m_maxSpeed; }
		virtual void setMaxSpeed(double val);
		virtual double currSpeed() { return m_speed; }

		virtual bool isFixed() { return m_isFixed; }
};

#endif //MOVEABLE8H8INCLUDED

