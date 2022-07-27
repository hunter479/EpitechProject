/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
	#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
	public:
		Buzz(const std::string &name, const std::string &filename = "buzz.txt") : Toy(BUZZ, name, filename) {};
		~Buzz();
	protected:
	private:
};

#endif /* !BUZZ_HPP_ */
