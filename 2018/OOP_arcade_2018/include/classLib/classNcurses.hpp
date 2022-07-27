/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** classNcurses
*/

#ifndef CLASSNCURSES_HPP_
    #define CLASSNCURSES_HPP_

#include <ncurses.h>
#include <map>
#include "IDisplayModule.hpp"

class NcursesLib : public IDisplayModule
{
    public:
        NcursesLib() {};
        NcursesLib(const NcursesLib &);
        virtual ~NcursesLib();
        const NcursesLib &operator=(const NcursesLib &);

        void doEvent(std::string &);
        void clean();
        bool isOpen() const {return (_run);};
        void display();
        void init(const arcade::state::state_t);

        void draw(const std::vector<std::string> &);
        void setState(const arcade::state::state_t &e);
        const arcade::state::state_t &getState() const {return (_state);};
        const arcade::key::key_t &getKey() const {return (_key);};
        void setKey(const arcade::key::key_t e) {_key = e;};
        void setName(std::string &);

    private:
        void recupTitle();
        void printTitle();
        void assignKey();
        void setInput();
        void drawMenu(const std::vector<std::string> &);
        void drawMap(const std::vector<std::string> &);

    private:
        bool _run = false;
        std::string title;
        WINDOW *_win;
        int input;
        arcade::state::state_t _state;
        arcade::key::key_t _key;
        std::map<int, arcade::key::key_t> _inputMap;
};

#endif /* !CLASSNCURSES_HPP_ */