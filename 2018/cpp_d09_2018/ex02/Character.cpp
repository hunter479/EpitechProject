/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** Character
*/

#include <string>
#include <iostream>
#include "Character.hpp"

void Character::TakeDamage(const int &damage)
{
    int pv = 0;

    setPv(getPv() - damage);
    pv = getPv();
    if (pv > 0)
        std::cout << getName() << " takes " << damage << " damage" << std::endl;
    if (pv <= 0) {
        std::cout << getName() << " out of combat" << std::endl;
        setPv(0);
        return;
    }
}

void Character::RestorePower()
{
    setPower(100);
    std::cout << getName() << " eats" << std::endl;
}

void Character::Heal()
{
    setPv(getPv() + 50);
    if (getPv() > 100)
        setPv(100);
    std::cout << getName() << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    if (getPv() <= 0)
        return (0);
    setPower(getPower() - 10);
    if (getPower() <= 0) {
        std::cout << getName() << " out of power" << std::endl;
        setPower(0);
        return (0);
    }
    std::cout << getName() << " tosses a stone" << std::endl;
    return (10 + getStrenght());
}

int Character::CloseAttack()
{
    if (getPv() <= 0)
        return (0);
    setPower(getPower() - 10);
    if (getPower() <= 0) {
        std::cout << getName() << " out of power" << std::endl;
        setPower(0);
        return (0);
    }
    std::cout << getName() << " strikes with a wooden stick" << std::endl;
    return (5 + getStrenght());
}

Character::Character(const std::string &name, const int &level)
{
    std::cout << name << " Created" << std::endl;
    Name = name;
    Lvl = level;
    Pv = 100;
    Power = 100;
    Strenght = 5;
    Stamina = 5;
    Intelligence = 5;
    Spirit = 5;
    Agility = 5;
    Range = CLOSE;
}

Character::~Character()
{
}
