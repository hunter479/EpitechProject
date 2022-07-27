/*
** EPITECH PROJECT, 2019
** cpp_d10_2018
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
	#define VICTIM_HPP_

#include <string>

class Victim {
	public:
		Victim(const std::string &);
		~Victim();
		const std::string &getName() const {return (_name);};
		virtual void getPolymorphed() const;
	protected:
	private:
		std::string _name;
};
std::ostream &operator<<(std::ostream &os, const Victim &ref);

#endif /* !VICTIM_HPP_ */
