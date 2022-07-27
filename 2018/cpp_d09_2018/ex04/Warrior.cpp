/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Warrior
*/

#include <iostream>
#include "Warrior.hpp"

int Warrior::RangeAttack()
{
    if (getPv() <= 0)
        return (0);
    if (getRange() == CLOSE)
        return (CloseAttack());
    setPower(getPower() - 10);
    if (getPower() <= 0) {
        std::cout << getName() << " out of power" << std::endl;
        setPower(0);
        return (0);
    }
    std::cout << getName() << " intercepts" << std::endl;
    Range = CLOSE;
    return (0);
}

int Warrior::CloseAttack()
{
    if (getPv() <= 0)
        return (0);
    setPower(getPower() - 30);
    if (getPower() <= 0) {
        std::cout << getName() << " out of power" << std::endl;
        setPower(0);
        return (0);
    }
    std::cout << getName() << " strikes with his " << weaponName;
    std::cout << std::endl;
    Range = CLOSE;
    return (20 + getStrenght());
}

Warrior::Warrior(const std::string &name, const int &level) : Character(name, level), weaponName("hammer")
{
    setClass("Warrior");
    setRace("Dwarf");
    setStrenght(12);
    setStamina(12);
    setIntelligence(6);
    setAgility(7);
    std::cout << "I'm "<< getName();
    std::cout << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}