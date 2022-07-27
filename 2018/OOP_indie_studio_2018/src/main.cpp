/*
** EPITECH PROJECT, 2019
** irrlicht
** File description:
** Game
*/

#include <time.h>
#include <random>
#include "SceneHandler.hpp"
#include "MapGen.hpp"
#include "Game.hpp"

#ifdef WIN32
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(void)
{
	std::srand(time(NULL));
    Core core = Core();
    SceneHandler *game_scene = new SceneHandler(core);
    IScene::e_scene current = IScene::MENU;

    while(current != IScene::QUIT && core.getDevice()->run()) {
        try {
            game_scene->changeScene(current);
            current = game_scene->getScene();
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }
    delete game_scene;
    core.getDevice()->drop();
	return (0);
}
