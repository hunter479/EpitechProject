/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** CLASSPACMAN
*/

#ifndef CLASSPACMAN_HPP_
    #define CLASSPACMAN_HPP_

#include <vector>
#include <string>
#include "IGameModule.hpp"

class classPacman : public IGame
{
    public:
        classPacman();
        virtual ~classPacman();

		int isPressed() {return (1);};
		int outPressed() {return (1);};
		int forwardPressed();
		int backwardPressed();
		int leftPressed();
		int rightPressed();

		mapHandle *mapEntry() {return (map);};
		std::vector<std::string> getMap() const {return (map->current);};

		void findPlayer();
		void movePlayer();

		int gameMechs();
    private:
		e_direct lastinput;
		mapHandle *map;
        int x;
        int y;
};

#endif /* !CLASSPACMAN_HPP_ */
