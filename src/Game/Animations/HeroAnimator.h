#ifndef HEROANIMATOR_H_INCLUDED
#define HEROANIMATOR_H_INCLUDED

#include "Animator.h"

class HeroAnimator : public Animator
{
	public:
		HeroAnimator(GameObject* attachTo);
		virtual ~HeroAnimator();
};

#endif //HEROANIMATOR_H_INCLUDED

