/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#include <stdexcept>
#include <sys/types.h>
#ifndef WIN32
	#include <dirent.h>
#endif
#include "Menu.hpp"

Menu::Menu(Core &core) : _core(core)
{
    setup();
    loop();
}

Menu::~Menu()
{
    if (_img != nullptr) {
        _img->remove();
        _img = nullptr;
    }
    for (auto i : _buttonList)
        i.second->remove();
    _buttonList.clear();
}

#ifndef WIN32
	const bool Menu::isSaveCreated(void) const
	{
		DIR *dir;
		struct dirent *ent;
		std::string save("save.txt");

		if ((dir = opendir ("./")) != NULL) {
			while ((ent = readdir (dir)) != NULL) {
				if (save.compare(ent->d_name) == 0)
					return true;
			}
			closedir (dir);
		}
		return false;
	}
#endif

void Menu::setupButton()
{
    _buttonList["CONTINUE"] = (_env->addButton(irr::core::rect<irr::s32>(960 - 250, 440, 960 + 250, 440 + 50), 0, LOAD_GAME, L"CONTINUE"));
    _buttonList["NEW GAME"] = (_env->addButton(irr::core::rect<irr::s32>(960 - 250, 540, 960 + 250, 540 + 50), 0, PRELAUNCH, L"NEW GAME"));
    _buttonList["QUIT"] = (_env->addButton(irr::core::rect<irr::s32>(960 - 250, 640, 960 + 250, 640 + 50), 0, QUIT, L"QUIT"));
    _buttonList["CREDITS"] = (_env->addButton(irr::core::rect<irr::s32>(1920 - 200, 940, 1920 - 50, 940 + 50), 0, CREDITS, L"CREDITS"));
	#ifdef WIN32
		_buttonList["CONTINUE"]->setEnabled(false);
	#endif
	#ifndef WIN32
		_buttonList["CONTINUE"]->setEnabled(isSaveCreated());
	#endif
}

void Menu::setup()
{
    _currentScene = MENU;
    _env = _core.getDevice()->getGUIEnvironment();
    _skin = _env->getSkin();
    _font = _env->getFont("./media/Menu/bigfont.png");
    if (!_font)
        throw std::invalid_argument("<Menu>: Unable to set font");
    _skin->setFont(_font);
    _skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, video::SColor(255,255,255,255));
	_context.device = _core.getDevice();
	_context.counter = 0;
    _img = _env->addImage(_core.getDriver()->getTexture("media/Menu/bomberman_bg.png"), position2d<int>(0,0));
    setupButton();
    _receiver = new MenuEvent(_context, _core);
    _core.getDevice()->setEventReceiver(_receiver);
}

void Menu::loop()
{
    if (_core.getDevice()->getEventReceiver() == nullptr) {
        std::cerr << "Event receiver is null\n";
        return;
    }
    while (_core.getDevice()->run() && _core.getDevice() && _receiver->getScene() == MENU) {
		if (_core.getDevice()->isWindowActive()) {
			_core.getDriver()->beginScene(true, true, irr::video::SColor(0, 100, 100, 100));
			_env->drawAll();
			_core.getDriver()->endScene();
		}
    }
    changeScene(_receiver->getScene());
}

void Menu::changeScene(const e_scene i)
{
    _currentScene = i;
}

Menu::e_scene Menu::getScene() const
{
    return (_currentScene);
}
