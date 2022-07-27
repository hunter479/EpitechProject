/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Credits
*/

#include <stdexcept>
#include <sys/types.h>
#include "Credits.hpp"

Credits::Credits(Core &core) : _core(core)
{
    setup();
    loop();
}

Credits::~Credits()
{
    if (_img != nullptr) {
        _img->remove();
        _img = nullptr;
    }
    if (_img != nullptr) {
        _button->remove();
    }
}

void Credits::setupButton()
{
    _button = (_env->addButton(irr::core::rect<irr::s32>(1920 - 200, 940, 1920 - 50, 940 + 50), 0, MENU, L"MENU"));
}

void Credits::setup()
{
    _currentScene = CREDITS;
    _env = _core.getDevice()->getGUIEnvironment();
    _skin = _env->getSkin();
    _font = _env->getFont("./media/Menu/bigfont.png");
    if (!_font)
        throw std::invalid_argument("<Credits>: Unable to set font");
    _skin->setFont(_font);
    _skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, video::SColor(255,255,255,255));
    _img = _env->addImage(_core.getDriver()->getTexture("media/Credits/bg.png"), position2d<int>(0,0));
    setupButton();
    _receiver = new CreditsEvent();
    _core.getDevice()->setEventReceiver(_receiver);
}

void Credits::loop()
{
    if (_core.getDevice()->getEventReceiver() == nullptr) {
        std::cerr << "Event receiver is null\n";
        return;
    }
    while (_core.getDevice()->run() && _core.getDevice() && _receiver->getScene() == CREDITS) {
		if (_core.getDevice()->isWindowActive()) {
			_core.getDriver()->beginScene(true, true, irr::video::SColor(0, 100, 100, 100));
			_env->drawAll();
			_core.getDriver()->endScene();
		}
    }
    changeScene(_receiver->getScene());
}

void Credits::changeScene(const e_scene i)
{
    _currentScene = i;
}

Credits::e_scene Credits::getScene() const
{
    return (_currentScene);
}
