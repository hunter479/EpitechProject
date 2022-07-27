/*
** EPITECH PROJECT, 2019
** ex03
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
	#define SICKKOALA_HPP_

#include <string>

class SickKoala {
	public:
		SickKoala(std::string s);
		~SickKoala();
                void    poke();
                void    overDrive(std::string str);
                bool   takeDrug(std::string s);
                std::string getName();
	private:
                std::string name;
                std::string kreog;
};

#endif /* !SICKKOALA_HPP_ */
