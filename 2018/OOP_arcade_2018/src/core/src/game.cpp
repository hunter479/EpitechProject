/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** game
*/

#include <iostream>
#include <unistd.h>
#include <algorithm>
#include "IDisplayModule.hpp"
#include "core.hpp"

void Core::loadGame()
{
    if (!game) {
        try {
            game = new dll<IGame>(_game.getCurrent(), "gameEntry");
            game->so->findPlayer();
        } catch (const std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            throw std::exception();
        }
        return;
    }
    try {
        if (lib->so->getKey() == arcade::key::enter) {
            game->so->mapEntry()->restoreSave();
            game->so->findPlayer();
        }
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        throw std::exception();
    }
}

void Core::gameInput()
{
    for (auto i : _inputGame) {
        if (i.first == lib->so->getKey()) {
            (game->so->*(i.second))();
            return;
        }
    }
}

void Core::doGame()
{
    try {
        if (lib->so->getState() != arcade::state::Game)
            return;
        loadGame();
        gameInput();
        game->so->gameMechs();
        if (lib->so->getKey() == arcade::key::backspace)
            lib->so->setState(arcade::state::Menu);
    } catch (const std::exception &e) {
        std::cerr << "doGame" << std::endl;
        throw std::exception();}
}

void Core::loop()
{
    try {
        lib->so->doEvent(this->username);
        if (lib->so->getState() != getState())
            setState(lib->so->getState());
        swapLib();
        doGame();
        lib->so->setKey(arcade::key::noaction);
        if (lib->so->getState() != arcade::state::Game)
            lib->so->draw(_game._list);
        else
            lib->so->draw(game->so->getMap());
        lib->so->display();
        lib->so->clean();
    } catch (const std::exception &e) {
        throw std::exception();
    }
}

void Core::launchGame()
{
    try {
        lib->so->init(getState());
        while (lib->so->isOpen() == true)
            loop();
    } catch (const std::exception &e) {
        std::cerr << "game\n";
        throw;
    };
}
