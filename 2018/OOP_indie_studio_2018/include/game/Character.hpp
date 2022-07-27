/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacter.hpp"

enum    E_TYPE {
        GHOST,
        PLAYER
};

class Character // : public ICharacter
{
        public:
	Character(const int, bind_t keys, vector3df pos, const std::string & sprite, Core &core);
        ~Character() {};

        // trash
        void            pickUpBonus(std::list<std::pair<Bonus *, vector3df>> &bonus, Core &core);

        void            findPosition(void);
        void            rotate(Core & core);
        bool            isObstacleAt(std::vector<std::string> &mapVector, vector3df vec);
        const bool      setRotation(Core &, const EKEY_CODE, const MOVE_DIRECTION);
        void            joystick_update(Core &core);
        void            move(const f32, Core &, std::list<std::pair<Bomb *, u32>>, std::vector<std::string> &map);
        void            makeItMove(const f32, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            ghostMove(const f32 frameRate, IAnimatedMeshSceneNode *mesh, vector3df &rot);
        const f32       rotateAndSpeed(const f32, IAnimatedMeshSceneNode *, const vector3df);
        bool            isCollidingWithBomb(vector3df playerPos, std::list<std::pair<Bomb *, u32>> bomb);
        bool            isCollidingWithObstacle(vector3df playerPos, std::vector<std::string> &map);

        void            initMove(IAnimatedMeshSceneNode *mesh);
        void            moveUp(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            moveDown(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            moveLeft(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);
        void            moveRight(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb);

        const bool      bombAction(u32, Core &);
        void            detectBonus(std::list<std::pair<Bonus *, vector3df>> & bonus);

        const bool      isPressed(const EKEY_CODE, Core &core);

        const bool      detectCollision(std::list<std::pair<Bomb *, u32>>);
        IAnimatedMeshSceneNode  *getPlayer(void) const { return _node; };

        void            setAlive(bool isAlive) { _isAlive = isAlive; };
        bool            getAlive(void) { return _isAlive; };
        const vector3df getPos(void) const { return _nodePosition; };
        const int       getPower(void) const { return _power; };
        const f32       getSpeed(void) const { return _movementSpeed; };
        const int       getId(void) const { return _id; };
        void            setBombLoad(int load) { _bombLoads += load; };
        const int       getBombLoad(void) const { return _bombLoads; };
        void            setIntoBomb(const bool state) { _intoBomb = state; };
        const bool      isIntoBomb(void) const { return _intoBomb; };
        bool            detectBombExplosion(std::list<std::pair<Bomb *, u32>> bomb, Core &);
        void            loadCharac(struct s_save info);
        const bool      getTempoBomb(void) const { return _tempoBomb; };
        void            setTempoBomb(const bool tempo) { _tempoBomb = tempo; };
        void            whichBonus(Bonus *);
        const std::string       getTexturePath(void) { return _texturePath;};
        bind_t                  getBind(void) { return _keys; };
        void            setCharacterRunning(Core &);
        bool            controllerUp(Core &, const MOVE_DIRECTION);
        bool            controllerDown(Core &, const MOVE_DIRECTION);
        bool            controllerLeft(Core &, const MOVE_DIRECTION);
        bool            controllerRight(Core &, const MOVE_DIRECTION);
        vector3df       getPlayerMiddleNode(const vector3df &vec);

	private:
        int             _id;
        bool            _collide;
        bool            _intoBomb;
        bool            _tempoBomb;
        bool            _tempoMove;
        bool            _isPlayer;
        bool            _isMoving;
        vector3df       _initialPos;
        bool            _speedBuffering;

        /* Character */
        int                     _countSpeedUp;
        IAnimatedMeshSceneNode  *_node;
        IAnimatedMeshSceneNode  *_ghost;
        core::vector3df         _nodePosition;
        core::vector3df         _ghostPosition;
        f32                     _movementSpeed;
        int                     _bombLoads;
        int                     _power;
        std::string             _texturePath;
        IAnimatedMesh*          _mesh;

        const bind_t            _keys;
        MOVE_DIRECTION          _moveDirection;

        SEvent::SJoystickEvent _joystickData;
        f32 _moveHorizontal;
        f32 _moveVertical;
        bool                    _isAlive;

        // BOMB
};

#endif /* !CHARACTER_HPP_ */
