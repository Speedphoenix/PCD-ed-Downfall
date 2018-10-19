#ifndef GAME_CONFIG_H_INCLUDED
#define GAME_CONFIG_H_INCLUDED

#include "config.h"
#include <map>

/********************************************************************
							TESTING PURPOSES
********************************************************************/

#define TEST_OLD_MONSTER_FILE RES_DIR "Test/monsterv2.png"
#define TEST_OLD_MONSTER "Test-monsterv2"

#define TEST_OLD_TILES_FILE RES_DIR "Test/testTiles.png"
#define TEST_OLD_TILES "testTiles"

#define TEST_TELEPORT_THINGY_FILE RES_DIR "Test/Teleport_Thingy.png"
#define TEST_TELEPORT_THINGY "Teleport-Thingy"

# define TEST_ENEMY_SCOPE_FILE RES_DIR "Test/EnemyScope.png"
# define TEST_ENEMY_SCOPE "EnemyScope"

/********************************************************************
								MAP
********************************************************************/

///the side of a (square) tile
const int tileSide = 75;

///converts coordinates in number of tiles
inline int tileCoord(int pixels)
{
	return ((int) (pixels / tileSide));
}


/********************************************************************
								INPUT
********************************************************************/

enum InputChoice : unsigned {
	//the first 10 cases are reserved for the ten teleporters
	AskTeleport = 10
};

extern std::map<int, unsigned> defaultKeys;


/********************************************************************
								UNITS
********************************************************************/

const double defaultIdleLapse = 0.3; // in seconds
const double defaultActiveLapse = 0.1; // in seconds

const double heroSpeed = 15;
const double heroWidth = 75;
const double heroHeight = 75;

const double enemyWidth = 75;
const double enemyHeight = 75;

const double teleporterSpeed = 38;
const double teleporterWidth = 20;
const double teleporterHeight = 20;


#endif // GAME_CONFIG_H_INCLUDED
