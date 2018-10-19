#include "ScopeFrame.h"

#include "allegroImplem.h"

ScopeFrame::ScopeFrame(ALLEGRO_BITMAP* _img, int _takenX, int _takenY, int _width, int _height, int _angleOffset, int _pivotX, int _pivotY)
	:Frame(_img, _takenX, _takenY, _width, _height),
	m_angleOffset(_angleOffset), m_pivotX(_pivotX), m_pivotY(_pivotY)
{

}

ScopeFrame::ScopeFrame(ALLEGRO_BITMAP* _img, int _angleOffset, int _pivotX, int _pivotY)
	:Frame(_img), m_angleOffset(_angleOffset),
	m_pivotX(_pivotX), m_pivotY(_pivotY)
{

}

ScopeFrame::~ScopeFrame()
{

}

void ScopeFrame::draw(double destx, double desty, double orientation)
{
	al_draw_rotated_bitmap(this->sprite(), m_pivotX, m_pivotY,
		destx + m_pivotX, desty + m_pivotY, orientation + m_angleOffset, 0);
}
