/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include <iostream>
#include "Core.hpp"
#include "Bomb.hpp"
#include "Explosion.hpp"

Bomb::Bomb(vector3df nodePos, const int id, Core &core, IAnimatedMeshSceneNode *characterNode) : _playerId(id), _state(INIT)
{
	// CREATE BOMB
	_mesh = core.getSmgr()->getMesh("./media/lego/bomb.3DS");
	_node = core.getSmgr()->addMeshSceneNode(_mesh);
	if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		_node->setScale(core::vector3df((float)STILE / 30, (float)STILE / 30, (float)STILE / 30));
		_node->setPosition(nodePos);
        _node->setRotation(irr::core::vector3df(0.f, -40.f, 0.f));
	}
	_nodePosition = vector3df(nodePos);

	// CREATE PARTICLE
	_particuleSystem = core.getSmgr()->addParticleSystemSceneNode(false);
	IParticleEmitter* emitter = _particuleSystem->createBoxEmitter(aabbox3d<f32>
		(_nodePosition.X, _nodePosition.Y + STILE * 0.5, _nodePosition.Z, _nodePosition.X, _nodePosition.Y + STILE * 0.5, _nodePosition.Z),
		vector3df(0.0f, 0.06f, 0.0f),
		20, 21,
		SColor(255, 255, 255, 255),
		SColor(255, 255, 255, 255),
		20, 20, 0,
		dimension2df(2.0f, 2.0f),
		dimension2df(3.0f, 3.0f));
	_particuleSystem->setEmitter(emitter);
	emitter->drop();
	_particuleSystem->setMaterialFlag(video::EMF_LIGHTING, false);
	_particuleSystem->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	_particuleSystem->setMaterialTexture(0, core.getDriver()->getTexture("./media/lego/fire.bmp"));
	_particuleSystem->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	_bombExplosed = false;
}

void Bomb::bombExplosion(Core &core, int powerMax)
{
	// UP
	_explosion.push_back(new Explosion(core, UPDIR, _nodePosition.X + powerMax,
	aabbox3d<f32>(_nodePosition.X, _nodePosition.Y, _nodePosition.Z - 2.3, _nodePosition.X + (STILE * 1.4), _nodePosition.Y, _nodePosition.Z + 2.3)));

	// DOWN
	_explosion.push_back(new Explosion(core, DOWNDIR, _nodePosition.X - powerMax,
	aabbox3d<f32>(_nodePosition.X - (STILE * 1.4), _nodePosition.Y, _nodePosition.Z - 2.3, _nodePosition.X, _nodePosition.Y, _nodePosition.Z + 2.3)));

	// LEFT
	_explosion.push_back(new Explosion(core, LEFTDIR, _nodePosition.Z + powerMax,
	aabbox3d<f32>(_nodePosition.X + 2.3, _nodePosition.Y, _nodePosition.Z, _nodePosition.X - 2.3, _nodePosition.Y, _nodePosition.Z + (STILE * 1.4))));

	// RIGHT
	_explosion.push_back(new Explosion(core, RIGHTDIR, _nodePosition.Z - powerMax,
	aabbox3d<f32>(_nodePosition.X + 2.3, _nodePosition.Y, _nodePosition.Z - (STILE * 1.4), _nodePosition.X - 2.3, _nodePosition.Y, _nodePosition.Z)));

	_bombExplosed = true;
}

void Bomb::explosionFadeOut()
{
	for (auto i : _explosion)
		i->getPs()->setEmitter(0);
}

void Bomb::destroyAll()
{
	int explo = 0;

	for (auto i : _explosion) {
		if (i->getPs()) {
			i->getPs()->remove();
			explo = 1;
		}
	}
	if (explo == 0) {
		getPs()->remove();
		getMesh()->remove();
	}
}

Bomb::~Bomb()
{
}
