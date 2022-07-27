/*
** EPITECH PROJECT, 2019
** src
** File description:
** Explosion
*/

#ifndef EXPLOSION_HPP_
#define EXPLOSION_HPP_

#include "Core.hpp"

#define TIME_TO_FADE 300

enum DIR {
	UPDIR,
	DOWNDIR,
	LEFTDIR,
	RIGHTDIR
};

class Explosion {
	public:
		Explosion(Core &, DIR, int, aabbox3d<f32>);
		~Explosion();

		IParticleSystemSceneNode *getPs(void) const { return _particuleSystem; };
		// void setExplosionTime(u32 time) { _explosionTime = time; };
		// u32 getExplosionTime(void) const { return _explosionTime; };
		const aabbox3d<f32> & getBox(void) const { return _box; };
		void updateExplosion();
		void setCollider(bool boolean) { isColliding = boolean; };

	private:
		aabbox3d<f32>	_box;
		IParticleSystemSceneNode* _particuleSystem;
		IParticleBoxEmitter *_emitter;
		bool isColliding;
		int	 _maxPower;
		DIR _direction;
};

#endif /* !EXPLOSION_HPP_ */
