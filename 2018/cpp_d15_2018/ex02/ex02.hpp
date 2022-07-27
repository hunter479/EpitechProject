/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** ex02
*/

#ifndef EX02_HPP_
	#define EX02_HPP_

#include <iostream>

template<typename T>
const T &min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return (a);
    else
        return (b);
}

int min(const int &a, const int &b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return (a);
    else
        return (b);
}

template<typename T>
const T templateMin(const T *a, const int &size)
{
    T min_val;

    if (size <= 0)
        return (0);
    min_val = a[0];
    for (int i = 0; i < size - 1; i++)
        min_val = min<T>(min_val, a[i + 1]);
    return (min_val);
}

int nonTemplateMin(const int *a, const int &size)
{
    int min_val = 0;

    if (size <= 0)
        return (0);
    min_val = a[0];
    for (int i = 0; i < size; i++)
        min_val = min(min_val, a[i]);
    return (min_val);
}



#endif /* !EX02_HPP_ */
