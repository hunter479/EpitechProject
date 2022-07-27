/*
** EPITECH PROJECT, 2019
** cpp_d15_2018
** File description:
** ex01
*/

#ifndef EX01_HPP_
	#define EX01_HPP_

template<typename T>
const int compare(const T &a, const T &b)
{
    if (a == b)
        return (0);
    else if (a > b)
        return (1);
    else
        return (-1);
}


#endif /* !EX01_HPP_ */
