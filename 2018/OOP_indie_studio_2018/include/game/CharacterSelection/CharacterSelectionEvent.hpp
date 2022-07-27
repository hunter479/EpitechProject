/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CharacterSelectionEvent
*/

#ifndef CHARACTERSELECTIONEVENT_HPP_
#define CHARACTERSELECTIONEVENT_HPP_

#include <map>
#include "IScene.hpp"
#include "Core.hpp"

class CharacterSelectionEvent : public irr::IEventReceiver
{
	public:
		enum button {
			L1 = 100, R1, L2, R2, L3, R3, L4, R4
		};
		CharacterSelectionEvent(const bool joy, Core &core);
		~CharacterSelectionEvent();
		virtual bool OnEvent(const irr::SEvent &event);
		const IScene::e_scene getScene() const;
		PlayerInfo *p1;
		PlayerInfo *p2;
		PlayerInfo *p3;
		PlayerInfo *p4;

	private:
		bool playerButton(irr::s32 id);
		bool button_event(irr::s32 id);
		bool keyboard_event(const irr::SEvent &event);
	private:
		Core &_core;
		std::map<button, PlayerInfo *> _moveL;
		std::map<button, PlayerInfo *> _moveR;
		std::map<button, void (PlayerInfo::*)()> _playerM;
		std::vector<std::pair<playerM, bool>> _isTaken;
		IScene::e_scene _scene;
};
#endif /* !CHARACTERSELECTIONEVENT_HPP_ */
