#ifndef ENEMY_H_INCLUDED
# define ENEMY_H_INCLUDED

# include "Moveable.h"

# include "Collider.h"

class Enemy : Moveable
{
	private:
		Collider m_collider;

	public:
		Enemy(double _x, double _y);
		virtual ~Enemy();

		
};

#endif //ENEMY_H_INCLUDED
