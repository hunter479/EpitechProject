/*
** EPITECH PROJECT, 2019
** cpp_d08_2018
** File description:
** Droid
*/

#ifndef DROID_HPP_
	#define DROID_HPP_

#include <iostream>
#include <string>


class Droid {
	public:
		Droid(const std::string &serial = "");
        Droid(const Droid &);
		~Droid();
        const size_t &getEnergy() const;
        const size_t &getAttack() const;
        const size_t &getToughness() const;
        const std::string *getStatus() const;
        const std::string &getId() const;
        void setEnergy(const size_t &);
        void setAttack(const size_t &);
        void setStatus(const std::string *);
        void setId(std::string const);
        bool operator==(const Droid &) const;
        bool operator!=(const Droid &) const;
        const Droid &operator=(const Droid &);
        void operator<<(size_t &);
	private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
};

std::ostream &operator<<(std::ostream &, const Droid &);

#endif /* !DROID_HPP_ */
