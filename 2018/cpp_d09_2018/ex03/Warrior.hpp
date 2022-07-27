/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
	#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character {
	public:
		Warrior(const std::string &, const int &);
		~Warrior();
		int CloseAttack();
		int RangeAttack();
	protected:
	private:
		const std::string weaponName;
};

#endif /* !WARRIOR_HPP_ */
