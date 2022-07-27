/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "irrlicht.h"

#include "EventReceiver.hpp"
#include "PlayerInfo.hpp"
#include "Save.hpp"

#define STILE 10

#define UPLEFT vector3df(STILE * 12 + STILE, STILE / -2, STILE * 14 + STILE)
#define DOWNRIGHT vector3df(STILE, STILE / -2, STILE)
#define UPRIGHT vector3df(STILE * 12 + STILE, STILE / -2, STILE)
#define DOWNLEFT vector3df(STILE, STILE / -2, STILE * 14 + STILE)

enum BONUS {
    SPEED,
    POWER,
    BOMB
};

enum  E_LOAD {
    MAP,
    PLAYERS
};

class Core {
	public:
		Core();
		~Core();

        std::vector<std::string>    &loadInfoMap(void) { return (_save.getMap()); };
        std::list<struct s_save>           &loadInfoPlayers(void) { return (_save.getPlayers()); };
        IrrlichtDevice  *getDevice(void) { return _device; };
        ISceneManager   *getSmgr(void) { return _smgr; };
        IVideoDriver    *getDriver(void) { return _driver; };
        IGUIEnvironment *getGUI(void) { return _guienv; };
        EventReceiver   *_receiver;

        void    save(void) { _save.createFile(); };
        void    clearSave(void) { _save.clearAll(); };
        void    updateSave(const std::vector<std::string> &map, const std::list<struct s_save> &info);
        void    displaySave(void);
        void    setLoaded(const bool isLoaded) { _isLoaded = isLoaded; };
        bool    isLoaded(void) const { return _isLoaded; };
        bool    verifSaveFile(void) { return (_save.verifFile()); };
        void    setPlayerType(PlayerInfo *p) { _playerType.push_back(p); };
        std::vector<PlayerInfo *>   &getPlayerType(void) { return _playerType; };
        array<SJoystickInfo> &getJoytstickInfo(void) { return _joystickInfo; };
        bool    getJoystickState(void) { return _isController; };

        void                    bindMap(void);
        std::string             keysToString(bind_t keys);
        bind_t                  stringToKeys(std::string &keys);

    private:
        bool            _isLoaded;
        bool            _isController;

        Save            _save;
        IrrlichtDevice  *_device;
        IVideoDriver    *_driver;
        ISceneManager   *_smgr;
        IGUIEnvironment *_guienv;
        std::vector<PlayerInfo *>   _playerType;
        array<SJoystickInfo> _joystickInfo;
        std::map<int, EKEY_CODE>        _bindSoon;
};

#endif /* !CORE_HPP_ */
