/*
** EPITECH PROJECT, 2019
** cpp_d08_2018
** File description:
** Droid
*/

#include <iostream>
#include <string>
#include "Droid.hpp"

std::ostream &operator<<(std::ostream &os, const Droid &droid)
{
    os << "Droid '"<< droid.getId() << "', ";
    os << *droid.getStatus() << ", " << droid.getEnergy();
    return (os);
}

const Droid &Droid::operator=(const Droid &other)
{
    if (this != &other) {
        Id = other.Id;
        this->Energy = other.Energy;
        delete Status;
        this->Status = new std::string(*other.getStatus());
    }
    return (*this);
}

bool Droid::operator!=(const Droid &other) const
{
    if (other.getStatus() != Status)
        return (true);
    return (false);
}

bool Droid::operator==(const Droid &other) const
{
    if (other.getStatus() != Status)
        return (false);
    return (true);
}

void Droid::operator<<(size_t &eng)
{
    size_t diff = 100 - Energy;

    if (Energy + eng >= 100) {
        Energy = 100;
        eng -= diff;
    } else if (Energy + eng < 100) {
        Energy += eng;
        eng = 0;
    }
}

void Droid::setId(const std::string str)
{
    Id = str;
}

void Droid::setStatus(const std::string *value)
{
    Status = new std::string(value->c_str());
}


void Droid::setEnergy(const size_t &value)
{
    Energy = value;
}

const std::string *Droid::getStatus() const
{
    return (Status);
}

const size_t &Droid::getToughness() const
{
    return (Toughness);
}

const size_t &Droid::getEnergy() const
{
    return (Energy);
}

const size_t &Droid::getAttack() const
{
    return (Attack);
}

const std::string &Droid::getId() const
{
    return (this->Id);
}

Droid::Droid(const std::string &serial) : Attack(25), Toughness(25)
{
    _BattleData = new DroidMemory();
    Id.assign(serial);
    Energy = 50;
    Status = new std::string("Standing by");
    std::cout << "Droid '" << Id << "' Activated\n";
}

Droid::Droid(const Droid &n) : Attack(n.getAttack()), Toughness(n.getToughness())
{
    _BattleData = new DroidMemory();
    Id.assign(n.Id);
    Energy = n.getEnergy();
    Status = new std::string(*n.getStatus());
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '"<< Id << "' Destroyed" << std::endl;
    delete _BattleData;
    delete Status;
}
