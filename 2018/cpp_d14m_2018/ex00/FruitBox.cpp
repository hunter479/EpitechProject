/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** FruitBox
*/

#include <iostream>
#include "FruitBox.hpp"
#include "FruitNode.hpp"

static bool instanceExist(FruitNode *fd, Fruit *f)
{
    FruitNode *tmp = fd;

    while (tmp) {
        if (tmp->getFruit() == f)
            return (true);
        tmp = tmp->next;
    }
    return (false);
}

FruitNode::FruitNode(Fruit *f)
{
    if (f != nullptr)
        _f = f;
    next = nullptr;
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *first = (this->_node);
    FruitNode *nextNode = (this->_node) ? (this->_node)->next : nullptr;

    if (this->_node == nullptr)
        return (nullptr);
    if (first)
        first->next = nullptr;
    this->_node = nextNode;
    return (first->getFruit());
}

int FruitBox::nbFruits() const
{
    FruitNode *tmp = this->_node;
    int a = 0;

    while (tmp) {
        tmp = tmp->next;
        a++;
    }
    return (a);
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *elem = new FruitNode(f);
    FruitNode *index = this->_node;
    int nb = 1;

    if (f == nullptr)
        return (false);
    if (index == nullptr) {
        this->_node = elem;
        return (true);
    }
    if (instanceExist(index, f) == true)
        return (false);
    while (index->next && nb++ < _size)
        index = index->next;
    if (nb >= _size)
        return (false);
    index->next = elem;
    return (true);
}

FruitBox::FruitBox(const int size)
{
    _size = size;
    _node = nullptr;
}

FruitBox::~FruitBox()
{
}
