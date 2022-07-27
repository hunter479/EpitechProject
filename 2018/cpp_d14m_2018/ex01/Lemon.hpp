/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
	#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit{
	public:
		Lemon();
		~Lemon();
        std::string getName() const {return (_name);};
        const int &getVitamins() const {return (_vitamins);};
	protected:
	private:
};

#endif /* !LEMON_HPP_ */
