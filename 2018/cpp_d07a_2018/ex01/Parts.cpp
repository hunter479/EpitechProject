/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** Parts
*/

#include <iostream>
#include "Parts.hpp"

std::string Arms::serial(void) const
{
    return (_serial);
}

bool Arms::isFunctionnal(void) const
{
    return (_functionnal);
}

void Arms::informations(void) const
{
    std::cout << "\t[Parts] Arms "  << _serial << " status : ";
    if (_functionnal == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}

Arms::Arms(const std::string &serial, bool functionnal)
{
    _serial = serial;
    _functionnal = functionnal;
}

Arms::~Arms()
{
}

std::string Legs::serial(void) const
{
    return (_serial);
}

bool Legs::isFunctionnal(void) const
{
    return (_functionnal);
}

void Legs::informations(void) const
{
    std::cout << "\t[Parts] Legs "  << _serial << " status : ";
    if (_functionnal == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}

Legs::Legs(const std::string &serial, bool functionnal)
{
    _serial = serial;
    _functionnal = functionnal;
}

Legs::~Legs()
{
}

std::string Head::serial(void) const
{
    return (_serial);
}

bool Head::isFunctionnal(void) const
{
    return (_functionnal);
}

void Head::informations(void) const
{
    std::cout << "\t[Parts] Head "  << _serial << " status : ";
    if (_functionnal == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}

Head::Head(const std::string &serial, bool functionnal)
{
    _serial = serial;
    _functionnal = functionnal;
}

Head::~Head()
{
}
