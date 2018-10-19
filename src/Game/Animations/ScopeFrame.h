#ifndef SCOPEFRAME_H_INCLUDED
# define SCOPEFRAME_H_INCLUDED

# include "Frame.h"

class ScopeFrame : public Frame
{
	protected:
		double m_angleOffset;
		int m_pivotX;
		int m_pivotY;
	
	public:
		ScopeFrame(ALLEGRO_BITMAP* _img, int _takenX, int _takenY, int _width, int _height, int _angleOffset = 0, int _pivotX = 0, int _pivotY = 0);
		ScopeFrame(ALLEGRO_BITMAP* _img, int _angleOffset = 0, int _pivotX = 0, int _pivotY = 0);
		virtual ~ScopeFrame();

		virtual void draw(double destx, double desty, double orientation);
};

#endif //SCOPEFRAME_H_INCLUDED
