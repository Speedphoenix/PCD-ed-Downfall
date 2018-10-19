#include "CreateAnimator.h"

#include "Animator.h"
#include "SpritesContainer.h"
#include "AimedAnimation.h"
#include "EnemyAnimation.h"

#include "allegroImplem.h"
#include "game_config.h"
#include "debugNerrors.h"
#include "basic_ops.h"

void CreateAnimator::heroAnimator(Animator& what)
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
	what.m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Walking, Anim::Active, false);
	newAnim = new AimedAnimation(sheet, 0, 0, heroWidth, heroHeight, 6);
	newAnim->setLapse(defaultActiveLapse);
	what.m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 5 * heroWidth, heroHeight, heroWidth, heroHeight, 1);
	newAnim->setLapse(defaultIdleLapse);
	what.m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Active, false);
	newAnim = new AimedAnimation(sheet, 0, heroHeight, heroWidth, heroHeight, 6);
	newAnim->setLapse(defaultActiveLapse);
	what.m_animations[newAnimKey] = newAnim;

	what.m_currState = Transition(Walking, Anim::Idle, false);
}

void CreateAnimator::telepAnimator(Animator& what)
{
	Transition newAnimKey;
	AimedAnimation *newAnim;
	SpritesContainer *sprites = SpritesContainer::instance();
	ALLEGRO_BITMAP *sheet = sprites->at(TEST_TELEPORT_THINGY);

	newAnimKey = Transition(Walking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 0, 0, teleporterWidth, teleporterHeight, 1);
	newAnim->setLapse(defaultIdleLapse);
	what.m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Walking, Anim::Active, false);
	newAnim = new AimedAnimation(sheet, 0, 0, teleporterWidth, teleporterHeight, 1);
	newAnim->setLapse(defaultActiveLapse);
	what.m_animations[newAnimKey] = newAnim;

	what.m_currState = Transition(Walking, Anim::Idle, false);
}

void CreateAnimator::enemAnimator(Animator& what)
{
	Transition newAnimKey;
	EnemyAnimation *newAnim;
	SpritesContainer *sprites = SpritesContainer::instance();
	ALLEGRO_BITMAP *sheet = sprites->at(TEST_OLD_TILES);

	newAnimKey = Transition(Walking, Anim::Idle, false);
	newAnim = new EnemyAnimation(sheet, 2 * enemyWidth, 0, enemyWidth, enemyHeight, 1);
	newAnim->createScope(sprites->at(TEST_ENEMY_SCOPE), M_PI_4);
	newAnim->setLapse(defaultIdleLapse);
	what.m_animations[newAnimKey] = newAnim;

	what.m_currState = Transition(Walking, Anim::Idle, false);
}
