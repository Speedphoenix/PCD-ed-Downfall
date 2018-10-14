#ifndef S2BCONTAINER_H
#define S2BCONTAINER_H

#include "GameContainer.h"
#include "GameMap.h"
#include "Camera.h"

#include <vector>

struct KeyboardEvent;
struct MouseEvent;
struct TouchEvent;

class Player;

/** The game container specific to Stiek2Bellum */
class DownfContainer : public GameContainer
{
	protected:
		GameMap m_map;
		Camera m_camera;

		std::vector<Player *> m_players;

		virtual void onKeyboardEvent(const KeyboardEvent& event);
		virtual void onMouseEvent(const MouseEvent& event);
		virtual void onTouchEvent(const TouchEvent& event);

		virtual void playerUpdate();

	public:
		DownfContainer(long _width, long _height);
		virtual ~DownfContainer();

		//no copy ctor or assignment
		DownfContainer(const DownfContainer&) = delete;
		DownfContainer& operator=(const DownfContainer&) = delete;

		virtual void start();

		virtual void addPlayer(Player *who);

		virtual double maximumX() { return mapWidth(); }
		virtual double maximumY() { return mapHeight(); }

		void setMap(const GameMap& val) { m_map = val; }

		long mapWidth() const { return m_map.widthpx(); }
		long mapHeight() const { return m_map.heightpx(); }

		long mapTileWidth() const { return m_map.widthtl(); }
		long mapTileHeight() const { return m_map.heighttl(); }

};

#endif // S2BCONTAINER_H
