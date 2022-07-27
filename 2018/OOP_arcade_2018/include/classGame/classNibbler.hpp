/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** classNibbler
*/

#ifndef CLASSNIBBLER_HPP_
    #define CLASSNIBBLER_HPP_

#include <vector>
#include <string>
#include "IGameModule.hpp"

class classNibbler : public IGame
{
    public:
        classNibbler();
        virtual ~classNibbler();

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

#endif /* !CLASSNIBBLER_HPP_ */
