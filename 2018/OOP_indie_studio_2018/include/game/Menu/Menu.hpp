/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <vector>
#include <map>
#include "Core.hpp"
#include "MenuEvent.hpp"
#include "IScene.hpp"

class Menu : public IScene {
	public:
		Menu(Core &core);
		~Menu();

		e_scene getScene() const;
		void changeScene(const e_scene);
		const bool isSaveCreated(void) const;

	private:
		void setup(void);
		void loop(void);
		void setupButton(void);

	private:
		Core &_core;
		SAppContext _context;
		e_scene _currentScene;
		MenuEvent *_receiver;
		std::map<std::string, irr::gui::IGUIButton *> _buttonList;
		irr::gui::IGUISkin *_skin;
		irr::gui::IGUIEnvironment *_env;
		irr::gui::IGUIFont *_font;
		irr::gui::IGUIImage *_img;
};

#endif /* !MENU_HPP_ */
