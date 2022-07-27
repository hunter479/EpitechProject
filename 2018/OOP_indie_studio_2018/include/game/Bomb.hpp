/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include <vector>
#include "Core.hpp"
#include "Explosion.hpp"

#ifndef BOMB_HPP_
#define BOMB_HPP_

typedef enum	STATES
{
	INIT,
	COLLIDE
} E_STATES;

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Bomb {
	public:
		Bomb(vector3df, const int, Core &, IAnimatedMeshSceneNode *);
		~Bomb();

		IMeshSceneNode *getMesh(void) const { return _node; };
		IParticleSystemSceneNode *getPs(void) const { return _particuleSystem; };
		IParticleEmitter *getEmitter(void) const {return _emitter; };
		bool isBombExplosed(void) { return _bombExplosed; };

		std::vector<Explosion *>	getExplosion(void) const { return _explosion; };
		void bombExplosion(Core &, int);
		void explosionFadeOut(void);

		const E_STATES	getCollider(void) const { return _state; };
		void			setCollider(const E_STATES state) { _state = state; }
		const int		getId(void) const { return _playerId; };
		void			destroyAll(void);
		const vector3df &getPos(void) const { return _nodePosition; };

	private:
		// BOMB
		int		_playerId;
	    IMeshSceneNode *_node;
        vector3df _nodePosition;
        IMesh* _mesh;

		// PARTICULE
		E_STATES	_state;
		IParticleSystemSceneNode* _particuleSystem;
		IParticleEmitter *_emitter;

		std::vector<Explosion *> _explosion;
		bool _bombExplosed;
};

#endif /* !BOMB_HPP_ */
