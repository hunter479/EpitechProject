/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
	#define SORCERER_HPP_

#include <string>
#include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer(const std::string &, const std::string &);
		~Sorcerer();
        const std::string &getTitle() const {return (_title);};
        const std::string &getName() const {return (_name);};
	void polymorph(const Victim &victim) const;
	protected:
	private:
        std::string _name;
        std::string _title;
};
std::ostream &operator<<(std::ostream &os, const Sorcerer &ref);

#endif /* !SORCERER_HPP_ */
