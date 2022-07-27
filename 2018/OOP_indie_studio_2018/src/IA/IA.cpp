/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IA
*/

#include "IA.hpp"

IA::IA(const int id, const irr::core::vector3df pos, const std::string & asset, Core & core) : _id(id), _asset(asset), _positions(pos), _moveDirection(NONE), _collide(false), _bombLoads(1), _movementSpeed(STILE * 2), _power(STILE), _intoBomb(false)
{
    _origin = pos;
    _isAlive = true;
	_mesh = core.getSmgr()->getMesh("./media/lego/bomberman_stand.b3d");
	_node = core.getSmgr()->addAnimatedMeshSceneNode(_mesh);
	_ghost = core.getSmgr()->addAnimatedMeshSceneNode(_mesh);
	if (_node) {
		_node->setScale(core::vector3df(3 * STILE / 5, 3 * STILE / 5, 3 * STILE / 5));
		_node->setPosition(_positions);
		_node->setMaterialTexture(0, core.getDriver()->getTexture(_asset.c_str()));
		_ghost->setScale(core::vector3df(0, 0, 0));
		_ghost->setPosition(core::vector3df(0, 0, 0));
	}
}

void	IA::setDirection(std::vector<std::string> &mapVector,Core & core)
{
    irr::core::vector3df vec(_node->getPosition());
	_moveDirection = static_cast<MOVE_DIRECTION>(rand() % 5);

	if (_moveDirection != NONE) {
        if (_moveDirection == UP) {
            vec.X += STILE;
            if (isObstacleAt(mapVector, vec) == true) {
                _moveDirection = NONE;
                _nextToBox = true;
            } else
                _nextToBox = false;
        }
        if (_moveDirection == DOWN) {
            vec.X -= STILE;
            if (isObstacleAt(mapVector, vec) == true) {
                _moveDirection = NONE;
                _nextToBox = true;
            } else
                _nextToBox = false;
        }
        if (_moveDirection == LEFT) {
            vec.Z += STILE;
            if (isObstacleAt(mapVector, vec) == true) {
                _moveDirection = NONE;
                _nextToBox = true;
            } else
                _nextToBox = false;
        }
        if (_moveDirection == RIGHT) {
            vec.Z -= STILE;
            if (isObstacleAt(mapVector, vec) == true) {
                _moveDirection = NONE;
                _nextToBox = true;
            } else
                _nextToBox = false;
        }
		_node->setMesh(core.getSmgr()->getMesh("./media/lego/bomberman_run.b3d"));
    }
	if (_moveDirection == NONE)
		_node->setMesh(core.getSmgr()->getMesh("./media/lego/bomberman_stand.b3d"));
	_node->setMaterialTexture(0, core.getDriver()->getTexture(_asset.c_str()));
}

void    IA::findPosition(void)
{
    _nodePosition = _node->getPosition();
    _ghostPosition = _nodePosition;
    _ghost->setPosition(_ghostPosition);
    return;
}

const f32     IA::rotateAndSpeed(const f32 frameRate, IAnimatedMeshSceneNode *mesh, const vector3df rotation)
{
    mesh->setRotation(rotation);
    return _movementSpeed * frameRate;
}

bool IA::isObstacleAt(std::vector<std::string> &mapVector, vector3df vec)
{
    int x = ((vec.X - (STILE / 2)) / STILE) + 1;
    int z = ((vec.Z - (STILE / 2)) / STILE) + 1;

    if (mapVector.at(x)[z] == '0' || mapVector.at(x)[z] == 'S')
        return (false);
    return (true);
}

vector3df IA::getPlayerMiddleNode(const vector3df &vec)
{
    int x = ((vec.X - (STILE / 2)) / STILE) + 1;
    int z = ((vec.Z - (STILE / 2)) / STILE) + 1;

    x = (x * STILE);
    z = (z * STILE);

    vector3df ret(x, vec.Y, z);
    return (ret);
}

void    IA::ghostMove(const f32 frameRate, IAnimatedMeshSceneNode *mesh, vector3df &rot)
{
    rot.X += _moveDirection == UP ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 270, 0)) : 0;
    rot.X -= _moveDirection == DOWN ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 90, 0)) : 0;
    rot.Z += _moveDirection == LEFT ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 180, 0)) : 0;
    rot.Z -= _moveDirection == RIGHT ? rotateAndSpeed(frameRate, mesh, vector3df(0.0, 0, 0)) : 0;
}

bool    IA::isCollidingWithBomb(vector3df playerPos, std::list<std::pair<Bomb *, u32>> bomb)
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

bool    IA::isCollidingWithObstacle(vector3df playerPos, std::vector<std::string> &map)
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

void    IA::initMove(IAnimatedMeshSceneNode *mesh)
{
    _isMoving = true;
    if (_tempoMove == false) {
        _initialPos = mesh->getPosition();
        _tempoMove = true;
    }
}

void    IA::moveUp(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == UP) {
        rot.X += rotateAndSpeed(frameRate, mesh, vector3df(0.0, 270.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X + STILE - _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X + STILE - _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), map) == true)
            return;
        if (mesh->getPosition().X >= _initialPos.X + STILE - _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.X += 0;
    }
}

void    IA::moveDown(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == DOWN) {
        rot.X -= rotateAndSpeed(frameRate, mesh, vector3df(0.0, 90.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X - STILE + _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X - STILE + _movementSpeed * frameRate, _initialPos.Y, _initialPos.Z)), map) == true)
            return;
        if (mesh->getPosition().X <= _initialPos.X - STILE + _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.X -= 0;
    }
}

void    IA::moveLeft(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == LEFT) {
        rot.Z += rotateAndSpeed(frameRate, mesh, vector3df(0.0, 180.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z + STILE - _movementSpeed * frameRate)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z + STILE - _movementSpeed * frameRate)), map) == true)
            return;
        if (mesh->getPosition().Z >= _initialPos.Z + STILE - _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.Z += 0;
    }
}

void    IA::moveRight(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    if (_moveDirection == RIGHT) {
        rot.Z -= rotateAndSpeed(frameRate, mesh, vector3df(0.0, 0.0, 0.0));
        initMove(mesh);
        if (isCollidingWithBomb(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z - STILE + _movementSpeed * frameRate)), bomb) == true)
            return;
        if (isCollidingWithObstacle(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z - STILE + _movementSpeed * frameRate)), map) == true)
            return;
        if (mesh->getPosition().Z <= _initialPos.Z - STILE + _movementSpeed * frameRate) {
            mesh->setPosition(getPlayerMiddleNode(vector3df(_initialPos.X, _initialPos.Y, _initialPos.Z)));
            _tempoMove = false;
            _isMoving = false;
        }
    } else {
        rot.Z -= 0;
    }
}

void    IA::makeItMove(const f32 frameRate, IAnimatedMeshSceneNode *mesh, core::vector3df & rot, std::vector<std::string> &map, std::list<std::pair<Bomb *, u32>> bomb)
{
    moveUp(frameRate, mesh, rot, map, bomb);
    moveDown(frameRate, mesh, rot, map, bomb);
    moveLeft(frameRate, mesh, rot, map, bomb);
    moveRight(frameRate, mesh, rot, map, bomb);
}

void    IA::move(const f32 frameRate, Core &core, std::list<std::pair<Bomb *, u32>> bomb, std::vector<std::string> &map)
{
    ghostMove(frameRate, _ghost, _ghostPosition);
    ghostMove(frameRate, _ghost, _ghostPosition);
    _ghost->setPosition(_ghostPosition);
    if (bomb.size() >= 1)
        _collide = detectCollision(bomb);
    else
        _collide = false;
    if (_collide == false) {
        makeItMove(frameRate, _node, _nodePosition, map, bomb);
        if (_collide == false)
            _node->setPosition(_nodePosition);
    }
    return;
}

const bool	IA::detectCollision(std::list<std::pair<Bomb *, u32>> bomb)
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

const bool  IA::bombAction(u32 now, Core &core)
{
    int k = rand() % 5;
    if (_bombLoads > 0 && k < 5 && _nextToBox == true) {
        if (_node->getPosition().X < _origin.X || _node->getPosition().Z < _origin.Z) {
            _bombLoads = 0;
            return true;
        }
        else if (_node->getPosition().X > _origin.X + STILE || _node->getPosition().Z > _origin.Z + STILE) {
            _bombLoads = 0; 
            return true;
        }
    }
    return false;
}

void IA::whichBonus(Bonus *bonus)
{
    if (bonus->getBonus() == SPEED)
        _movementSpeed += 3;
    else if (bonus->getBonus() == POWER)
        _power += STILE;
}

void    IA::pickUpBonus(std::list<std::pair<Bonus *, vector3df>> & bonus, Core &core)
{
    if (bonus.size() >= 1) {
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
}

bool IA::detectBombExplosion(std::list<std::pair<Bomb *, u32>> _bomb, Core &core)
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
                // GAME OVER
                std::cout << test << std::endl;
                test += 1;
                return true;
            }
        }
    }
    return false;
}