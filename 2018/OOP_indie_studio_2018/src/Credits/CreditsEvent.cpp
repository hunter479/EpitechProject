/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CreditsEvent
*/

#include <iostream>
#include "Menu.hpp"
#include "CreditsEvent.hpp"

CreditsEvent::CreditsEvent()
{
    _scene = IScene::CREDITS;
}

CreditsEvent::~CreditsEvent()
{
}

bool CreditsEvent::keyboard_event(const irr::SEvent &event)
{
    if (!event.KeyInput.PressedDown)
        return (false);
    if (event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE) {
        _scene = IScene::MENU;
        return (true);
    }
    return (false);
}

bool CreditsEvent::OnEvent(const irr::SEvent &event)
{
    irr::s32 id;

    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            return (keyboard_event(event));
    else if (event.EventType == irr::EET_GUI_EVENT) {
        id = event.GUIEvent.Caller->getID();
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
            if (id == IScene::MENU) {
                _scene = IScene::MENU;
                return (true);
            }
            return (false);
        }
    }
    return (false);
}

const IScene::e_scene CreditsEvent::getScene() const
{
    return (_scene);
}