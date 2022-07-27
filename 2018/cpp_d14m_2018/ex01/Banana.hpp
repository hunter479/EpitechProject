/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** Banana
*/

#ifndef BANANA_HPP_
	#define BANANA_HPP_

#include <string>
#include "Fruit.hpp"

class Banana : public Fruit{
	public:
		Banana();
		~Banana();
        std::string getName() const {return (_name);};
        const int &getVitamins() const {return (_vitamins);};
	protected:
	private:
};

#endif /* !BANANA_HPP_ */
