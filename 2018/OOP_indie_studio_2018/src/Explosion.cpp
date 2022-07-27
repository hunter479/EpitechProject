/*
** EPITECH PROJECT, 2019
** src
** File description:
** Explosion
*/

#include "Explosion.hpp"

Explosion::Explosion(Core &core, DIR direction, int maxPower, aabbox3d<f32> bbox) : isColliding(false), _maxPower(maxPower), _direction(direction)
{
	_box = bbox;
	_particuleSystem = core.getSmgr()->addParticleSystemSceneNode(false);
	IParticleAffector* paf = _particuleSystem->createFadeOutParticleAffector(SColor(0, 0, 0, 0), 1000);
	_particuleSystem->addAffector(paf);
	paf->drop();

	_emitter = _particuleSystem->createBoxEmitter(bbox,
		vector3df(0.0f, 0.0f, 0.0f),
		6000, 6000,
		SColor(0, 255, 255, 255),
		SColor(0, 255, 255, 255),
		500, 500, 1,
		dimension2df(2.0f, 2.0f),
		dimension2df(3.0f, 3.0f));
	_particuleSystem->setEmitter(_emitter);
	// _emitter->drop();
	_particuleSystem->setMaterialFlag(video::EMF_LIGHTING, false);
	_particuleSystem->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	_particuleSystem->setMaterialTexture(0, core.getDriver()->getTexture("./media/lego/fire.bmp"));
	_particuleSystem->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

Explosion::~Explosion()
{
}

void Explosion::updateExplosion(void)
{
	if (_direction == UPDIR && isColliding == false) {
		if (_box.MaxEdge.X <= _maxPower)
			_box.MaxEdge.X += STILE;
	}
	if (_direction == DOWNDIR && isColliding == false) {
		if (_box.MinEdge.X >= _maxPower)
			_box.MinEdge.X -= STILE;
	}
	if (_direction == LEFTDIR && isColliding == false) {
		if (_box.MaxEdge.Z <= _maxPower)
			_box.MaxEdge.Z += STILE;
	}
	if (_direction == RIGHTDIR && isColliding == false) {
		if (_box.MinEdge.Z >= _maxPower) {
			_box.MinEdge.Z -= STILE;
		}
	}
	// isColliding = true;
	_emitter->setBox(_box);
}