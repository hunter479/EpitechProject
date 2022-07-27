/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** inPut
*/

#include "classNcurses.hpp"

void NcursesLib::setInput()
{
    _inputMap[266] = arcade::key::f2;
    _inputMap[267] = arcade::key::f3;
    _inputMap[268] = arcade::key::f4;
    _inputMap[269] = arcade::key::f5;
    _inputMap['\n'] = arcade::key::enter;
    _inputMap[263] = arcade::key::backspace;
    _inputMap[27] = arcade::key::escape;
    _inputMap['z'] = arcade::key::z;
    _inputMap['q'] = arcade::key::q;
    _inputMap['s'] = arcade::key::s;
    _inputMap['d'] = arcade::key::d;
}

void NcursesLib::setState(const arcade::state::state_t &state)
{
	_state = state;
	clear();
}

#include <unistd.h>

void NcursesLib::assignKey()
{
    input = getch();

    if (input == -1)
        return;
    for (auto i : _inputMap) {
        if (input == i.first) {
            setKey(i.second);
            return;
        }
    }
}
