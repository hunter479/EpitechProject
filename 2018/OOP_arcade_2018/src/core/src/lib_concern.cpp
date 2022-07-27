/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** lib_concern
*/

#include <iostream>
#include "core.hpp"

void Core::swapLib()
{
    try {
        if (lib->so->getKey() == arcade::key::f2)
            changeLib(-1);
        if (lib->so->getKey() == arcade::key::f3)
            changeLib(1);
        if (lib->so->getKey() == arcade::key::f4)
            changeGame(-1);
        if (lib->so->getKey() == arcade::key::f5)
            changeGame(1);
    }
    catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            throw std::exception();
    }
}

void Core::changeGame(const int value)
{
    try {
        if (_game._list.size() <= 1)
            return;
        _game.changeLib(value);
        if (game) {
            delete this->game;
            this->game = NULL;
        }
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        throw std::exception();
    }
}

void Core::changeLib(const int value)
{
    try {
        if (_lib._list.size() <= 1)
            return;
        _lib.changeLib(value);
        delete lib;
        lib = new dll<IDisplayModule>(_lib.getCurrent(), "libEntry");
        lib->so->init(getState());
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        throw std::exception();
    }
}
