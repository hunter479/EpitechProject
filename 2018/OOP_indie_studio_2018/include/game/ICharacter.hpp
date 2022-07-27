/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
# define ICHARACTER_HPP_

#include <list>
#include "Core.hpp"
#include "Bonus.hpp"
#include "Bomb.hpp"

#define TIME_TO_EXPLODE 3000

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

enum MOVE_DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

class ICharacter {
	public:
		virtual ~ICharacter() = default;

        virtual void        findPosition(void) = 0;
        virtual void        makeItMove(const f32, IAnimatedMeshSceneNode *mesh, core::vector3df & rot) = 0;
        virtual void        pickUpBonus(std::list<std::pair<Bonus *, vector3df>> &bonus, Core &core) = 0;

        virtual void        putBomb(u32, Core &) = 0;
        virtual void        removeBomb(u32, Core &) = 0;
        virtual void        bombAction(u32, Core &) = 0;
        virtual const bool  isPressed(const EKEY_CODE, Core &) = 0;

        virtual void        move(const f32, Core &) = 0;
        virtual void        joystick_update(Core &) = 0;
        virtual void        rotate(Core &) = 0;
        virtual void        detectBonus(std::list<std::pair<Bonus *, vector3df>> & bonus) = 0;
        virtual const bool  setRotation(Core &, const EKEY_CODE, const MOVE_DIRECTION) = 0;
        virtual const bool  detectCollision(Core &) = 0;

	protected:
	private:
};

#endif /* !ICHARACTER_HPP_ */
