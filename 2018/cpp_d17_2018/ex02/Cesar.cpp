/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Cesar
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Cesar.hpp"

void Cesar::reset()
{
    intervalle = 3;
}

void Cesar::decryptChar(char ciperchar)
{
    if (intervalle == 30)
        intervalle = 4;
    if (ciperchar >= 'a' && ciperchar <= 'z') {
        for (int a = 0; a < intervalle; a++) {
            ciperchar -= 1;
            if (ciperchar < 'a')
                ciperchar = 'z';
        }
    }
    else if (ciperchar >= 'A' && ciperchar <= 'Z') {
        for (int a = 0; a < intervalle; a++) {
            ciperchar -= 1;
            if (ciperchar < 'A')
                ciperchar = 'Z';
        }
    }
    std::cout << ciperchar;
    intervalle++;
}

void Cesar::encryptChar(char plainchar)
{
    if (intervalle == 30)
        intervalle = 4;
    if (plainchar >= 'a' && plainchar <= 'z') {
        for (int a = 0; a < intervalle; a++) {
            plainchar += 1;
            if (plainchar > 'z')
                plainchar = 'a';
        }
    }
    else if (plainchar >= 'A' && plainchar <= 'Z') {
        for (int a = 0; a < intervalle; a++) {
            plainchar += 1;
            if (plainchar > 'Z')
                plainchar = 'A';
        }
    }
    std::cout << plainchar;
    intervalle++;
}

Cesar::Cesar()
{
    intervalle = 3;
}

Cesar::~Cesar()
{
}
