/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PlayerInfo
*/

#ifndef PLAYERINFO_HPP_
#define PLAYERINFO_HPP_

#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "irrlicht.h"

enum playerM {
    AI_BIND = 0,
    KEY1 = 1,
    KEY2 = 2,
    JOY1 = 3,
    NONE_BIND = 4
};

typedef struct  s_bind
{
    bool    ai;
    bool    none;
    bool    joystick;
    irr::EKEY_CODE up;
    irr::EKEY_CODE down;
    irr::EKEY_CODE left;
    irr::EKEY_CODE right;
    irr::EKEY_CODE drop;
}   bind_t;

class PlayerInfo {

	public:
        PlayerInfo(const int i, const bool joystick, const std::string &path, irr::core::vector3df pos, std::vector<std::pair<playerM, bool>> &_taken);
        ~PlayerInfo();
        void                    changePlayerL();
        void                    changePlayerR();
        const std::wstring      getModel();
        const int               getId(void) const { return _id; };
        irr::core::vector3df    getPos(void) const { return _pos; };
        bind_t                  getBind(void);
        const playerM           getType(void) const { return _playerM.front(); };
        const std::string &     getTexturePath(void) { return _texturePath; };
        const bind_t            InitKeys(bool, bool, bool, const irr::EKEY_CODE up, const irr::EKEY_CODE down, const irr::EKEY_CODE left, const irr::EKEY_CODE right, const irr::EKEY_CODE drop);

        void                    bindMap(void);
        std::string             keysToString(bind_t keys);
        bind_t                  stringToKeys(std::string &keys);

	private:
        std::vector<std::pair<playerM, bool>>         &_isTaken;
        std::map<playerM, std::wstring> _model;
        std::vector<playerM>            _playerM;
        int                             _id;
        irr::core::vector3df            _pos;
        std::string                     _texturePath;
        std::map<int, irr::EKEY_CODE>        _bindSoon;
};

#endif /* !PLAYERINFO_HPP_ */
