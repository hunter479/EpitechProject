/*
** EPITECH PROJECT, 2019
** ex03
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
# define PRIEST_HPP_

#include "Mage.hpp"

class Priest : virtual public Mage {
	public:
		Priest(const std::string &name, const int &level);
		~Priest();
        int CloseAttack();
		void Heal();
	protected:
	private:
};

#endif /* !PRIEST_HPP_ */
