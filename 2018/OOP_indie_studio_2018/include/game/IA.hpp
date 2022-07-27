/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_

#include "Core.hpp"
#include "Bomb.hpp"
#include "Character.hpp"
#include "Bonus.hpp"
#include "irrlicht.h"
#include <string>

class IA {
	public:
		IA(const int, const irr::core::vector3df, const std::string &, Core &);
		~IA() {};

	public:
        bool            isObstacleAt(std::vector<std::string> &mapVector, vector3df vec);
        void            initMove(IAnimatedMeshSceneNode *mesh);
        void            moveUp(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            moveDown(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            moveLeft(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            moveRight(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);

        void            move(const f32, Core &, std::list<std::pair<Bomb *, u32>>, std::vector<std::string> &map);
        void            makeItMove(const f32, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            ghostMove(const f32 frameRate, IAnimatedMeshSceneNode *mesh, vector3df &rot);
        const f32       rotateAndSpeed(const f32, IAnimatedMeshSceneNode *, const vector3df);
        bool            isCollidingWithBomb(vector3df playerPos, std::list<std::pair<Bomb *, u32>> bomb);
        bool            isCollidingWithObstacle(vector3df playerPos, std::vector<std::string> &map);
        bool            detectBombExplosion(std::list<std::pair<Bomb *, u32>> _bomb, Core &core);

        const bool      detectCollision(std::list<std::pair<Bomb *, u32>>);

		void    		findPosition(void);
		void			setDirection(std::vector<std::string> &mapVector, Core & core);

        void            setAlive(bool isAlive) { _isAlive = isAlive; };
        bool            getAlive(void) { return _isAlive; };

        IAnimatedMeshSceneNode  *getIA(void) const { return _node; };
        const int       getId(void) const { return _id; };
        const int       getPower(void) const { return _power; };
        void            setBombLoad(int load) { _bombLoads += load; };

        const bool      bombAction(u32 now, Core &core);

        void    pickUpBonus(std::list<std::pair<Bonus *, vector3df>> & bonus, Core &core);
        void    whichBonus(Bonus *bonus);
        vector3df       getPlayerMiddleNode(const vector3df &vec);

	private:
		int 					_id;
		std::string				_asset;
		irr::core::vector3df	_positions;
		irr::core::vector3df	_ghostPosition;
		irr::core::vector3df	_nodePosition;

        irr::core::vector3df       _initialPos;
        bool            _tempoBomb;
        bool            _isMoving;
        bool            _tempoMove;

		MOVE_DIRECTION	_moveDirection;
		bool			_collide;

        int                     _bombLoads;        
        f32 _movementSpeed;
        int _power;
        bool			_intoBomb;

        vector3df _origin;

		irr::scene::IAnimatedMeshSceneNode *_node;
		irr::scene::IAnimatedMeshSceneNode *_ghost;
		irr::scene::IAnimatedMesh *_mesh;

        bool _nextToBox;

        bool                    _isAlive;
};

#endif /* !IA_HPP_ */
