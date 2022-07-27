/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
	#define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
	public:
		KoalaNurse(std::string id);
		~KoalaNurse();
		std::string readReport(std::string filename);
		void	giveDrug(std::string drug, SickKoala *patient);
		void    timeCheck(void);
	private:
    	std::string id;
		bool	_work;
};

#endif /* !KOALANURSE_HPP_ */
