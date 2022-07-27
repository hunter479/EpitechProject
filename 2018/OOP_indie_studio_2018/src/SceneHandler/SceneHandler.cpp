/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** SceneHandler
*/

#include <exception>
#include "SceneHandler.hpp"
#include "Game.hpp"

SceneHandler::SceneHandler(Core &core) : _core(core)
{
    _currentScene = nullptr;
    _mapScene[IScene::MENU] = &SceneHandler::sceneMenu;
    _mapScene[IScene::GAME] = &SceneHandler::sceneGame;
    _mapScene[IScene::CREDITS] = &SceneHandler::sceneCredits;
    _mapScene[IScene::PRELAUNCH] = &SceneHandler::sceneCharacterSelection;
}

SceneHandler::~SceneHandler()
{
    if (_currentScene) {
        delete _currentScene;
    }
}

IScene *SceneHandler::sceneMenu()
{
    _currentScene = new Menu(_core);
    return (_currentScene);
}

IScene *SceneHandler::sceneGame()
{
    _currentScene = new Game(_core);
    return (_currentScene);
}

IScene *SceneHandler::sceneCharacterSelection()
{
    _currentScene = new CharacterSelection(_core);
    return (_currentScene);
}

IScene *SceneHandler::sceneCredits()
{
    _currentScene = new Credits(_core);
    return (_currentScene);
}

void SceneHandler::changeScene(const IScene::e_scene n)
{
    if (_currentScene) {
        delete _currentScene;
        _currentScene = nullptr;
    }
    for (auto i : _mapScene) {
        if (i.first == n) {
            _currentScene = (this->*(i.second))();
            return;
        }
    }
    throw std::invalid_argument("scene not recognized");
}

const IScene::e_scene SceneHandler::getScene() const
{
    return (_currentScene->getScene());
}