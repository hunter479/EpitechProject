/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Woody
*/

#include "Woody.hpp"

bool Woody::speak(const std::string &state)
{
    std::cout << "WOODY: ";
    std::cout << getName() << " \"" << state << '"' << std::endl;
    return (true);
}

Woody::~Woody()
{
}
