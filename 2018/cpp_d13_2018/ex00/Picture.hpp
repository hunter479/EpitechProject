/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
	#define PICTURE_HPP_

#include <string>

class Picture {
	public:
		Picture(const std::string &file = "");
		~Picture();
        bool getPictureFromFile(const std::string &file);
    public:
        std::string data;
	protected:
	private:
};

#endif /* !PICTURE_HPP_ */
