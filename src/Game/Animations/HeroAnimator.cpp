#include "HeroAnimator.h"

#include "SpritesContainer.h"
#include "AimedAnimation.h"

#include "allegroImplem.h"
#include "game_config.h"
#include "debugNerrors.h"

HeroAnimator::HeroAnimator(GameObject* attachTo)
	:Animator(attachTo, defaultIdleLapse, Walking, 0) 
{
	Transition newAnimKey;
	AimedAnimation *newAnim;
	SpritesContainer *sprites = SpritesContainer::instance();
	ALLEGRO_BITMAP *sheet = sprites->at(TEST_OLD_MONSTER);

	//these are more temporary and for testing than anything
	newAnimKey = Transition(Walking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 0, 0, heroWidth, heroHeight, 1);
	newAnim->addFrames(sheet, 5 * heroWidth, heroHeight, heroWidth, heroHeight, 1);
	newAnim->setLapse(defaultIdleLapse);
	m_animations[newAnimKey] = newAnim;
	
	newAnimKey = Transition(Walking, Anim::Active, false);
	newAnim = new AimedAnimation(sheet, 0, 0, heroWidth, heroHeight, 6);
	newAnim->setLapse(defaultActiveLapse);
	m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 5 * heroWidth, heroHeight, heroWidth, heroHeight, 1);
	newAnim->setLapse(defaultIdleLapse);
	m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Active, false);
	newAnim = new AimedAnimation(sheet, 0, heroHeight, heroWidth, heroHeight, 6);
	newAnim->setLapse(defaultActiveLapse);
	m_animations[newAnimKey] = newAnim;

	m_currState = Transition(Walking, Anim::Idle, false);
}

HeroAnimator::~HeroAnimator()
{

}
