/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Peon
*/

#include <iostream>
#include "Peon.hpp"

void Peon::getPolymorphed() const
{
    std::cout << getName() << " has been turned into a pink pony!" <<  std::endl;
}

Peon::Peon(const std::string &name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}
