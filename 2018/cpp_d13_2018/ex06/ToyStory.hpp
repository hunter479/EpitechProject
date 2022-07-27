/*
** EPITECH PROJECT, 2019
** ex06
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
	#define TOYSTORY_HPP_

#include <string>
#include "Toy.hpp"

class ToyStory {
	public:
		ToyStory();
		~ToyStory();
        static void tellMeAStory(const std::string &filename, Toy &toy1, bool (Toy::*func1)(const std::string &str1), Toy &toy2, bool (Toy::*func2)(const std::string &str2));
    protected:
	private:
};

#endif /* !TOYSTORY_HPP_ */
