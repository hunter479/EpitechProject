/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Federation
*/

#include <iostream>
#include "Destination.hpp"
#include "Federation.hpp"

bool    Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp > _maxWarp || d == _location)
        return (false);
    if (_core->checkReactor()->isStable() != true)
        return (false);
    _location = d;
    return (true);
}

bool    Federation::Starfleet::Ship::move(int warp)
{
    if (warp > _maxWarp)
        return (false);
    if (_core->checkReactor()->isStable() != true)
        return (false);
    _location = _home;
    return (true);
}

bool    Federation::Starfleet::Ship::move(Destination d)
{
    if (_core->checkReactor()->isStable() != true)
        return (false);
    if (d == _location)
        return (false);
    _location = d;
    return (true);
}

bool    Federation::Starfleet::Ship::move(void)
{
    if (_core->checkReactor()->isStable() == false)
        return (false);
    _location = _home;
    return (true);
}

bool    Federation::Ship::move(int warp, Destination d)
{
    if (warp > _maxWarp || d == _location)
        return (false);
    if (_core->checkReactor()->isStable() != true)
        return (false);
    _location = d;
    return (true);
}

bool    Federation::Ship::move(int warp)
{
    if (warp > _maxWarp)
        return (false);
    if (_core->checkReactor()->isStable() != true)
        return (false);
    _location = _home;
    return (true);
}

bool    Federation::Ship::move(Destination d)
{
    if (_core->checkReactor()->isStable() != true)
        return (false);
    if (d == _location)
        return (false);
    _location = d;
    return (true);
}

bool    Federation::Ship::move(void)
{
    if (_core->checkReactor()->isStable() == false)
        return (false);
    _location = _home;
    return (true);
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " + _name + ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

void    Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *c)
{
    _captain = c;
    std::cout << _captain->getName() << ": I'm glad to be the ";
    std::cout << "captain of the USS " << _name << "." << std::endl;
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (_age);
}

void    Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
    _age = 0;
}

Federation::Starfleet::Captain::~Captain()
{
}

void    Federation::Ship::checkCore()
{
    std::cout << _name << ": The core is ";
    if (_core->checkReactor()->isStable() == true)
        std::cout << "stable ";
    else
        std::cout << "unstable ";
    std::cout << "at the time.\n";
}

void    Federation::Ship::setupCore(WarpSystem::Core *pointer)
{
    std::cout << _name << ": The core is set.\n";
    _core = pointer;
}

Federation::Ship::Ship(int l, int w, std::string n)
{
    _lenght = l;
    _width = w;
    _name = n;
    _maxWarp = 1;
    _home = VULCAN;
    _location = _home;
    std::cout << "The independant ship " << n << " just finished ";
    std::cout << "its construction." << std::endl;
    std::cout << "It is " << l << " m in length and " << w;
    std::cout << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void    Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << _name << ": The core is ";
    if (_core->checkReactor()->isStable() == true)
        std::cout << "stable ";
    else
        std::cout << "unstable ";
    std::cout << "at the time.\n";
}

void    Federation::Starfleet::Ship::setupCore(WarpSystem::Core *pointer)
{
    std::cout << "USS " << _name << ": The core is set.\n";
    _core = pointer;
}

Federation::Starfleet::Ship::Ship(int l, int w, std::string n, short maxWarp)
{
    _lenght = l;
    _width = w;
    _name = n;
    _maxWarp = maxWarp;
    _home = EARTH;
    _location = _home;
    std::cout << "The ship USS " << n << " has been finished." << std::endl;
    std::cout << "It is " << l << " m in length and " << w;
    std::cout << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp <<"!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}