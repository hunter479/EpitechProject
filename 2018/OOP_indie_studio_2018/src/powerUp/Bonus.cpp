/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bonus
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>
#include "Core.hpp"
#include "Bonus.hpp"
#include "BombUp.hpp"
#include "SpeedUp.hpp"
#include "PowerUp.hpp"

Bonus::Bonus(irr::IrrlichtDevice *device, vector3df pos)
{
    int myRandom;

    myRandom = rand() % 3 + 1;
    if (myRandom == 1) {
        IMesh *mesh = device->getSceneManager()->getMesh("./media/powerUpSpeed.obj");
        _node = device->getSceneManager()->addMeshSceneNode(mesh);
        SpeedUp speedup(device, pos, _node);
        _bonus = SPEED;
    }
    else if (myRandom == 2) {
        IMesh *mesh = device->getSceneManager()->getMesh("./media/powerUpBomb.obj");
        _node = device->getSceneManager()->addMeshSceneNode(mesh);
        BombUp bombup(device, pos, _node);
        _bonus = BOMB;
    } else if (myRandom == 3) {
        IMesh *mesh = device->getSceneManager()->getMesh("./media/powerUpP.obj");
        _node = device->getSceneManager()->addMeshSceneNode(mesh);
        PowerUp power(device, pos, _node);
        _bonus = POWER;
    }
}

Bonus::~Bonus()
{
}
