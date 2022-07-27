/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Priest
*/

#include <iostream>
#include "Priest.hpp"
#include "Character.hpp"

void Priest::Heal()
{
    setPower(getPower() - 10);
    if (getPower() <= 0) {
        setPower(0);
        return;
    }
    setPv(70 + getPv());
    if (getPv() >= 100)
        setPv(100);
    std::cout << getName() << " casts a little heal spell" << std::endl;
}

int Priest::CloseAttack()
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
    std::cout << getName() << " uses a spirit explosion" << std::endl;
    setRange(RANGE);
    return (10 + getSpirit());
}

Priest::Priest(const std::string &name, const int &level) : Character(name, level), Mage(name, level)
{
    setClass("Priest");
    setRace("Orc");
    setStrenght(3);
    setStamina(3);
    setSpirit(21);
    setIntelligence(42);
    setAgility(2);
    std::cout << getName() << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}