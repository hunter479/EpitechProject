/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, const int &level) : Character(name, level), Mage(name, level), Warrior(name, level), Priest(name, level)
{
    setName(name);
    setClass("Paladin");
    setLvl(level);
    setRace("Human");
    setStrenght(9);
    setStamina(10);
    setIntelligence(10);
    setSpirit(10);
    setAgility(2);
    std::cout<< "the light falls on " << name << std::endl;
}

Paladin::~Paladin()
{
}
