/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** KoalaBot
*/

#include <iostream>
#include "KoalaBot.hpp"
#include "Parts.hpp"

bool KoalaBot::status() const
{
    if (_legs.isFunctionnal() == false)
        return (false);
    if (_head.isFunctionnal() == false || _arms.isFunctionnal() == false)
        return (false);
    return (true);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

void KoalaBot::swapParts(Arms &a)
{
    Arms tmp = _arms;

    _arms = a;
    a = tmp;
}

void KoalaBot::swapParts(Legs &a)
{
    Legs tmp = _legs;

    _legs = a;
    a = tmp;
}

void KoalaBot::swapParts(Head &a)
{
    Head tmp = _head;

    _head = a;
    a = tmp;
}

void KoalaBot::setParts(const Arms &a)
{
    _arms = a;
}

void KoalaBot::setParts(const Legs &a)
{
    _legs = a;
}

void KoalaBot::setParts(const Head &a)
{
    _head = a;
}

KoalaBot::KoalaBot(std::string serial)
{
    _serial = serial;
}

KoalaBot::~KoalaBot()
{
}
