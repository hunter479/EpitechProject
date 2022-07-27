/*
** EPITECH PROJECT, 2019
** ex04
** File description:
** ex04
*/

#ifndef EX04_HPP_
	#define EX04_HPP_

template<typename T>
class Tester {
    public:
        Tester() {};
        ~Tester() {};
        bool equal(const T &a, const T &b);
};

template<typename T>
bool equal(const T &a, const T &b);

#endif /* !EX04_HPP_ */
