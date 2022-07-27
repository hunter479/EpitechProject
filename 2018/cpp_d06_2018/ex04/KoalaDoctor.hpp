/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
	#define KOALADOCTOR_HPP_

#include <iostream>
#include "KoalaNurse.hpp"

class KoalaDoctor {
	public:
		KoalaDoctor(std::string name);
		~KoalaDoctor();
		void	diagnose(SickKoala *patient);
		void    timeCheck(void);
	private:
		std::string	name;
		std::string	tab[5];
		bool	_work;
};

#endif /* !KOALADOCTOR_HPP_ */
