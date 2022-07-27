/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** setName
*/

#include <string>
#include "classNcurses.hpp"

void popChar(WINDOW *_win, std::string &name)
{
    if (name.size() <= 0)
        return;
    clear();
    mvwprintw(_win, 8, 2, "name:");
    name.pop_back();
    mvwprintw(_win, 8, 8, name.c_str());
}

void NcursesLib::setName(std::string &name)
{
    mvwprintw(_win, 8, 2, "name:");
    if (input == -1)
        return;
    if (getKey() == arcade::key::enter)
        this->setState(arcade::state::Menu);
    else if (getKey() == arcade::key::backspace)
        popChar(_win, name);
    else if (getKey() == arcade::key::noaction ||
    (getKey() >= arcade::key::z && getKey() <= arcade::key::d)) {
        name.push_back((char)input);
        mvwprintw(_win, 8, 8, name.c_str());
    }
}