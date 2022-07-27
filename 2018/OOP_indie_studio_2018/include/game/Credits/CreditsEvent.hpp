/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CreditsEvent
*/

#ifndef CREDITSEVENT_HPP_
#define CREDITSEVENT_HPP_

#include "IScene.hpp"

class CreditsEvent : public irr::IEventReceiver
{
	public:
		CreditsEvent();
		~CreditsEvent();

		virtual bool OnEvent(const irr::SEvent &event);
		const IScene::e_scene getScene() const;

	private:
		IScene::e_scene _scene;
        bool keyboard_event(const irr::SEvent &event);
};

#endif /* !CREDITsEVENT_HPP_ */
