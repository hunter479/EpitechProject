/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Credits
*/

#ifndef CREDITs_HPP_
#define CREDITs_HPP_

#include "Core.hpp"
#include "CreditsEvent.hpp"
#include "IScene.hpp"

class Credits : public IScene {
	public:
		Credits(Core &core);
		~Credits();

		e_scene getScene() const;
		void changeScene(const e_scene);
		const bool isSaveCreated(void) const;

	private:
		void setup(void);
		void loop(void);
		void setupButton(void);

	private:
		Core &_core;
		e_scene _currentScene;
		CreditsEvent *_receiver;
        irr::gui::IGUIButton *_button;
		irr::gui::IGUISkin *_skin;
		irr::gui::IGUIEnvironment *_env;
		irr::gui::IGUIFont *_font;
		irr::gui::IGUIImage *_img;
};

#endif /* !CREDITs_HPP_ */
