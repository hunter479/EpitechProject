/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MapGen
*/

#ifndef MAPGEN_HPP_
#define MAPGEN_HPP_

#include <vector>
#include <string>

#define BOX '1'
#define GRA '0'

class MapGen {
	public:
		MapGen(); // Throw a std::vector<std::string>
		~MapGen();

	protected:
	private:
		const std::string mapPattern1();
		const std::string mapPattern2();
		const char doPutBox(const int modulo, const int check);
        std::vector<std::string> putBox(const std::string map);
};

#endif /* !MAPGEN_HPP_ */
