/*
** EPITECH PROJECT, 2019
** ex04
** File description:
** ex04
*/

#include <iostream>
#include "ex04.hpp"

template<typename T>
bool equal(const T &a, const T &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool equal(const int &a, const int &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool equal(const double &a, const double &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool equal(const float &a, const float &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool equal(const std::string &a, const std::string &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}


template<>
bool Tester<int>::equal(const int &a, const int &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool Tester<double>::equal(const double &a, const double &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool Tester<float>::equal(const float &a, const float &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}

template<>
bool Tester<std::string>::equal(const std::string &a, const std::string &b)
{
    if (a == b)
        return (true);
    else
        return (false);
}
