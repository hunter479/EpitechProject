/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CharacterSelection
*/

#ifndef CHARACTERSELECTION_HPP_
#define CHARACTERSELECTION_HPP_

#include <map>
#include "Core.hpp"
#include "IScene.hpp"
#include "CharacterSelectionEvent.hpp"

class CharacterSelection : public IScene {
	public:
		CharacterSelection(Core &core);
		~CharacterSelection();

		e_scene getScene() const;
		void changeScene(const e_scene);
	private:
		void setup();
		void loop();
		void drawText();
		void setupButton();
		void setupText();
		void setupImg();
		const irr::core::recti center(playerM model, bool L, int y);
	private:
		Core &_core;
		e_scene _currentScene;
		CharacterSelectionEvent *_receiver;
		std::map<std::string, irr::gui::IGUIButton *> _buttonList;
		std::map<std::string, irr::gui::IGUIImage *> _img;
		std::map<std::string, irr::gui::IGUIStaticText *> _text;
		irr::gui::IGUISkin *_skin;
		irr::gui::IGUIEnvironment *_env;
		irr::gui::IGUIFont *_font;
};

#endif /* !CHARACTERSELECTION_HPP_ */
