/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** CharacterSelection
*/

#include <stdexcept>
#include "CharacterSelection.hpp"

CharacterSelection::CharacterSelection(Core &core) : _core(core)
{
    setup();
    loop();
}

CharacterSelection::~CharacterSelection()
{
    for (auto i : _img) {
        i.second->remove();
    }
    _img.clear();
    for (auto i : _buttonList)
        i.second->remove();
    _buttonList.clear();
    for (auto i : _text)
        i.second->remove();
    _text.clear();
}

void CharacterSelection::setup()
{
    _currentScene = PRELAUNCH;
    _env = _core.getDevice()->getGUIEnvironment();
    _skin = _env->getSkin();
    _font = _env->getFont("./media/Menu/bigfont.png");
    if (!_font)
        throw std::invalid_argument("<CharacterSelection>: Unable to set font");
    _skin->setFont(_font);
    _skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    _skin->setColor(gui::EGDC_BUTTON_TEXT, video::SColor(255,255,255,255));
    _core.getDevice()->setEventReceiver((_receiver = new CharacterSelectionEvent(_core.getJoystickState(), _core)));
    setupImg();
    setupButton();
}

void CharacterSelection::setupImg()
{
    _img["BG"] = _env->addImage(_core.getDriver()->getTexture("media/prelaunch/bg.png"), position2d<int>(0, 0));
    _img["P1"] = _env->addImage(_core.getDriver()->getTexture("media/prelaunch/bluebm.png"), position2d<int>(1350, 40));
    _img["P2"] = _env->addImage(_core.getDriver()->getTexture("media/prelaunch/redbm.png"), position2d<int>(370, 50));
    _img["P3"] = _env->addImage(_core.getDriver()->getTexture("media/prelaunch/greenbm.png"), position2d<int>(425, 560));
    _img["P4"] = _env->addImage(_core.getDriver()->getTexture("media/prelaunch/pinkbm.png"), position2d<int>(1300, 560));
}

void CharacterSelection::setupButton()
{
    _buttonList["L1"] = (_env->addButton(irr::core::recti(250, 425, 250 + 50, 425 + 50), 0, CharacterSelectionEvent::L1, L"<"));
    _buttonList["R1"] = (_env->addButton(irr::core::recti(650, 425, 650 + 50, 425 + 50), 0, CharacterSelectionEvent::R1, L">"));
    _buttonList["L2"] = (_env->addButton(irr::core::recti(1220, 425, 1220 + 50, 425 + 50), 0, CharacterSelectionEvent::L2, L"<"));
    _buttonList["R2"] = (_env->addButton(irr::core::recti(1620, 425, 1620 + 50, 425 + 50), 0, CharacterSelectionEvent::R2, L">"));
    _buttonList["L3"] = (_env->addButton(irr::core::recti(250, 920, 250 + 50, 920 + 50), 0, CharacterSelectionEvent::L3, L"<"));
    _buttonList["R3"] = (_env->addButton(irr::core::recti(650, 920, 650 + 50, 920 + 50), 0, CharacterSelectionEvent::R3, L">"));
    _buttonList["L4"] = (_env->addButton(irr::core::recti(1220, 920, 1220 + 50, 920 + 50), 0, CharacterSelectionEvent::L4, L"<"));
    _buttonList["R4"] = (_env->addButton(irr::core::recti(1620, 920, 1620 + 50, 920 + 50), 0, CharacterSelectionEvent::R4, L">"));
    _buttonList["PLAY"] = (_env->addButton(irr::core::recti(960 - 150, 515, 960 + 150, 515 + 50), 0, GAME, L"PLAY"));
}

const irr::core::recti CharacterSelection::center(playerM model, bool L, int y)
{
    if (L == true) {
        if (model == NONE_BIND)
            return (irr::core::recti(435, y, 435 + 150, y + 25));
        if (model == AI_BIND)
            return (irr::core::recti(460, y, 460 + 150, y + 25));
        return (irr::core::recti(390, y, 390 + 150, y + 25));
    } else {
        if (model == NONE_BIND)
            return (irr::core::recti(1400, y, 1385 + 150, y + 25));
        if (model == AI_BIND)
            return (irr::core::recti(1425, y, 1410 + 150, y + 25));
        return (irr::core::recti(1360, y, 1360 + 150, y + 25));
    }
}

void CharacterSelection::loop()
{
    irr::video::SColor _colorTxt = SColor(255, 255, 255, 255);
    if (_core.getDevice()->getEventReceiver() == nullptr) {
        std::cerr << "Event receiver is null\n";
        return;
    }
    while (_core.getDevice()->run() && _core.getDevice() && _receiver->getScene() == PRELAUNCH) {
		if (_core.getDevice()->isWindowActive()) {
			_core.getDriver()->beginScene(true, true, SColor(0, 100, 100, 100));
			_env->drawAll();
            _font->draw(_receiver->p1->getModel().c_str(), center(_receiver->p1->getType(), true, 435),_colorTxt);
            _font->draw(_receiver->p2->getModel().c_str(), center(_receiver->p2->getType(), false, 435), _colorTxt);
            _font->draw(_receiver->p3->getModel().c_str(), center(_receiver->p3->getType(), true, 930), _colorTxt);
            _font->draw(_receiver->p4->getModel().c_str(), center(_receiver->p4->getType(), false, 930), _colorTxt);
			_core.getDriver()->endScene();
		}
    }
    changeScene(_receiver->getScene());
}

void CharacterSelection::changeScene(const e_scene i)
{
    _currentScene = i;
}

CharacterSelection::e_scene CharacterSelection::getScene() const
{
    return (_currentScene);
}
