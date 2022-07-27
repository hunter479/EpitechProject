/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PowerUp
*/

#include "PowerUp.hpp"

PowerUp::PowerUp(irr::IrrlichtDevice *device, vector3df pos, IMeshSceneNode *node)
{
	// IMesh *mesh = core.getSmgr()->getMesh("./media/powerUpP.obj");
	// node = core.getSmgr()->addMeshSceneNode(mesh);
	if (node) {
        node->setMaterialTexture(0, device->getVideoDriver()->getTexture("./media/powerUpTexture.png"));
        node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
		node->setScale(irr::core::vector3df((float)STILE / 23, (float)STILE / 23, (float)STILE / 23));
		node->setPosition(pos);
        node->setRotation(irr::core::vector3df(-40, 0, 0));
        node->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	}

    // ROTATION ANIMATION
    irr::scene::ISceneNodeAnimator *anim = NULL;
    anim = device->getSceneManager()->createRotationAnimator(irr::core::vector3df(0, 1, 0));
    if (anim) {
        node->addAnimator(anim);
        anim->drop();
    }
}

PowerUp::~PowerUp()
{
}
