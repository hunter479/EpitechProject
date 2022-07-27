/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventReceiver
*/

#ifndef EVENTRECEIVER_HPP_
#define EVENTRECEIVER_HPP_

#include <iostream>
#include "PauseMenu.hpp"
#include "IScene.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class EventReceiver : public IEventReceiver
{
	public:
		EventReceiver(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver);
		~EventReceiver();

		virtual bool OnEvent(const SEvent& event);
		virtual bool IsKeyDown(EKEY_CODE keyCode) const;

		const SEvent::SJoystickEvent &GetJoystickState(void) const;
	private:
		bool KeyIsDown[KEY_KEY_CODES_COUNT];
		SEvent::SJoystickEvent JoystickState;

		irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_driver;
	 /* IScene */
	private:
		IScene::e_scene _scene;
	public:
		IScene::e_scene getScene() const {return (_scene);};
		void changeScene(const IScene::e_scene e) {_scene = e;};
};

#endif /* !EVENTRECEIVER_HPP_ */
