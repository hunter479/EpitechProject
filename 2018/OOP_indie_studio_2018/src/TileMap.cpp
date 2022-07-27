/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** TileMap
*/

#include "TileMap.hpp"

TileMap::TileMap(int tileSize, int width, int height, irr::IrrlichtDevice *device)
{
    _tileSize = tileSize;
    _mapHeight = height;
    _mapWidth = width;

    _device = device;
    _driver = device->getVideoDriver();
    _sceneManager = device->getSceneManager();
    ILightSceneNode* light = _sceneManager->addLightSceneNode(0, vector3df(20.0f, 20.0f, 120.0f), SColorf(1.0f, 1.0f, 1.0f, 1.0f), 80.0f);
    light->getLightData().AmbientColor.set(1.0f, 1.0f, 1.0f, 1.0f);
}

TileMap::~TileMap()
{
    save();
}

irr::core::vector3df TileMap::getMiddleNode(irr::core::vector3df const &vec)
{
    std::cout << "VECOT" << vec.X << "-" << vec.Z << std::endl;

    int x = (vec.X / _tileSize);
    int z = (vec.Z / _tileSize);

    x = (x * _tileSize);
    z = (z * _tileSize);

    std::cout << "VECAT" << x << "-" << z << std::endl;

    irr::core::vector3df ret(x, vec.Y, z);
    return (ret);
}

std::pair<int, int> TileMap::getNode(irr::core::vector3df const &vec)
{
    int x = vec.X / _tileSize;
    int z = vec.Z / _tileSize;

    std::pair<int, int> ret(x, z);

    return (ret);
}

std::list<std::pair<irr::scene::IMeshSceneNode *, bool>> TileMap::getObjects()
{
    std::list<std::pair<irr::scene::IMeshSceneNode *, bool>> list;

    int i = 0;
    int k = 0;

    for (i = 0; i != _mapHeight; i++) {
        for (k = 0; k != _mapWidth; k++) {
            if (_mapVector.at(i)[k] == *WOOD)
                list.push_back(std::make_pair(_map[std::make_pair(i, k)].front(), true));
            if (_mapVector.at(i)[k] == *WALL)
                list.push_back(std::make_pair(_map[std::make_pair(i, k)].front(), false));        }
    }
    return (list);
}

void TileMap::deleteMap()
{
    int i = 0;
    int k = 0;

    for (i = 0; i != _mapHeight; i++) {
        for (k = 0; k != _mapWidth; k++) {
            while (_map[std::make_pair(i, k)].size() > 0) {
                _map[std::make_pair(i, k)].front()->remove();
                _map[std::make_pair(i, k)].pop_front();
            }
        }
    }
    _mapVector.clear();
    _mapHeight = 0;
    _mapWidth = 0;
}

void TileMap::emptyMap()
{
    int i = 0;
    int k = 0;
    irr::core::vector3df pos(0, 0 - _tileSize, 0);

    for (i = 0; i != _mapHeight; i++) {
        _mapVector.push_back("");
        for (k = 0; k != _mapWidth; k++) {
            irr::scene::IMeshSceneNode *node = _sceneManager->addCubeSceneNode(_tileSize);
            node->setPosition(pos);
            node->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
            node->setMaterialTexture(0, _driver->getTexture(GRASS_PNG));
            _map[std::make_pair(i, k)].push_front(node);
            _mapVector.at(i).append(GRASS);
            pos.Z += _tileSize;
        }
        pos.Z = 0;
        pos.X += _tileSize;
    }
}

void TileMap::setCollisions(irr::scene::IMeshSceneNode *node)
{
    irr::scene::ITriangleSelector *selector = _sceneManager->createOctreeTriangleSelector(node->getMesh(), node, 128);
    node->setTriangleSelector(selector);

    for (Character *a : _player) {
        irr::scene::ISceneNodeAnimator *anim = _sceneManager->createCollisionResponseAnimator(selector, a->getPlayer(),
                    irr::core::vector3df(3, 0.01, 3),
                    irr::core::vector3df(0.f, 0.f, 0.f),
                    irr::core::vector3df(0.f, 0.f, 0.f));
        a->getPlayer()->addAnimator(anim);
        anim->drop();
    }
    for (IA *a : _ais) {
        irr::scene::ISceneNodeAnimator *anim = _sceneManager->createCollisionResponseAnimator(selector, a->getIA(),
                    irr::core::vector3df(3, 0.01, 3),
                    irr::core::vector3df(0.f, 0.f, 0.f),
                    irr::core::vector3df(0.f, 0.f, 0.f));
        a->getIA()->addAnimator(anim);
        anim->drop();
    }
}

void TileMap::deleteBonuses()
{
    for (auto b : *_bonus) {
        b.first->getMesh()->remove();
    }
    _bonus->clear();
}

void TileMap::load(std::vector<std::string> &map, std::list<std::pair<Bonus *, irr::core::vector3df>> *bonuses)
{
    _bonus = bonuses;
    deleteMap();
    _map.clear();

    _mapHeight = (int)map.size();
    _mapWidth = (int)map.at(0).size();

    _mapVector.clear();

    emptyMap();
    _mapVector = map;

    int i = 0;
    int k = 0;
    int bonus;
    int b = (_bonus->size() != 0) ? 0 : 1;

    irr::core::vector3df pos(0, 0, 0);

    for (i = 0; i != (int)_mapVector.size(); i++) {
        for (k = 0; _mapVector.at(i)[k] != 0; k++) {
            if (_mapVector.at(i)[k] != *GRASS && _mapVector.at(i)[k] != *SAFE) {
                irr::scene::IMeshSceneNode *node = _sceneManager->addCubeSceneNode(_tileSize);
                setCollisions(node);

                node->setPosition(pos);
                node->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
                bonus = (b == 1) ? rand() % 100 : 100;
                if (_mapVector.at(i)[k] == *WOOD) {
                    node->setMaterialTexture(0, _driver->getTexture(WOOD_PNG));
                    if (bonus < 50)
                        bonuses->push_back(std::make_pair(new Bonus(_device, pos), pos));
                }
                if (_mapVector.at(i)[k] == *WALL)
                    node->setMaterialTexture(0, _driver->getTexture(WALL_PNG));
                _map[std::make_pair(i, k)].push_front(node);
            }
            pos.Z += _tileSize;
        }
        pos.Z = 0;
        pos.X += _tileSize;
    }
    _bonus = bonuses;
}

std::vector<std::string> TileMap::save()
{
    // for (int i = 0; i != (int)_mapVector.size(); i ++)
    //     std::cout << _mapVector.at(i) << std::endl;
    return (_mapVector);
}

const irr::core::vector3df TileMap::getMiddle()
{
    int x = (int)_mapHeight / 2;
    int z = (int)_mapWidth / 2;
    std::cout << x << z << std::endl;
    return (getTileMiddle(_map[std::make_pair(x, z)].front()->getPosition()));
}

const irr::core::vector3df TileMap::getTileMiddle(irr::core::vector3df const &vec)
{
    irr::core::vector3df middle;

    std::cout << vec.X << "-" << vec.Z << ";";

    int x = ((int)vec.X + _tileSize / 2) / _tileSize;
    middle.X = x * _tileSize;

    std::cout << middle.X;

    middle.Y = vec.Y;
    std::cout << "-";

    int z = ((int)vec.Z + _tileSize / 2) / _tileSize;
    middle.Z = z * _tileSize;

    std::cout << middle.Z << std::endl;

    return (middle);
}

void TileMap::setPlayer(std::list<Character *> player)
{
    _player = player;
}

void TileMap::setAis(std::list<IA *> ia)
{
    _ais = ia;
}

TileMap &TileMap::operator[](std::pair<int ,int> pos)
{
    _x = pos.first;
    _z = pos.second;

    if (_x >= (int)_mapVector.size())
        _x = (int)_mapVector.size() - 1;
    if (_z >= (int)_mapVector.at(0).size())
        _z = (int)_mapVector.at(0).size() - 1;
    return (*this);
}

TileMap &TileMap::operator+=(std::string const &cube)
{
    irr::core::vector3df pos = _map[std::make_pair(_x, _z)].front()->getPosition();
    pos.Y += _tileSize;

    irr::scene::IMeshSceneNode *node = _sceneManager->addCubeSceneNode(_tileSize);
    node->setPosition(pos);
    node->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    if (cube.at(0) == *GRASS || cube.at(0) == *SAFE) {
        node->setMaterialTexture(0, _driver->getTexture(GRASS_PNG));
        _mapVector.at(_x)[_z] = *GRASS;
    }
    if (cube.at(0) == *WOOD) {
        (this)->setCollisions(node);
        node->setMaterialTexture(0, _driver->getTexture(WOOD_PNG));
        _mapVector.at(_x)[_z] = *WOOD;
    }
    if (cube.at(0) == *WALL) {
        (this)->setCollisions(node);
        node->setMaterialTexture(0, _driver->getTexture(WALL_PNG));
        _mapVector.at(_x)[_z] = *WALL;
    }
    _map[std::make_pair(_x, _z)].push_front(node);

    return (*this);
}

TileMap &TileMap::operator--(int useless)
{
    for (Character *a : _player) {
        a->getPlayer()->removeAnimators();
    }
    for (IA *a : _ais) {
        a->getIA()->removeAnimators();
    }
    _mapVector.at(_x)[_z] = *GRASS;
    std::vector<std::string> map = _mapVector;
    load(map, _bonus);
    return (*this);
}
