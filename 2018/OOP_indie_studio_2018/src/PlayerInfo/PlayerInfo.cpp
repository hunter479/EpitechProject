/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PlayerInfo
*/

#include "PlayerInfo.hpp"

PlayerInfo::PlayerInfo(const int i, const bool joystick, const std::string &path, irr::core::vector3df pos, std::vector<std::pair<playerM, bool>> &_taken) : _isTaken(_taken), _id(i), _pos(pos), _texturePath(path)
{
    _playerM.push_back(KEY1);
    _playerM.push_back(KEY2);
    _playerM.push_back(AI_BIND);
    if (joystick == true) {
        std::cout << "ACTIVATE JOYSTICK 1" << std::endl;
        _playerM.push_back(JOY1);
    }
    _playerM.push_back(NONE_BIND);
    _model[KEY1].assign(L"Keyboard1");
    _model[KEY2].assign(L"Keyboard2");
    _model[JOY1].assign(L"Joystick1");
    _model[AI_BIND].assign(L"IA");
    _model[NONE_BIND].assign(L"NONE");
    if (i == 1) {
        while (_isTaken.front().first != KEY1)
            std::rotate(_isTaken.rbegin(), _isTaken.rbegin() + 1, _isTaken.rend());
        _isTaken.front().second = true;
        while (getType() != KEY1)
            std::rotate(_playerM.rbegin(), _playerM.rbegin() + 1, _playerM.rend());
    } else if (i == 2) {
        while (_isTaken.front().first != KEY2)
            std::rotate(_isTaken.rbegin(), _isTaken.rbegin() + 1, _isTaken.rend());
        _isTaken.front().second = true;
        while (getType() != KEY2)
            std::rotate(_playerM.rbegin(), _playerM.rbegin() + 1, _playerM.rend());
    } else {
        while (getType() != AI_BIND)
            std::rotate(_playerM.rbegin(), _playerM.rbegin() + 1, _playerM.rend());
    }

}

PlayerInfo::~PlayerInfo()
{
}

void    PlayerInfo::bindMap(void)
{
    _bindSoon[38] = irr::EKEY_CODE::KEY_UP;
    _bindSoon[40] = irr::EKEY_CODE::KEY_DOWN;
    _bindSoon[37] = irr::EKEY_CODE::KEY_LEFT;
    _bindSoon[39] = irr::EKEY_CODE::KEY_RIGHT;
    _bindSoon[90] = irr::EKEY_CODE::KEY_KEY_Z;
    _bindSoon[83] = irr::EKEY_CODE::KEY_KEY_S;
    _bindSoon[81] = irr::EKEY_CODE::KEY_KEY_Q;
    _bindSoon[68] = irr::EKEY_CODE::KEY_KEY_D;
    _bindSoon[80] = irr::EKEY_CODE::KEY_KEY_P;
    _bindSoon[32] = irr::EKEY_CODE::KEY_SPACE;
    _bindSoon[13] = irr::EKEY_CODE::KEY_RETURN;
}

std::string     PlayerInfo::keysToString(bind_t keys)
{
    std::string to_save;

    to_save.append(std::to_string(keys.ai));
    to_save.append(" " + std::to_string(keys.none));
    to_save.append(" " + std::to_string(keys.up));
    to_save.append(" " + std::to_string(keys.down));
    to_save.append(" " + std::to_string(keys.left));
    to_save.append(" " + std::to_string(keys.right));
    to_save.append(" " + std::to_string(keys.drop));
    return to_save;
}

bind_t  PlayerInfo::stringToKeys(std::string &keys)
{
    bind_t to_ret;
    std::string test;
    std::stringstream ssin(keys);

    ssin >> test;
    to_ret.ai = stoi(test);
    ssin >> test;
    to_ret.none = stoi(test);
    ssin >> test;
    to_ret.up = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.down = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.left = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.right = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.drop = _bindSoon[std::stoi(test)];
    return to_ret;
}

const bind_t    PlayerInfo::InitKeys(bool joy, bool none, bool ai, const irr::EKEY_CODE up, const irr::EKEY_CODE down, const irr::EKEY_CODE left, const irr::EKEY_CODE right, const irr::EKEY_CODE drop)
{
    bind_t  keys;

    keys.joystick = joy;
    keys.none = none;
    keys.ai = ai;
    keys.up = up;
    keys.down = down;
    keys.left = left;
    keys.right = right;
    keys.drop = drop;
    return keys;
}

bind_t    PlayerInfo::getBind(void)
{
    if (_playerM.front() == AI_BIND)
        return InitKeys(false, false, true, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P);
    else if (_playerM.front() == KEY1)
        return InitKeys(false, false, false, irr::EKEY_CODE::KEY_KEY_Z, irr::EKEY_CODE::KEY_KEY_S, irr::EKEY_CODE::KEY_KEY_Q, irr::EKEY_CODE::KEY_KEY_D, irr::EKEY_CODE::KEY_SPACE);
    else if (_playerM.front() == KEY2)
        return InitKeys(false, false, false, irr::EKEY_CODE::KEY_UP, irr::EKEY_CODE::KEY_DOWN, irr::EKEY_CODE::KEY_LEFT, irr::EKEY_CODE::KEY_RIGHT, irr::EKEY_CODE::KEY_RETURN);
    else if (_playerM.front() == JOY1)
        return InitKeys(true, false, false, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P);
    else if (_playerM.front() == NONE_BIND)
        return InitKeys(false, true, false, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P);
    return InitKeys(false, true, false, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P, irr::EKEY_CODE::KEY_KEY_P);
}

void PlayerInfo::changePlayerL()
{
    while (_isTaken.front().first != getType())
        std::rotate(_isTaken.rbegin(), _isTaken.rbegin() + 1, _isTaken.rend());
    _isTaken.front().second = false;
    std::rotate(_isTaken.rbegin(), _isTaken.rbegin() + 1, _isTaken.rend());
    while (_isTaken.front().second != false) {
        std::rotate(_isTaken.rbegin(), _isTaken.rbegin() + 1, _isTaken.rend());
    }
    _isTaken.front().second = true;
    while (getType() != _isTaken.front().first)
        std::rotate(_playerM.rbegin(), _playerM.rbegin() + 1, _playerM.rend());
    if (_isTaken.front().first == AI_BIND || _isTaken.front().first == NONE_BIND)
        _isTaken.front().second = false;
}

void PlayerInfo::changePlayerR()
{
    while (_isTaken.front().first != getType())
        std::rotate(_isTaken.begin(), _isTaken.begin() + 1, _isTaken.end());
    _isTaken.front().second = false;
    std::rotate(_isTaken.begin(), _isTaken.begin() + 1, _isTaken.end());
    while (_isTaken.front().second != false) {
        std::rotate(_isTaken.begin(), _isTaken.begin() + 1, _isTaken.end());
    }
    _isTaken.front().second = true;
    while (getType() != _isTaken.front().first)
        std::rotate(_playerM.begin(), _playerM.begin() + 1, _playerM.end());
    if (_isTaken.front().first == AI_BIND || _isTaken.front().first == NONE_BIND)
        _isTaken.front().second = false;
}

const std::wstring PlayerInfo::getModel()
{
    for (auto i : _model) {
        if (getType() == i.first)
            return (i.second.c_str());
    }
    return (L"NULL");
}