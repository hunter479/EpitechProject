/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include <iostream>
#include <vector>
#include "Bomb.hpp"
#include "Character.hpp"
#include "EventReceiver.hpp"
#include "Core.hpp"
#include "PowerUp.hpp"
#include "SpeedUp.hpp"
#include "Bonus.hpp"

Character::Character(const int id, bind_t keys, vector3df pos, const std::string & path, Core &core) : _id(id), _collide(false), _movementSpeed(STILE * 2), _bombLoads(1), _power(STILE), _keys(keys), _moveDirection(NONE)
{
    _texturePath = path;
    _tempoBomb = false;
    _tempoMove = false;
    _speedBuffering = false;
    _isMoving = false;
    _intoBomb = false;
    _isPlayer = false;
    _isAlive = true;
    _countSpeedUp = 0;
	_mesh = core.getSmgr()->getMesh("./media/lego/bomberman_stand.b3d");
	_node = core.getSmgr()->addAnimatedMeshSceneNode(_mesh);
	_ghost = core.getSmgr()->addAnimatedMeshSceneNode(_mesh);
    _moveHorizontal = 0;
    _moveVertical = 0;
	if (_node) {
		_node->setScale(core::vector3df(3 * STILE / 5, 3 * STILE / 5, 3 * STILE / 5));
		_node->setPosition(pos);
		_node->setMaterialTexture(0, core.getDriver()->getTexture(_texturePath.c_str()));
		_ghost->setScale(core::vector3df(0, 0, 0));
		_ghost->setPosition(core::vector3df(0, 0, 0));
	}
}

void Character::loadCharac(struct s_save info)
{
    _power = info.bomb_power;
    _movementSpeed = info.speed;
    _bombLoads = info.nb_bombs;
    return;
}

bool Character::detectBombExplosion(std::list<std::pair<Bomb *, u32>> _bomb, Core &core)
{
    aabbox3d<f32> node1 = _node->getBoundingBox();
    aabbox3d<f32> node2;
    static int test = 0;

    _node->getRelativeTransformation().transformBoxEx(node1);
    for (auto i : _bomb) {
        for (auto a : i.first->getExplosion()) {
            node2 = a->getBox();
            if (node1.intersectsWithBox(node2) == true) {
                _node->removeAnimators();
                test += 1;
                return true;
            }
        }
    }
    return false;
}

void    Character::findPosition(void)
{
    _nodePosition = _node->getPosition();
    _ghostPosition = _nodePosition;
    _ghost->setPosition(_ghostPosition);
    return;
}

const bool Character::setRotation(Core &core, const EKEY_CODE key, const MOVE_DIRECTION dir)
{
	if (core._receiver->IsKeyDown(key)) {
        if (_moveDirection != dir) {
            setCharacterRunning(core);
            _moveDirection = dir;
        }
        return (true);
	}
    return (false);
}

void Character::setCharacterRunning(Core &core)
{
    _node->setMesh(core.getSmgr()->getMesh("./media/lego/bomberman_run.b3d"));
    _node->setMaterialTexture(0, core.getDriver()->getTexture(_texturePath.c_str()));
}

bool Character::controllerUp(Core &core, const MOVE_DIRECTION dir)
{
    if (_moveVertical < 0
        && (_moveHorizontal > -0.75 && _moveHorizontal < 0.75)) {
        if (_moveDirection != dir) {
            setCharacterRunning(core);
            _moveDirection = dir;
        }
        return (true);
	}
    return (false);
}

bool Character::controllerDown(Core &core, const MOVE_DIRECTION dir)
{
    if (_moveVertical > 0
        && (_moveHorizontal > -0.75 && _moveHorizontal < 0.75)) {
        if (_moveDirection != dir) {
            setCharacterRunning(core);
            _moveDirection = dir;
        }
        return (true);
	}
    return (false);
}

bool Character::controllerLeft(Core &core, const MOVE_DIRECTION dir)
{
    if (_moveHorizontal < 0
        && (_moveVertical > -0.75 && _moveVertical < 0.75)) {
        if (_moveDirection != dir) {
            setCharacterRunning(core);
            _moveDirection = dir;
        }
        return (true);
	}
    return (false);
}

bool Character::controllerRight(Core &core, const MOVE_DIRECTION dir)
{
    if (_moveHorizontal > 0
        && (_moveVertical > -0.75 && _moveVertical < 0.75)) {
        if (_moveDirection != dir) {
            setCharacterRunning(core);
            _moveDirection = dir;
        }
        return (true);
	}
    return (false);
}

void    Character::rotate(Core &core)
{
    if (_isMoving == true)
        return;
    if (_speedBuffering == true) {
        _movementSpeed += 2;
        _countSpeedUp += 1;
        _speedBuffering = false;
    }
    if (_keys.joystick == false) {
        if (!(setRotation(core, _keys.left, LEFT) || setRotation(core, _keys.right, RIGHT)
            || setRotation(core, _keys.up, UP) || setRotation(core, _keys.down, DOWN))) {
            _node->setMesh(core.getSmgr()->getMesh("./media/lego/bomberman_stand.b3d"));
            _node->setMaterialTexture(0, core.getDriver()->getTexture(_texturePath.c_str()));
            _moveDirection = NONE;
        }
    } else {
        if (!(controllerLeft(core, LEFT)  || controllerRight(core, RIGHT) || 
            controllerUp(core, UP) || controllerDown(core, DOWN))) {
            _node->setMesh(core.getSmgr()->getMesh("./media/lego/bomberman_stand.b3d"));
            _node->setMaterialTexture(0, core.getDriver()->getTexture(_texturePath.c_str()));
            _moveDirection = NONE;
        }
    }
}

const bool Character::isPressed(const EKEY_CODE key, Core &core)
{
	if (core._receiver->IsKeyDown(key)) {
        return (true);
    } else if (key == _keys.drop && core._receiver->IsKeyDown(key) == false) {
        _tempoBomb = false;
    }
    return (false);
}

const bool  Character::bombAction(u32 now, Core &core)
{
    if (isPressed(_keys.drop, core) == true && _bombLoads >= 1)
        return true;
    else {
        joystick_update(core);
        if (_keys.joystick == true) {
            if (_joystickData.IsButtonPressed(0) == true && _bombLoads >= 1)
                return true;
            else {
                _tempoBomb = false;
                return false;
            }
        }
    }
    return false;
}

const f32     Character::rotateAndSpeed(const f32 frameRate, IAnimatedMeshSceneNode *mesh, const vector3df rotation)
{
    mesh->setRotation(rotation);
    return _movementSpeed * frameRate;
}

void Character::whichBonus(Bonus *bonus)
{
    if (bonus->getBonus() == SPEED) {
        _speedBuffering = true;
    } else if (bonus->getBonus() == BOMB)
        _bombLoads += 1;
    else if (bonus->getBonus() == POWER)
        _power += STILE;
}

void Character::detectBonus(std::list<std::pair<Bonus *, vector3df>> & bonus)
{
    aabbox3d<f32> node1 = _node->getBoundingBox();
    aabbox3d<f32> node2;

    _node->getRelativeTransformation().transformBoxEx(node1);
    for (auto i : bonus) {
        node2 = i.first->getMesh()->getBoundingBox();
        i.first->getMesh()->getRelativeTransformation().transformBoxEx(node2);
        if (node1.intersectsWithBox(node2) == true) {
            whichBonus(i.first);
            i.first->getMesh()->remove();
            bonus.remove(i);
            return;
        }
    }
}

void Character::joystick_update(Core &core)
{
    if (core.getJoytstickInfo().size() > 0) {
        _joystickData = core._receiver->GetJoystickState();
        _moveHorizontal = (f32)_joystickData.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
        _moveVertical = (f32)_joystickData.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / 32767.f;

        if (std::fabs(_moveHorizontal) < 0.20f)
            _moveHorizontal = 0;
        if (std::fabs(_moveVertical) < 0.20f)
            _moveVertical = 0;
    }
}

void    Character::pickUpBonus(std::list<std::pair<Bonus *, vector3df>> & bonus, Core &core)
{
    if (bonus.size() >= 1) {
        detectBonus(bonus);
    }
}

const bool  Character::detectCollision(std::list<std::pair<Bomb *, u32>> bomb)
{
    aabbox3d<f32> node1 = _ghost->getBoundingBox();
    aabbox3d<f32> node2;

    _ghost->getRelativeTransformation().transformBoxEx(node1);
    for (auto i : bomb) {
        if (i.first->isBombExplosed() == false) {
            node2 = i.first->getMesh()->getBoundingBox();
            i.first->getMesh()->getRelativeTransformation().transformBoxEx(node2);
            if (node1.intersectsWithBox(node2) == true && i.first->getCollider() == INIT && _id == i.first->getId()) {
                _intoBomb = true;
                return false;
            } else if (node1.intersectsWithBox(node2) == true && i.first->getCollider() == INIT && _id != i.first->getId()) {
                return true;
            } else if (node1.intersectsWithBox(node2) == true && i.first->getCollider() != INIT) {
                return true;
            } else {
                _intoBomb = false;
                if (i.first->getId() == _id) {
                    i.first->setCollider(COLLIDE);
                }
            }
        }
    }
    return false;
}

bool Character::isObstacleAt(std::vector<std::string> &mapVector, vector3df vec)
{
    int x = ((vec.X - (STILE / 2)) / STILE) + 1;
    int z = ((vec.Z - (STILE / 2)) / STILE) + 1;

    if (mapVector.at(x)[z] == '0' || mapVector.at(x)[z] == 'S')
        return (false);
    return (true);
}

vector3df Character::getPlayerMiddleNode(const vector3df &vec)
{
    int x = ((vec.X - (STILE / 2)) / STILE) + 1;
    int z = ((vec.Z - (STILE / 2)) / STILE) + 1;

    x = (x * STILE);
    z = (z * STILE);

    vector3df ret(x, vec.Y, z);
    return (ret);
}

void    Character::ghostMove(const f32 frameRate, IAnimatedMeshSceneNode *mesh, vector3df &rot)
{
    rot.X += _moveDirection == UP ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 270, 0)) : 0;
    rot.X -= _moveDirection == DOWN ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 90, 0)) : 0;
    rot.Z += _moveDirection == LEFT ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 180, 0)) : 0;
    rot.Z -= _moveDirection == RIGHT ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 0, 0)) : 0;
}

bool    Character::isCollidingWithBomb(vector3df playerPos, std::list<std::pair<Bomb *, u32>> bomb)
{
    for (auto b : bomb) {
        if (b.first->getPos() == playerPos) {
            _collide = true;
            if (_tempoMove == true)
                _tempoMove = false;
            _isMoving = false;
            return true;
        } else
        _collide = false;
    }
    return false;
}

bool    Character::isCollidingWithObstacle(vector3df playerPos, std::vector<std::string> &map)
{
    if (isObstacleAt(map, playerPos) == true) {
        _collide = true;
        if (_tempoMove == true)
            _tempoMove = false;
        _isMoving = false;
        return true;
    } else
        _collide = false;
    return false;
}

void    Character::initMove(IAnimatedMeshSceneNode *mesh)
{
    _isMoving = true;
    if (_tempoMove == false) {
        _initialPos = mesh->getPosition();
        _tempoMove = true;
    }
}

void    Character::moveUp(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == UP) {
        rot.X += rotateAndSpeed(frameRate, mesh, vector3df(0.0, 270.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X + STILE - _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X + STILE - _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), map) == true)
            return;
        if (mesh->getPosition().X >= _initialPos.X + STILE - _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X + STILE - _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.X += 0;
    }
}

void    Character::moveDown(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == DOWN) {
        rot.X -= rotateAndSpeed(frameRate, mesh, vector3df(0.0, 90.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X - STILE + _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X - STILE + _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), map) == true)
            return;
        if (mesh->getPosition().X <= _initialPos.X - STILE + _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X - STILE + _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.X -= 0;
    }
}

void    Character::moveLeft(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == LEFT) {
        rot.Z += rotateAndSpeed(frameRate, mesh, vector3df(0.0, 180.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z + STILE - _movementSpeed * frameRate)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z + STILE - _movementSpeed * frameRate)), map) == true)
            return;
        if (mesh->getPosition().Z >= _initialPos.Z + STILE - _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z + STILE - _movementSpeed * frameRate)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.Z += 0;
    }
}

void    Character::moveRight(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == RIGHT) {
        rot.Z -= rotateAndSpeed(frameRate, mesh, vector3df(0.0, 0.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z - STILE + _movementSpeed * frameRate)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z - STILE + _movementSpeed * frameRate)), map) == true)
            return;
        if (mesh->getPosition().Z <= _initialPos.Z - STILE + _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z - STILE + _movementSpeed * frameRate)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.Z -= 0;
    }
}

void    Character::makeItMove(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    moveUp(frameRate, mesh, rot, map, bomb);
    moveDown(frameRate, mesh, rot, map, bomb);
    moveLeft(frameRate, mesh, rot, map, bomb);
    moveRight(frameRate, mesh, rot, map, bomb);
}

void    Character::move(const f32 frameRate, Core &core, std::list<std::pair<Bomb *, u32>> bomb, std::vector<std::string> &map)
{
    ghostMove(frameRate, _ghost, _ghostPosition);
    ghostMove(frameRate, _ghost, _ghostPosition);
    _ghost->setPosition(_ghostPosition);
    if (bomb.size() >= 1) {
        _collide = detectCollision(bomb);
    } else {
        _collide = false;
    }
    if (_collide == false) {
        makeItMove(frameRate, _node, _nodePosition, map, bomb);
        if (_collide == false && _isMoving == true)
            _node->setPosition(_nodePosition);
    }
    return;
}