/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** createWindow
*/

#include "classNcurses.hpp"

void NcursesLib::init(const arcade::state::state_t state)
{
    _run = true;
    _win = initscr();
    recupTitle();
    keypad(_win, true);
    curs_set(false);
    noecho();
    halfdelay(1);
    setState(state);
    setKey(arcade::key::noaction);
    setInput();
    input = 0;
}

void NcursesLib::display()
{
    if (getState() != arcade::state::Game)
        printTitle();
}

void NcursesLib::clean()
{
    refresh();
}

void NcursesLib::doEvent(std::string &name)
{
    assignKey();
    if (_key == arcade::key::escape) {
        _run = false;
        return;
    }
    if (this->getState() == arcade::state::Username)
        this->setName(name);
    else if (getState() == arcade::state::Menu &&
            getKey() == arcade::key::enter)
            setState(arcade::state::Game);
}

NcursesLib::~NcursesLib()
{
    endwin();
}

extern "C" {
    IDisplayModule *libEntry() {
        return (new NcursesLib);
    }
}