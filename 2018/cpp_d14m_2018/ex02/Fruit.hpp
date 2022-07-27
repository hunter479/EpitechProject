/*
** EPITECH PROJECT, 2019
** cpp_d14m_2018
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
	#define FRUIT_HPP_

#include <string>

class Fruit {
	public:
		Fruit();
		virtual ~Fruit();
        virtual std::string getName() const = 0;
        virtual const int &getVitamins() const = 0;
	protected:
	        int _vitamins;
	        std::string _name;
	private:
};

#endif /* !FRUIT_HPP_ */
