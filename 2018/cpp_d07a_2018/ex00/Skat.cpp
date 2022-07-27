/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Skat
*/

#include <iostream>
#include "Skat.hpp"

void    Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stock;
    std::cout << " stimpaks remaining sir!" << std::endl;
}

void    Skat::useStimPaks()
{
    if (_stock > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        _stock--;
        return;
    } else
        std::cout << "Mediiiiiic" << std::endl;
}

void    Skat::addStimPaks(unsigned int number)
{
    if (number <= 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _stock += number;
}

void    Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stock) {
        std::cout << "Don't be greedy" << std::endl;
    } else {
        std::cout << "Keep the change." << std::endl;
        stock += number;
        _stock -= number;
    }
}

int  &Skat::stimPaks()
{
    return (_stock);
}

const   std::string &Skat::name()
{
    return (_name);
}

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stock = stimPaks;
}

Skat::~Skat()
{
}
