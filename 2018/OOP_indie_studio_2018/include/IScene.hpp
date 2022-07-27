/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "irrlicht.h"

struct SAppContext
{
	irr::IrrlichtDevice *device;
	irr::s32 counter;
};

class IScene {
	public:
    enum e_scene{
        MENU, GAME, QUIT, LOAD_GAME, CREDITS, PRELAUNCH, SAVE_QUIT, SAVE_MENU
    };
		virtual ~IScene() {};
        virtual e_scene getScene() const = 0;
	protected:
        virtual void changeScene(const e_scene) = 0;
	private:
};

#endif /* !ISCENE_HPP_ */
