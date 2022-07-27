/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
        #define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        FruitNode(const Fruit *f);
        ~FruitNode() {};
        Fruit *getFruit() const {return (_f);};
        void setFruit(Fruit *f) {_f = f;};
        FruitNode *next;
    protected:
        Fruit *_f;
    private:
};

#endif /* !FRUITNODE_HPP_ */
