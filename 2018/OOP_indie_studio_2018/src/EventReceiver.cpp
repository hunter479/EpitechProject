/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** EventReceiver
*/

#include "EventReceiver.hpp"

EventReceiver::EventReceiver(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver)
{
	_device = device;
	_driver = driver;
    _scene = IScene::GAME;
    for (int i = 0; i < KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

EventReceiver::~EventReceiver()
{
}

bool EventReceiver::OnEvent(const SEvent &event)
{
	PauseMenu *tmp = nullptr;
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE && event.KeyInput.PressedDown) {
			tmp = new PauseMenu(_device, _driver);
			if (tmp->getStatus() == PauseMenuEvent::MENU)
				_scene = IScene::SAVE_MENU;
			if (tmp->getStatus() == PauseMenuEvent::QUIT)
				_scene = IScene::SAVE_QUIT;
			delete tmp;
			return (true);
		}
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		return (true);
	}
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
		&& event.JoystickEvent.Joystick == 0)
		JoystickState = event.JoystickEvent;
	return false;
}

bool EventReceiver::IsKeyDown(EKEY_CODE keyCode) const
{
	return KeyIsDown[keyCode];
}

const SEvent::SJoystickEvent &EventReceiver::GetJoystickState(void) const
{
	return JoystickState;
}
