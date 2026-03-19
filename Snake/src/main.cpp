#include <iostream>
#include <windows.h>
#include "Game.hpp"

int main()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	Game game;
	game.run();
}