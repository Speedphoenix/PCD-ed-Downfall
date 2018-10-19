#include "EnemyAnimation.h"

#include "ScopeFrame.h"
#include "Frame.h"

EnemyAnimation::EnemyAnimation()
	:AimedAnimation(), m_scope(nullptr)
{

}

EnemyAnimation::EnemyAnimation(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h, int nb)
	:AimedAnimation(sheet, x, y, w, h, nb), m_scope(nullptr)
{

}

EnemyAnimation::~EnemyAnimation()
{

}

void EnemyAnimation::createScope(ALLEGRO_BITMAP *img, double angleOffset)
{
	if (m_scope != nullptr)
		delete m_scope;
	m_scope = new ScopeFrame(img, angleOffset, 0, 0);
}

void EnemyAnimation::createScope(ALLEGRO_BITMAP *img, int x, int y, int w, int h, double angleOffset)
{
	if (m_scope != nullptr)
		delete m_scope;
	m_scope = new ScopeFrame(img, x, y, w, h, angleOffset, 0, 0);
}

void EnemyAnimation::draw(double destx, double desty, unsigned frameNumber)
{
	Frame *currFrame = this->getFrame(frameNumber);
	m_scope->draw(destx + (currFrame->width() / 2),
		desty + (currFrame->height() / 2), m_aimedDir);
	currFrame->draw(destx, desty, m_aimedDir);
}
