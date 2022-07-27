/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

#include <vector>
#include <string>
#include "info.hpp"
#include "mapHandle.hpp"

class IGame
{
	public:
		typedef enum {
			UP,
			DOWN,
			LEFT,
			RIGHT,
			NONE,
		} e_direct;

		virtual ~IGame() {};

		virtual std::vector<std::string> getMap() const = 0;

		virtual int isPressed() = 0;
		virtual int outPressed() = 0;
		virtual int forwardPressed() = 0;
		virtual int backwardPressed() = 0;
		virtual int leftPressed() = 0;
		virtual int rightPressed() = 0;

		virtual void findPlayer() = 0;
		virtual void movePlayer() = 0;

		virtual int gameMechs() = 0;
		virtual mapHandle *mapEntry() = 0;
	protected:
	private:
};

#endif /* !IGAME_HPP_ */
