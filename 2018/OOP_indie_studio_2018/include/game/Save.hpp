/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <list>
#include <vector>
#include <string>

#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

struct s_save {
        int         id;
        int         nbPlayers;
        int         isPlayer;
        int         bomb_power;
        int         speed;
        int         nb_bombs;
        std::string     texturePath;
        std::string     keys;
        vector3df   pos;
};

class Save {
	public:
		Save();
		~Save();

        void            clearAll(void);
        vector3df       getVectorPos(std::string &vec);
        void            cleanSave(void);
        void            createFile(void);
        void            saveMap(const std::vector<std::string> &map);
        void            saveCharacters(const std::list<struct s_save> &info);
        void            display(void);
        bool            verifFile(void);
        bool            setInfoMap(std::ifstream &myfile);
        bool            setInfoPlayer(std::ifstream &myfile);

        std::vector<std::string>        &getMap(void) { return _map; };
        std::list<struct s_save>        &getPlayers(void) { return _players; };

	private:
        int     _nbPlayers;

        std::vector<std::string> _map;
        std::list<struct s_save> _players;
};

#endif /* !SAVE_HPP_ */
