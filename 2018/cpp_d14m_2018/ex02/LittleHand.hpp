/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
	#define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Coconut.hpp"

class LittleHand {
	public:
		LittleHand();
		~LittleHand();
        static void  sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
		static FruitBox * const *organizeCoconut(Coconut  const * const *coconuts);
	protected:
	private:
};

#endif /* !LITTLEHAND_HPP_ */
