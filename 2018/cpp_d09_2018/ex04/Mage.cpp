/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Mage
*/

#include <iostream>
#include "Mage.hpp"

int Mage::RangeAttack()
{
    if (getPv() <= 0)
        return (0);
    setPower(getPower() - 25);
    if (getPower() <= 0) {
        std::cout << getName() << " out of power" << std::endl;
        setPower(0);
        return (0);
    }
    std::cout << getName() << " launches a fire ball" << std::endl;
    setRange(CLOSE);
    return (20 + getSpirit());
}

int Mage::CloseAttack()
{
    if (getPv() <= 0)
        return (0);
    if (getRange() == RANGE)
        return (RangeAttack());
    setPower(getPower() - 10);
    if (getPower() <= 0) {
        std::cout << getName() << " out of power" << std::endl;
        setPower(0);
        return (0);
    }
    std::cout << getName() << " blinks" << std::endl;
    setRange(RANGE);
    return (0);
}

void Mage::RestorePower()
{
    setPower(50 + getIntelligence());
    std::cout << getName() << " takes a mana potion" << std::endl;
}

Mage::Mage(const std::string &name, const int &level) : Character(name, level)
{
    setClass("Mage");
    setRace("Gnome");
    setStrenght(6);
    setStamina(6);
    setIntelligence(12);
    setAgility(7);
    setSpirit(11);
    std::cout << getName() << " teleported" << std::endl;
}

Mage::~Mage()
{
}