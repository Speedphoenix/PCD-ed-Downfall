#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct KeyboardEvent;
struct MouseEvent;
struct TouchEvent;

class Hero;

class Player
{
	protected:
		Hero *m_hero;
		//list or vector or map of little teleport thingies

	public:
		Player();
		virtual ~Player();

		virtual void update();

		virtual void onKeyboardEvent(const KeyboardEvent& event);
 		virtual void onMouseEvent(const MouseEvent& event);
		virtual void onTouchEvent(const TouchEvent& event);
};

#endif //PLAYER_H_INCLUDED
