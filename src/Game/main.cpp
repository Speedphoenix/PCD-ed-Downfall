#include "allegroImplem.h"
#include "colors.h"
#include "game_config.h"
#include "debugNerrors.h"

#include "SpritesContainer.h"
#include "DownfContainer.h"
#include "Player.h"
#include "Enemy.h"


using namespace std;

namespace test {
	void makeTest();
	void maketestSprites();
}

int main(int argc, char* argv[])
{
	try
	{
		initAlleg(ALLEGRO_WINDOWED, defaultDispWidth, defaultDispHeight); // or pass ALLEGRO_FULLSCREEN_WINDOW as a param
	}
	catch (const char* e)
	{
		ES(e)
	}

	SpritesContainer* sprites = new SpritesContainer();
	DownfContainer* theGame = new DownfContainer(60, 45);
	Player *mainPlayer;

	test::maketestSprites();
	mainPlayer = new Player(9);
	theGame->addPlayer(mainPlayer);
	theGame->start();

	double elapsed = 0.02;

	while(!theGame->shouldStop())
	{
		theGame->update(elapsed*10);

		al_rest(elapsed);
	}

	delete theGame;
	delete sprites;

	closeAlleg();
	return 0;
}


namespace test {

void makeTest()
{
	new Enemy(300, 300);
}

///FOR TESTING PURPOSES
void maketestSprites()
{
	//the default flags, just in case it was changed somewhere
	al_set_new_bitmap_flags(ALLEGRO_CONVERT_BITMAP);

	SpritesContainer::instance()->addSprite(TEST_OLD_MONSTER, al_load_bitmap(TEST_OLD_MONSTER_FILE));
	SpritesContainer::instance()->addSprite(TEST_OLD_TILES, al_load_bitmap(TEST_OLD_TILES_FILE));
	SpritesContainer::instance()->addSprite(TEST_TELEPORT_THINGY, al_load_bitmap(TEST_TELEPORT_THINGY_FILE));
	SpritesContainer::instance()->addSprite(TEST_ENEMY_SCOPE, al_load_bitmap(TEST_ENEMY_SCOPE_FILE));
}

}
