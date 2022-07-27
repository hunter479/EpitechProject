/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "TileMap.hpp"
#include "Core.hpp"
#include "IScene.hpp"
#include "IA.hpp"
#include "Character.hpp"
#include "MapGen.hpp"
#include "Menu.hpp"
#include "EventReceiver.hpp"
#include "SceneHandler.hpp"
#include "Save.hpp"
#include "Sound.hpp"

#define KB_ARROW InitKeys(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_RETURN)
#define KB_ZQSD InitKeys(KEY_KEY_Z, KEY_KEY_S, KEY_KEY_Q, KEY_KEY_D, KEY_SPACE)

class Game : public IScene
{
    public:
        Game(Core &core);
        ~Game();

        void            start(void);
        void            resetElapsedTime(void);

    /* Test */
        void            createMap(void);
        void            createPlayers(void);
        void            loadComponents(void);
        void            putBomb(Character *player);
        void            removeBomb(Character *);
        void            removeBombIA(IA *);
        struct s_save   savePlayers(Character *player);

        void            detectBombWithCubes(void);
        int             handlePlayers(std::list<struct s_save> &, int);
        int             handleIA(int, int);

        void            checkGameOver(void);

    private:
        /* Core class for window, display, etc... */
        Core    &_core;

        /* Just one player for the moment */
        std::list<Character *>      _players;
        std::vector<PlayerInfo *>   _playerType;
        std::list<struct s_save>   _playersInfo;

        /* list of ias */
        std::list<IA *>  _ais;

        /* Creation Of Game Clock */
        f32     _frameDeltaTime;
        u32     _now;
        u32     _then;

        int     _bombOnField;
        int     _countPlayers;
        TileMap _map;
        ICameraSceneNode*   _cam;
        std::vector<std::string> _mapVector;
        std::list<std::pair<Bomb *, u32>> _bomb;
        std::list<std::pair<Bonus *, vector3df>> _bonus;
        std::list<std::pair<irr::scene::IMeshSceneNode *, bool>> _list;
        Sound _sound;
		irr::gui::IGUIFont *_font;
        bool _isGameOver;
        std::string _winner;
        u32 _backToMenu;

    private: /* IScene */
        e_scene _currentScene;
        e_scene getScene() const {return (_currentScene);};
        void changeScene(const e_scene e) {_currentScene = e;};
};

#endif /* !GAME_HPP_ */
