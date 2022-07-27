/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PauseMenuEvent
*/

#include "PauseMenuEvent.hpp"

PauseMenuEvent::PauseMenuEvent()
{
    _current = RUN;
}

PauseMenuEvent::~PauseMenuEvent()
{
}

bool PauseMenuEvent::button_event(irr::s32 id)
{
    if (id == QUIT) {
        _current = QUIT;
        return (true);
    }
    if (id == RESUME) {
        _current = RESUME;
        return (true);
    }
    if (id == MENU) {
        _current = MENU;
        return (true);
    }
    return (false);
}

bool PauseMenuEvent::keyboard_event(const irr::SEvent &event)
{
    if (!event.KeyInput.PressedDown)
        return (false);
    if (event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE) {
        _current = RESUME;
        return (true);
    }
    return (false);
}

bool PauseMenuEvent::OnEvent(const irr::SEvent &event)
{
    irr::s32 id;

    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        return ((keyboard_event(event) == true) ? true : false);
    else if (event.EventType == irr::EET_GUI_EVENT) {
        id = event.GUIEvent.Caller->getID();
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            return ((button_event(id) == true) ? true : false);
    }
    return (false);
}

const PauseMenuEvent::status PauseMenuEvent::getStatus() const
{
    return (_current);
}