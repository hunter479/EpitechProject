/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** BONUS
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include "Core.hpp"

class Bonus {
	public:
		Bonus(irr::IrrlichtDevice *device, vector3df);
		~Bonus();

		IMeshSceneNode *getMesh(void) const { return _node; };
		const BONUS getBonus(void) { return _bonus; };

	private:
	    IMeshSceneNode *_node;
        BONUS _bonus;
};

#endif /* !BONUS_HPP_ */
