/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** Toy
*/

#include <iostream>
#include "Toy.hpp"

Toy &Toy::operator<<(const std::string str)
{
    _picture.data = str;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Toy &other)
{
    os << other.getName() << std::endl;
    os << other.getAscii() << std::endl;
    return (os);
}

const Toy &Toy::operator=(const Toy &other)
{
    if (this != &other) {
        this->_picture = other._picture;
        _name = other._name;
        _type = other._type;
    }
    return (*this);
}

bool Toy::speak(const std::string &state)
{
    std::cout << getName() << " \"" << state << "\"" << std::endl;
    return (true);
}

bool Toy::setAscii(const std::string &filename)
{
    return(_picture.getPictureFromFile(filename));
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    _type = type;
    _name.assign(name);
    _picture = Picture(file);
}

Toy::~Toy()
{
}
