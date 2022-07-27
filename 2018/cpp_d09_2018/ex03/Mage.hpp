/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Mage
*/

#ifndef MAGE_HPP_
	#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character {
	public:
		Mage(const std::string &, const int &);
		virtual ~Mage();
		int CloseAttack();
		int RangeAttack();
		void RestorePower();
	protected:
	private:
};

#endif /* !MAGE_HPP_ */
