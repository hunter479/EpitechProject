/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** init
*/

#include <iostream>
#include "classPacman.hpp"

void classPacman::findPlayer()
{
    y = 0;
    x = 0;
    for(; y < (int)map->current.size() ; y++) {
        for(x = 0; map->current.at(y)[x] != '\0'; x++)
            if (map->current.at(y)[x] == 'P')
                return;
    }
    throw std::invalid_argument("No player found");
}

classPacman::classPacman()
{
    try {
        x = 0;
        y = 0;
        map = new mapHandle("src/game/pacman/map/map");
    } catch (const std::exception &e) {
        std::cerr << "failed in classPacman constructor\n";
        throw std::exception();
    }
}

classPacman::~classPacman()
{
    delete map;
}

extern "C"
{
    IGame *gameEntry() {
        return (new classPacman());
    }
}