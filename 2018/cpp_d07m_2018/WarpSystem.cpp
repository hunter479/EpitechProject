/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** WarpSystem
*/

#include <iostream>
#include "WarpSystem.hpp"
#include "Federation.hpp"

WarpSystem::QuantumReactor  *WarpSystem::Core::checkReactor(void)
{
    return (_coreReactor);
}

WarpSystem::Core::Core(QuantumReactor *core)
{
    _coreReactor = core;
}

void    WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

bool    WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}
