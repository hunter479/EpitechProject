/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PauseMenu
*/

#include <iostream>
#include "PauseMenu.hpp"

PauseMenu::PauseMenu(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver)
{
    _device = device;
    _driver = driver;
    _status = PauseMenuEvent::RUN;
    setup();
    loop();
}

PauseMenu::~PauseMenu()
{
    for (auto i : _buttonList)
        i.second->remove();
    _buttonList.clear();
}

void PauseMenu::setup()
{
    _env = _device->getGUIEnvironment();
    _skin = _env->getSkin();
    _font = _env->getFont("./media/Menu/bigfont.png");
    if (!_font)
        throw std::invalid_argument("<Menu>: Unable to set font");
    _skin->setFont(_font);
    _skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255,255,255,255));
    _img = _env->addImage(_driver->getTexture("media/pauseBG.png"), irr::core::position2d<int>(0,0));
    setupButton();
    _receiver = new PauseMenuEvent();
    _device->setEventReceiver(_receiver);
}

void PauseMenu::setupButton()
{
    _buttonList["CONTINUE"] = (_env->addButton(irr::core::rect<irr::s32>(960 - 250, 440, 960 + 250, 440 + 50), 0, PauseMenuEvent::RESUME, L"RESUME"));
    _buttonList["NEW GAME"] = (_env->addButton(irr::core::rect<irr::s32>(960 - 250, 540, 960 + 250, 540 + 50), 0, PauseMenuEvent::MENU, L"MENU"));
    _buttonList["QUIT"] = (_env->addButton(irr::core::rect<irr::s32>(960 - 250, 640, 960 + 250, 640 + 50), 0, PauseMenuEvent::QUIT, L"QUIT AND SAVE"));

}

void PauseMenu::loop()
{
    if (_device->getEventReceiver() == nullptr) {
        std::cerr << "Event receiver is null\n";
        return;
    }
    while (_device->run() && _receiver->getStatus() == PauseMenuEvent::RUN) {
		if (_device->isWindowActive()) {
			_driver->beginScene(true, true, irr::video::SColor(0, 100, 100, 100));
			_env->drawAll();
			_driver->endScene();
		}
    }
}

const PauseMenuEvent::status PauseMenu::getStatus() const
{
    return (_receiver->getStatus());
}