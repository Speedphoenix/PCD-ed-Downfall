#include "game_config.h"

std::map<int, unsigned> defaultKeys = {
	{ALLEGRO_KEY_A, 0}, {ALLEGRO_KEY_Z, 1}, {ALLEGRO_KEY_E, 2},
	{ALLEGRO_KEY_R, 3}, {ALLEGRO_KEY_T, 4}, {ALLEGRO_KEY_Y, 5},
	{ALLEGRO_KEY_U, 6}, {ALLEGRO_KEY_I, 7}, {ALLEGRO_KEY_O, 8},
	{ALLEGRO_KEY_P, 9},
	{ALLEGRO_KEY_SPACE, InputChoice::AskTeleport}};
