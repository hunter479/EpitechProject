/*
** EPITECH PROJECT, 2019
** cpp_d17_2018
** File description:
** find
*/

#ifndef FIND_HPP_
	#define FIND_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<class T>
class T::iterator do_find(T &ref, int i)
{
    return (std::find(ref.begin(), ref.end(), i));
};

#endif /* !FIND_HPP_ */
