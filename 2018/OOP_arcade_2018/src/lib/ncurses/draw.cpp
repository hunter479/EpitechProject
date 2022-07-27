/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** draw
*/

#include "classNcurses.hpp"

void NcursesLib::drawMenu(const std::vector<std::string> &list)
{
    size_t i = 0;
    int y = 14;

    mvprintw(8, 2, "f2/f3 = change lib");
    mvprintw(9, 2, "f4/f5 = change game");
    mvprintw(10, 2, "enter = restart game");
    mvprintw(11, 2, "esc = quit");
    mvprintw(13, 2, "games:");
    while (list.size() > i) {
        mvprintw(y, 2, list.at(i).c_str());
        y += 1;
        i++;
    }
}

void NcursesLib::drawMap(const std::vector<std::string> &map)
{
    size_t i = 0;
    int y = 25;

    while (map.size() > i) {
        mvprintw(y, 50, map.at(i).c_str());
        y += 1;
        i++;
    }
}

void NcursesLib::draw(const std::vector<std::string> &list)
{
    if (getState() == arcade::state::Username)
        return;
    if (getState() == arcade::state::Menu)
        drawMenu(list);
    if (getState() == arcade::state::Game)
        drawMap(list);
}