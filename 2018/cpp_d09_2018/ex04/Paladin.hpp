/*
** EPITECH PROJECT, 2019
** cpp_d09_2018
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
	#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest{
	public:
		Paladin(const std::string &name, const int &level);
		~Paladin();
        int CloseAttack() {return (Warrior::CloseAttack());};
        int RangeAttack() {return (Priest::RangeAttack());};
        void Heal() {Priest::Heal();};
        void RestorePower() {Warrior::RestorePower();};
		int Intercept() {return (Warrior::RangeAttack());};
	protected:
	private:
};

#endif /* !PALADIN_HPP_ */
