/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** game
*/

#include "classNibbler.hpp"

int classNibbler::gameMechs()
{
    if (lastinput == UP)
        forwardPressed();
    if (lastinput == DOWN)
        backwardPressed();
    if (lastinput == LEFT)
        leftPressed();
    if (lastinput == RIGHT)
        rightPressed();
    return (0);
}