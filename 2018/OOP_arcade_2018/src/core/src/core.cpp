/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** sym
*/

#include <string>
#include <iostream>
#include "core.hpp"

void Core::setupKeyGame()
{
    _inputGame[arcade::key::z] = &IGame::forwardPressed;
    _inputGame[arcade::key::s] = &IGame::backwardPressed;
    _inputGame[arcade::key::q] = &IGame::leftPressed;
    _inputGame[arcade::key::d] = &IGame::rightPressed;
}

Core::Core(const char *path)
{
    try {
        _lib.parseLib(path);
        _game.parseGame();
        lib = new dll<IDisplayModule>(path, "libEntry");
        game = NULL;
        _state = arcade::state::Username;
        setupKeyGame();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        throw std::exception();
    }
}

Core::~Core()
{
    if (lib)
        delete lib;
    if (game)
        delete game;
}
