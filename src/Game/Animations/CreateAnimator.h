#ifndef CREATEANIMATOR_H_INCLUDED
#define CREATEANIMATOR_H_INCLUDED

/*
 * this is a provisory class to assemble concrete animators
*/

class Animator;

class CreateAnimator
{
	public:
		static void heroAnimator(Animator& what);
		static void telepAnimator(Animator& what);
		static void enemAnimator(Animator& what);
};

#endif //CREATEANIMATOR_H_INCLUDED
