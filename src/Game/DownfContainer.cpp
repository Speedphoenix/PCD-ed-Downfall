#include "DownfContainer.h"
#include "Events.h"
#include "Player.h"

#include "game_config.h"
#include "debugNerrors.h"

DownfContainer::DownfContainer(long _width, long _height)
	:GameContainer(), m_map(_width, _height), m_camera()
{

}

DownfContainer::~DownfContainer()
{
	for (auto& elem : m_players)
		delete elem;
}


void DownfContainer::start()
{
	GameContainer::start();
}

void DownfContainer::addPlayer(Player *who)
{
	if (who)
		m_players.push_back(who);
}

void DownfContainer::onKeyboardEvent(const KeyboardEvent& event)
{
	if (event.keycode == ALLEGRO_KEY_ESCAPE)
		m_finished = true;
	for (auto& elem : m_players)
		elem->onKeyboardEvent(event);
}

void DownfContainer::onMouseEvent(const MouseEvent& event)
{
	for (auto& elem : m_players)
		elem->onMouseEvent(event);
}

void DownfContainer::onTouchEvent(const TouchEvent& event)
{
	for (auto& elem : m_players)
		elem->onTouchEvent(event);
}


void DownfContainer::playerUpdate()
{
	//may move the camera here...

	for (auto& elem : m_players)
		elem->update();
}

