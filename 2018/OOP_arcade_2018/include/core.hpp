/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include <vector>
#include <string>
#include <map>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "dll.hpp"
#include "parseDir.hpp"
#include "mapHandle.hpp"

class Core
{
    public:
        Core(const char *);
        ~Core();
        dll<IDisplayModule> *lib;
        dll<IGame> *game;
        parseDir _lib;
        parseDir _game;

        void setState(const arcade::state::state_t &e) {_state = e;};
        const arcade::state::state_t &getState() const {return (_state);};

        void launchGame();
    private:
        void gameInput();
        void changeLib(const int);
        void changeGame(const int);
        void loadGame();
        void swapLib();
        void doGame();
        void loop();
        void setupKeyGame();
    private:
        std::string username;
        arcade::state::state_t _state;
        std::map<arcade::key::key_t, int (IGame::*)(void)> _inputGame;
};

#endif /* !CORE_HPP_ */
