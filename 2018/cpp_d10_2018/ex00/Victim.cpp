/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Victim
*/

#include <iostream>
#include "Victim.hpp"

void Victim::getPolymorphed() const
{
    std::cout << getName() << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Victim &ref)
{
    os << "I'm " << ref.getName() << " and i like otters!" << std::endl;
    return (os);
}

Victim::Victim(const std::string &name)
{
    _name.assign(name);
    std::cout << "Some random victim called " << getName() << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << getName() << " just died for no apparent reason!" << std::endl;
}
