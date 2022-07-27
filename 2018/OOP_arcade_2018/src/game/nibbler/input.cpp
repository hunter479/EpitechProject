/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** input
*/

#include "classNibbler.hpp"

void classNibbler::movePlayer()
{
    map->current.at(y)[x] = 'P';
}

int classNibbler::forwardPressed()
{
    if (map->current.at(y - 1)[x] == '*')
        return (1);
    map->current.at(y)[x] = ' ';
    y -= 1;
    lastinput = UP;
    movePlayer();
    return (0);
}

int classNibbler::backwardPressed()
{
    if (map->current.at(y + 1)[x] == '*')
        return (1);
    map->current.at(y)[x] = ' ';
    y += 1;
    lastinput = DOWN;
    movePlayer();
    return (0);
}

int classNibbler::leftPressed()
{
    if (map->current.at(y)[x - 1] == '*')
        return (1);
    map->current.at(y)[x] = ' ';
    x -= 1;
    lastinput = LEFT;
    movePlayer();
    return (0);
}

int classNibbler::rightPressed()
{
    if (map->current.at(y)[x + 1] == '*')
        return (1);
    map->current.at(y)[x] = ' ';
    x += 1;
    lastinput = RIGHT;
    movePlayer();
    return (0);
}