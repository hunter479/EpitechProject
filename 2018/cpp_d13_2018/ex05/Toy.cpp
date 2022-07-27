/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** Toy
*/

#include <iostream>
#include "Toy.hpp"

const Toy::Error Toy::getLastError()
{
    return (err);
}

Toy &Toy::operator<<(std::string str)
{
    _picture.data = str;
    return (*this);
}

const std::string Toy::Error::where() const
{
    if (getType() == PICTURE)
        return ("setAscii");
    else if (getType() == SPEAK)
        return ("speak_es");
    else
        return ("");
}

const std::string Toy::Error::what() const
{
    if (getType() == SPEAK)
        return ("wrong mode");
    else if (getType() == PICTURE)
        return ("bad new illustration");
    else
        return ("");
}

std::ostream &operator<<(std::ostream &os, const Toy &other)
{
    os << other.getName() << std::endl;
    os << other.getAscii() << std::endl;
    return (os);
}

Toy &Toy::operator=(const Toy &other)
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
    bool a = _picture.getPictureFromFile(filename);

    if (a == false)
        err.setType(Error::PICTURE);
    return (a);
}

bool Toy::speak(const std::string &state)
{
    std::cout << getName() << " \"" << state << "\"" << std::endl;
    return (true);
}


Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    _type = type;
    _name.assign(name);
    err = Error();
    _picture = Picture(file);
}

Toy::~Toy()
{
}
