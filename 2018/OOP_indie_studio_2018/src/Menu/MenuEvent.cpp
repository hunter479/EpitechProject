/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuEvent
*/

#include <iostream>
#include "Menu.hpp"
#include "MenuEvent.hpp"

MenuEvent::MenuEvent(SAppContext &context, Core &core) : _core(core), _context(context)
{
    _scene = IScene::MENU;
}

MenuEvent::~MenuEvent()
{
}

bool MenuEvent::button_event(irr::s32 id, irr::gui::IGUIEnvironment *env)
{
    if (id == IScene::QUIT) {
        _scene = IScene::QUIT;
        return (true);
    }
    if (id == IScene::CREDITS) {
        _scene = IScene::CREDITS;
        return (true);
    }
    if (id == IScene::LOAD_GAME) {
        _scene = IScene::GAME;
        if (_core.verifSaveFile() == true) {
            _core.setLoaded(true);
        }
        return true;
    }
    if (id == Menu::PRELAUNCH) {
        _core.setLoaded(false);
        _scene = IScene::PRELAUNCH;
        return (true);
    }
    return (false);
}

bool MenuEvent::keyboard_event(const irr::SEvent &event)
{
    if (!event.KeyInput.PressedDown)
        return (false);
    if (event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE) {
        _scene = IScene::QUIT;
        return (true);
    }
    return (false);
}

bool MenuEvent::OnEvent(const irr::SEvent &event)
{
    irr::s32 id;
    irr::gui::IGUIEnvironment *env = nullptr;

    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            return (keyboard_event(event));
    else if (event.EventType == irr::EET_GUI_EVENT) {
        env = _context.device->getGUIEnvironment();
        id = event.GUIEvent.Caller->getID();
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            return (button_event(id, env));
    }
    return (false);
}

const IScene::e_scene MenuEvent::getScene() const
{
    return (_scene);
}