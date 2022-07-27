/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** Toy
*/

#include "Toy.hpp"

const Toy &Toy::operator=(const Toy &other)
{
    if (this != &other) {
        this->_picture = other._picture;
        _name = other._name;
        _type = other._type;
    }
    return (*this);
}

bool Toy::setAscii(const std::string &filename)
{
    return (_picture.getPictureFromFile(filename));
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    _type = type;
    _name.assign(name);
    _picture = Picture(file);
}

Toy::Toy(const Toy &other)
{
    *this = other;
}

Toy::~Toy()
{
}
