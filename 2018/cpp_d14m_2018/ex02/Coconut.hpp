/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
	#define COCONUT_HPP_

#include "Fruit.hpp"
#include "FruitBox.hpp"

class Coconut : public Fruit{
	public:
		Coconut();
		~Coconut();
        std::string getName() const {return (_name);};
        const int &getVitamins() const {return (_vitamins);};
	protected:
	private:
};

#endif /* !COCONUT_HPP_ */
