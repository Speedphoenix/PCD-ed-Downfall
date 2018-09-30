#ifndef GAME_CONFIG_H_INCLUDED
#define GAME_CONFIG_H_INCLUDED

#include "config.h"

/********************************************************************
							TESTING PURPOSES
********************************************************************/

#define TEST_OLD_MONSTER_FILE RES_DIR "Test/monsterv2.png"
#define TEST_OLD_MONSTER "Test-monsterv2"

#define TEST_OLD_TILES_FILE "Test/testTiles.png"
#define TEST_OLD_TILES "testTiles"


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
								UNITS
********************************************************************/

const double defaultUnitSpeed = 30;

const double defaultIdleLapse = 0.3; // in seconds
const double defaultActiveLapse = 0.1; // in seconds




#endif // GAME_CONFIG_H_INCLUDED
