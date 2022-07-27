/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** Bord
*/

#include "Destination.hpp"
#include "Borg.hpp"

bool    Borg::Ship::move(int warp, Destination d)
{
    if (warp > _maxWarp || d == _location)
        return (false);
    if (_core->checkReactor()->isStable() != true)
        return (false);
    _location = d;
    return (true);
}

bool    Borg::Ship::move(int warp)
{
    if (warp > _maxWarp)
        return (false);
    if (_core->checkReactor()->isStable() != true)
        return (false);
    _location = _home;
    return (true);
}

bool    Borg::Ship::move(Destination d)
{
    if (_core->checkReactor()->isStable() != true)
        return (false);
    if (d == _location)
        return (false);
    _location = d;
    return (true);
}

bool    Borg::Ship::move(void)
{
    if (_core->checkReactor()->isStable() == false)
        return (false);
    _location = _home;
    return (true);
}

void    Borg::Ship::checkCore()
{
    if (_core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order.\n";
    else
        std::cout << "Critical failure imminent\n";
}

void    Borg::Ship::setupCore(WarpSystem::Core *pointer)
{
    _core = pointer;
}

Borg::Ship::Ship(void)
{
    _lenght = 300;
    _maxWarp = 9;
    _home = UNICOMPLEX;
    _location = _home;
    std::cout << "We are the Borgs. Lower your shields and ";
    std::cout << "surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and";
    std::cout << " technologies will be assimilated.\n";
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}
