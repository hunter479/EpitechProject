/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CharacterSelectionEvent
*/

#include <iostream>
#include "CharacterSelection.hpp"
#include "CharacterSelectionEvent.hpp"

CharacterSelectionEvent::CharacterSelectionEvent(const bool joy, Core &core) : _core(core)
{
    _scene = IScene::PRELAUNCH;
    _isTaken.push_back(std::make_pair(KEY1, false));
    _isTaken.push_back(std::make_pair(KEY2, false));
    _isTaken.at(0).second;
    if (joy == true)
        _isTaken.push_back(std::make_pair(JOY1, false));
    _isTaken.push_back(std::make_pair(AI_BIND, false));
    _isTaken.push_back(std::make_pair(NONE_BIND, false));
    p1 = new PlayerInfo(1, joy, "./media/bomberman_red.png", DOWNRIGHT, _isTaken);
    p2 = new PlayerInfo(2, joy, "./media/bomberman_blue.png", DOWNLEFT, _isTaken);
    p3 = new PlayerInfo(3, joy, "./media/bomberman_green.png", UPLEFT, _isTaken);
    p4 = new PlayerInfo(4, joy, "./media/bomberman_pink.png", UPRIGHT, _isTaken);
    _moveL[L1] = p1;
    _moveL[L2] = p2;
    _moveL[L3] = p3;
    _moveL[L4] = p4;
    _moveR[R1] = p1;
    _moveR[R2] = p2;
    _moveR[R3] = p3;
    _moveR[R4] = p4;
}

CharacterSelectionEvent::~CharacterSelectionEvent()
{
}

bool CharacterSelectionEvent::playerButton(irr::s32 id)
{
    for (auto i :_moveL) {
        if (id == i.first) {
            i.second->changePlayerL();
            return (true);
        }
    }
    for (auto i :_moveR) {
        if (id == i.first) {
            i.second->changePlayerR();
            return (true);
        }
    }
    return (false);
}

bool CharacterSelectionEvent::button_event(irr::s32 id)
{
    _core.getPlayerType().clear();
    _core.setPlayerType(p1);
    _core.setPlayerType(p2);
    _core.setPlayerType(p3);
    _core.setPlayerType(p4);
    if (id == IScene::GAME) {
        _scene = IScene::GAME;
        return (true);
    }
    return (playerButton(id));
}

bool CharacterSelectionEvent::keyboard_event(const irr::SEvent &event)
{
    if (!event.KeyInput.PressedDown)
        return (false);
    if (event.KeyInput.Key == irr::EKEY_CODE::KEY_ESCAPE) {
        _scene = IScene::MENU;
        return (true);
    }
    return (false);
}

bool CharacterSelectionEvent::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            return (keyboard_event(event));
    else if (event.EventType == irr::EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == EGET_BUTTON_CLICKED)
            return (button_event(event.GUIEvent.Caller->getID()));
    }
    return (false);
}

const IScene::e_scene CharacterSelectionEvent::getScene() const
{
    return (_scene);
}