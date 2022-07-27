/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** LittleHand
*/

#include <iostream>
#include "LittleHand.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

void  LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitBox tmp = FruitBox(unsorted.getSize());
    Fruit *fruit;
    bool oui = true;

    while (unsorted.nbFruits() > 0) {
        fruit = unsorted.pickFruit();
        if (dynamic_cast<Lime *> (fruit)  && limes.getSize() > limes.nbFruits())
            oui = limes.putFruit(fruit);
        else if (dynamic_cast<Lemon *> (fruit) && lemons.getSize() > lemons.nbFruits())
            oui = lemons.putFruit(fruit);
        else if (dynamic_cast<Banana *> (fruit) && bananas.getSize() > bananas.nbFruits())
            bananas.putFruit(fruit);
        else
            tmp.putFruit(fruit);
        if (oui == false)
            tmp.putFruit(fruit);
    }
    unsorted = tmp;
}

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}
