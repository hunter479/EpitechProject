/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** TileMap
*/

#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#ifndef WIN32
	#include <unistd.h>
#endif
#include <map>
#include "IA.hpp"
#include "irrlicht.h"
#include "Character.hpp"
#include "Bomb.hpp"
#include "IA.hpp"

#define SAFE "S"
#define GRASS "0"
#define WOOD "1"
#define WALL "X"

#define GRASS_PNG "media/walle.jpg"
#define WOOD_PNG "media/wood.png"
#define WALL_PNG "media/walleb.jpg"

class TileMap {
	public:
		TileMap(int tileSize, int width, int height, irr::IrrlichtDevice *device);
		~TileMap();

        void emptyMap();
        void deleteMap();
        void deleteBonuses();

        void load(std::vector<std::string> &map, std::list<std::pair<Bonus *, irr::core::vector3df>> *bonuses);
        std::vector<std::string> save();

        void setCollisions(irr::scene::IMeshSceneNode *node);
        void setPlayer(std::list<Character *> player);
        void setAis(std::list<IA *> ia);

        irr::core::vector3df getMiddleNode(irr::core::vector3df const &vec);
        const irr::core::vector3df getMiddle();
        const irr::core::vector3df getTileMiddle(irr::core::vector3df const &vec);
        std::pair<int, int> getNode(irr::core::vector3df const &vec);
        std::list<std::pair<irr::scene::IMeshSceneNode *, bool>> getObjects();

        TileMap &operator[](std::pair<int, int> pos);
        TileMap &operator+=(std::string const &cube);
        TileMap &operator--(int useless);
        std::vector<std::string> &getMapVector(void) { return _mapVector; };

	private:
        int _tileSize;
        int _mapWidth;
        int _mapHeight;

        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_sceneManager;

        std::map<std::pair<int, int>, std::list<irr::scene::IMeshSceneNode *>> _map;
        std::vector<std::string> _mapVector;

        std::list<Character *>_player;
        std::list<IA *>_ais;
        std::list<std::pair<Bonus *, irr::core::vector3df>> *_bonus;

        int _x;
        int _z;
};

#endif /* !TILEMAP_HPP_ */
