/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PauseMenu
*/

#ifndef PAUSEMENU_HPP_
#define PAUSEMENU_HPP_

#include <map>
#include "PauseMenuEvent.hpp"

class PauseMenu {
	public:
		PauseMenu(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver);
		~PauseMenu();
		const PauseMenuEvent::status getStatus() const;
	protected:
    private:
        void setup();
        void setupButton();
        void loop();
	private:
        irr::IrrlichtDevice *_device;
		irr::video::IVideoDriver *_driver;
        PauseMenuEvent::status _status;
		PauseMenuEvent *_receiver;
		std::map<std::string, irr::gui::IGUIButton *> _buttonList;
		irr::gui::IGUISkin *_skin;
		irr::gui::IGUIEnvironment *_env;
		irr::gui::IGUIFont *_font;
		irr::gui::IGUIImage *_img;
};

#endif /* !PAUSEMENU_HPP_ */
