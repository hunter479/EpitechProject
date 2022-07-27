/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuEvent
*/

#ifndef MENUEVENT_HPP_
#define MENUEVENT_HPP_

#include "IScene.hpp"

class MenuEvent : public irr::IEventReceiver
{
	public:
		MenuEvent(SAppContext &context, Core &core);
		~MenuEvent();

		virtual bool OnEvent(const irr::SEvent &event);
		const IScene::e_scene getScene() const;

	private:
		Core	&_core;
		IScene::e_scene _scene;
		bool button_event(irr::s32 id, irr::gui::IGUIEnvironment *env);
		bool keyboard_event(const irr::SEvent &event);
		SAppContext &_context;
};
#endif /* !MENUEVENT_HPP_ */
