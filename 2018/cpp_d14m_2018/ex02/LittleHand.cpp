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

FruitBox * const *LittleHand::organizeCoconut(Coconut  const * const *coconuts)
{
    int a = 0;
    int x = 0;
    int z = 0;
    int total = 0;
    FruitBox **store;

    for (; coconuts[a]; a++, total++);
    a = (a % 6 == 0) ? (a  / 6) + 1 : (a / 6) + 2;
    store = new FruitBox*[a];
    while (z < total) {
        store[x] = new FruitBox(6);
        for (int nb = 0; nb < 6; nb++) {
            store[x]->putFruit(coconuts[z]);
            z++;
        }
        x++;
    }
    store[x] = nullptr;
    return (store);
}

void  LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitBox tmp = FruitBox(unsorted.getSize());
    const Fruit *fruit;
    bool    oui = true;

    while (unsorted.nbFruits() > 0) {
        fruit = unsorted.pickFruit();
        if (dynamic_cast<const Lime *> (fruit))
            oui = limes.putFruit(fruit);
        else if (dynamic_cast<const Lemon *> (fruit))
            oui = lemons.putFruit(fruit);
        else if (dynamic_cast<const Banana *> (fruit))
            oui = bananas.putFruit(fruit);
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
