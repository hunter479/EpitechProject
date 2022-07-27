/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Buzz
*/

#include <iostream>
#include "Buzz.hpp"

bool Buzz::speak_es(const std::string &state)
{
    std::cout << "BUZZ: ";
    std::cout << getName() << " senorita \"" << state << "\" senorita" << std::endl;
    return (true);
}

bool Buzz::speak(const std::string &state)
{
    std::cout << "BUZZ: ";
    std::cout << getName() << " \"" << state << "\"" << std::endl;
    return (true);
}

Buzz::~Buzz()
{
}
