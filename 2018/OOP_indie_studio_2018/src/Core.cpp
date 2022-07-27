/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Core
*/

#include "Core.hpp"
#include "EventReceiver.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Core::Core() : _isLoaded(false)
{
    bindMap();
	const dimension2d<u32> dim = dimension2d<u32>(1920, 1080);
	_receiver = nullptr;
	_device = createDevice(EDT_OPENGL, dim, 16, false, false, false, _receiver);
	_driver = _device->getVideoDriver();
	_smgr = _device->getSceneManager();
	_guienv = _device->getGUIEnvironment();
	_isController = false;
    // JOYSTICK ACTIVATION
	_device->activateJoysticks(_joystickInfo);
	if (_joystickInfo.size() > 0)
		_isController = true;
}

Core::~Core()
{
}

void    Core::bindMap(void)
{
    _bindSoon[38] = KEY_UP;
    _bindSoon[40] = KEY_DOWN;
    _bindSoon[37] = KEY_LEFT;
    _bindSoon[39] = KEY_RIGHT;
    _bindSoon[90] = KEY_KEY_Z;
    _bindSoon[83] = KEY_KEY_S;
    _bindSoon[81] = KEY_KEY_Q;
    _bindSoon[68] = KEY_KEY_D;
    _bindSoon[80] = KEY_KEY_P;
    _bindSoon[32] = KEY_SPACE;
    _bindSoon[13] = KEY_RETURN;
}

std::string     Core::keysToString(bind_t keys)
{
    std::string to_save;

    to_save.append(std::to_string(keys.ai));
    to_save.append(" " + std::to_string(keys.none));
    to_save.append(" " + std::to_string(keys.up));
    to_save.append(" " + std::to_string(keys.down));
    to_save.append(" " + std::to_string(keys.left));
    to_save.append(" " + std::to_string(keys.right));
    to_save.append(" " + std::to_string(keys.drop));
    return to_save;
}

bind_t  Core::stringToKeys(std::string &keys)
{
    bind_t to_ret;
    std::string test;
    std::stringstream ssin(keys);

    ssin >> test;
    to_ret.ai = stoi(test);
    ssin >> test;
    to_ret.none = stoi(test);
    ssin >> test;
    to_ret.up = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.down = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.left = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.right = _bindSoon[std::stoi(test)];
    ssin >> test;
    to_ret.drop = _bindSoon[std::stoi(test)];
    return to_ret;
}

void	Core::updateSave(const std::vector<std::string> &map, const std::list<struct s_save> &info)
{
	_save.saveMap(map);
	_save.saveCharacters(info);
}

void	Core::displaySave(void)
{
	_save.display();
}