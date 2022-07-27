/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
        #define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"
#include "Coconut.hpp"

class FruitBox {
    public:
        FruitBox(const int size);
        ~FruitBox();
        int nbFruits() const;
        bool putFruit (const Fruit *f);
        int getSize() const {return (_size);};
        Fruit *pickFruit();
        FruitNode *head() const {return (_node);};
    protected:
        FruitNode *_node;
        int _size;
    private:
};

#endif /* !FRUITBOX_HPP_ */
