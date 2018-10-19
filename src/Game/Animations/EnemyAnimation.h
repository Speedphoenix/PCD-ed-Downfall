#ifndef ENEMYANIMATION_H_INCLUDED
# define ENEMYANIMATION_H_INCLUDED

# include "AimedAnimation.h"

struct ALLEGRO_BITMAP;
class Frame;

class EnemyAnimation : public AimedAnimation
{
	protected:
		Frame *m_scope;

	public:
		EnemyAnimation();
		EnemyAnimation(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h, int nb);
		~EnemyAnimation();

		virtual void createScope(ALLEGRO_BITMAP *img, double angleOffset = 0.0);
		virtual void createScope(ALLEGRO_BITMAP *img, int x, int y, int w, int h, double angleOffset = 0.0);

		virtual void draw(double destx, double desty, unsigned frameNumber);
};

#endif //ENEMYANIMATION_H_INCLUDED
