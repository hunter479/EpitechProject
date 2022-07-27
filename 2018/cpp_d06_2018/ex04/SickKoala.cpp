/*
** EPITECH PROJECT, 2019
** ex03
** File description:
** SickKoala
*/

#include <iostream>
#include <algorithm>
#include "SickKoala.hpp"

std::string    SickKoala::getName()
{
    return (name);
}

void    SickKoala::overDrive(std::string str)
{
    size_t  pos = -1;

    pos = str.find(kreog);
    while (pos != -1) {
        str.replace(pos, kreog.size(), "1337!");
        pos = str.find(kreog);
    }
    std::cout << str << std::endl;
    return;
}

bool   SickKoala::takeDrug(std::string s)
{
    std::string tmp = s;

    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    if (tmp.compare("mars") == 0) {
        std::cout << "Mr." << name << ": ";
        std::cout << "Mars, and it " << kreog << std::endl;
        return (true);
    } else if (s.compare("Buronzand") == 0) {
        std::cout << "Mr." << name << ": ";
        std::cout << "And you'll sleep right away!\n";
        return (true);
    } else {
        std::cout << "Mr." << name << ": ";
        std::cout << "Goer" << kreog << std::endl;
    }
    return (false);
}

void   SickKoala::poke(void)
{
    std::cout << "Mr." << name << ": ";
    std::cout << "Gooeeeeerrk!" << std::endl;
}

SickKoala::SickKoala(std::string s)
{
    name.assign(s);
    kreog.assign("Kreog!");
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name << ": ";
    std::cout << "Kreooogg!! I'm cuuuured!\n";
}
