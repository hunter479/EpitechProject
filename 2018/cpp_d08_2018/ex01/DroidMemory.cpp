/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** DroidMemory
*/

#include <iostream>

#include "DroidMemory.hpp"

std::ostream &operator<<(std::ostream &os, const DroidMemory &droid)
{
    os << "DroidMemory '" << droid.getFingerPrint() << "', ";
    os << droid.getExp();
    return (os);
}

DroidMemory *DroidMemory::getBattleData() const
{
    return (_BattleData);
}
void DroidMemory::setBattleData(const DroidMemory *value)
{
    _BattleData = new DroidMemory(*value);
}

DroidMemory &DroidMemory::operator+(const DroidMemory &value)
{
    DroidMemory *droid = new DroidMemory();

    *droid += *this;
    *droid += value;
    return (*droid);
}

DroidMemory &DroidMemory::operator+(const size_t &value)
{
    DroidMemory *droid = new DroidMemory();

    *droid += value;
    return (*droid);
}

void DroidMemory::operator+=(const size_t &value)
{
    _Exp += value;
    setFingerPrint(value ^ getFingerPrint());
}

void DroidMemory::operator<<(const DroidMemory &other)
{
    _Exp += other.getExp();
    setFingerPrint(_FingerPrint ^ other.getFingerPrint());
}

void DroidMemory::operator>>(DroidMemory &other)
{
    size_t aaa = _Exp;

    aaa += other.getExp();
    other.setExp(aaa);
    other.setFingerPrint(other.getFingerPrint() ^ _FingerPrint);
}

void DroidMemory::operator+=(const DroidMemory &droid)
{
    *this << droid;
}

void DroidMemory::setFingerPrint(const size_t &value)
{
    _FingerPrint = value;
}

const size_t &DroidMemory::getFingerPrint() const
{
    return (_FingerPrint);
}

void DroidMemory::setExp(const size_t &value)
{
    _Exp = value;
}

const size_t &DroidMemory::getExp() const
{
    return (_Exp);
}

DroidMemory::DroidMemory()
{
    _Exp = 0;
    _FingerPrint = std::rand();
}

DroidMemory::DroidMemory(const DroidMemory &droid)
{
    _Exp = droid.getExp();
    _FingerPrint = droid.getFingerPrint();
}

DroidMemory::~DroidMemory()
{
}
