/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Peon
*/

#ifndef PEON_HPP_
	#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon(const std::string &);
		~Peon();
		void getPolymorphed() const;
	protected:
	private:
};

#endif /* !PEON_HPP_ */
