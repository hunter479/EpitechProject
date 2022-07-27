
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator() : _quantity(0)
{
}

void Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void Oxygenator::useOxygen(int quantity)
{
    LifeCriticalError err("Not enough oxygen to live.", "Oxygenator");
    MissionCriticalError err2("Not enough oxygen to continue the mission.", "Oxygenator");

    if (_quantity - quantity <= 5)
        throw err;
    if (_quantity - quantity <= 10)
        throw err2;
    _quantity -= quantity;
}
