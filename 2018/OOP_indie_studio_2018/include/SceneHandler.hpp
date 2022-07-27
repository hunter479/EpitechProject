/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** SceneHandler
*/

#ifndef SCENEHANDLER_HPP_
#define SCENEHANDLER_HPP_

#include <map>
#include "Core.hpp"
#include "Menu.hpp"
#include "Credits.hpp"
#include "CharacterSelection.hpp"

class SceneHandler {
	public:
        SceneHandler(Core &core);
		~SceneHandler();

        void changeScene(const IScene::e_scene);
        const IScene::e_scene getScene() const;
	protected:
        std::map<Menu::e_scene, IScene *(SceneHandler::*)(void)> _mapScene;
	private:
        Core    &_core;
        IScene *_currentScene;
        IScene *sceneMenu();
        IScene *sceneCharacterSelection();
        IScene *sceneCredits();
        IScene *sceneGame();
};

#endif /* !SceneHandler_HPP_ */
