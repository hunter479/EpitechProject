/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Woody
*/

#ifndef WOODy_HPP_
	#define WOODy_HPP_

#include <iostream>
#include "Toy.hpp"

class Woody : public Toy{
	public:
    	Woody(const std::string &name, const std::string &filename = "woody.txt") : Toy(WOODY, name, filename) {};
		~Woody();
		bool speak(const std::string &);
	protected:
	private:
};

#endif /* !WOODy_HPP_ */
