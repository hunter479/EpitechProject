/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "Core.hpp"

class PowerUp {
	public:
		PowerUp(irr::IrrlichtDevice *device, vector3df, IMeshSceneNode *);
		~PowerUp();
};

#endif /* !POWERUP_HPP_ */
