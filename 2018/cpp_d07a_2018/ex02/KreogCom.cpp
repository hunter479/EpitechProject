/*
** EPITECH PROJECT, 2019
** cpp_d07a_2018
** File description:
** KreogCom
*/

#include <string>
#include <iostream>
#include "KreogCom.hpp"

void KreogCom::locateSquad() const
{
    KreogCom *n = this->_next;

    if (this == nullptr|| this->_next == nullptr)
        return;
    while (n) {
        n->ping();
        n = n->_next;
    }
    if (this)
        this->ping();
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << m_serial << "currently at ";
    std::cout << _x + " " + _y << std::endl;
}

KreogCom *KreogCom::getCom()
{
    if (_next != nullptr)
        return (_next);
    return (nullptr);
}

void KreogCom::removeCom()
{
    KreogCom *tmp = this->_next;

    if (tmp && tmp->_next)
        this->_next = tmp->_next;
    if (tmp && tmp->_next == nullptr)
        this->_next = nullptr;
    if (tmp)
        delete tmp;
}

void KreogCom::addCom(int x, int y, const int serial)
{
    KreogCom *index = this->_next;
    KreogCom *tmp = new KreogCom(x, y, serial);

    if (this->_next == nullptr) {
        this->_next = tmp;
    } else {
        tmp->_next = index;
        this->_next = tmp;
    }
}

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), m_serial(serial)
{
    std::cout << "KreogCom " << serial << " initialized\n";
    _next = nullptr;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down\n";
}
