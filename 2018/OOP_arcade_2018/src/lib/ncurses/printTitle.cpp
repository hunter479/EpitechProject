/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** printTitle
*/

#include <fstream>
#include "classNcurses.hpp"

void NcursesLib::recupTitle()
{
    std::ifstream myfile;

    myfile.open("src/lib/ncurses/title");
    if (myfile.is_open()) {
        title.assign(std::istreambuf_iterator<char>(myfile.rdbuf()), std::istreambuf_iterator<char>());
        myfile.close();
    } else {
        title.assign("ERROR");
    }
}

void NcursesLib::printTitle()
{
    mvwprintw(_win, 0, 0, title.c_str());
}