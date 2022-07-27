/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Sorcerer
*/

#include <iostream>
#include "Sorcerer.hpp"

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &ref)
{
    os << "I am " << ref.getName() << ", "<< ref.getTitle() << ", and I like ponies!" << std::endl;
    return (os);
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
{
    _name.assign(name);
    _title.assign(title);
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead.";
    std::cout << " Consequences will never be the same!" <<std::endl;
}
