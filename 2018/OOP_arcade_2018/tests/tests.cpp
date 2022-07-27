/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** tests1
*/


#include <criterion/criterion.h>
#include "info.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include "mapHandle.hpp"
#include "parseDir.hpp"
#include "dll.hpp"
#include "core.hpp"

Test(check, mapHandle)
{
	mapHandle *map = new mapHandle("./src/game/nibbler/map/map");

	cr_assert(map->current.at(0).compare("********************") == 0);
	cr_assert(map->current.at(1).compare("*                  *") == 0);
	cr_assert(map->current.at(2).compare("*                  *") == 0);
	cr_assert(map->current.at(3).compare("*                  *") == 0);
	cr_assert(map->current.at(4).compare("*     P            *") == 0);
	cr_assert(map->current.at(5).compare("*                  *") == 0);
	cr_assert(map->current.at(6).compare("*                  *") == 0);
	cr_assert(map->current.at(7).compare("*                  *") == 0);
	cr_assert(map->current.at(8).compare("*                  *") == 0);
	cr_assert(map->current.at(9).compare("*                  *") == 0);
	cr_assert(map->current.at(10).compare("*                  *") == 0);
	cr_assert(map->current.at(11).compare("*                  *") == 0);
	cr_assert(map->current.at(12).compare("*                  *") == 0);
	cr_assert(map->current.at(13).compare("*                  *") == 0);
	cr_assert(map->current.at(14).compare("********************") == 0);
	delete map;
}

Test(check, parseDir)
{
	parseDir *lib = new parseDir();
	parseDir *game = new parseDir();

	lib->parseLib("lib/lib_arcade_ncurses.so");
	cr_assert(lib->_list.at(0).compare("lib/lib_arcade_ncurses.so") == 0);
	cr_assert(lib->_list.at(1).compare("lib/lib_arcade_sfml.so") == 0);
	game->parseGame();
	cr_assert(game->_list.at(0).compare("lib/lib_arcade_nibbler.so"));
	cr_assert(game->_list.at(1).compare("lib/lib_arcade_pacman.so"));
}

Test(check, dll_Lib)
{
	dll<IDisplayModule> *lib = new dll<IDisplayModule>("lib/lib_arcade_sfml.so", "libEntry");

	cr_assert(lib->so != NULL);
	lib->so->setState(arcade::state::Username);
	cr_assert(lib->so->getState() == arcade::state::Username);
	cr_assert(lib->so->getKey() == arcade::key::noaction);
	lib->so->setKey(arcade::key::z);
	cr_assert(lib->so->getKey() == arcade::key::z);
	delete lib;
}

Test(check, dll_game)
{
	dll<IGame> *lib = new dll<IGame>("games/lib_arcade_nibbler.so", "gameEntry");

	cr_assert(lib->so != NULL);
	delete lib;
}

Test(check, core)
{
	Core core("lib/lib_arcade_sfml.so");

	cr_assert(core.game == NULL);
	cr_assert(core.lib->so != NULL);
	cr_assert(core._lib._list.size() != 0);
	cr_assert(core._game._list.size() != 0);
	cr_assert(core.getState() == arcade::state::Username);
}