/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** OneTime
*/

#include <string>
#include <algorithm>
#include <iostream>
#include "OneTime.hpp"

void OneTime::encryptChar(char c)
{
    int ref = 0;

    if (key[index] == '\0')
        index = 0;
    ref = key[index] - 'a';
    if (c >= 'a' && c <= 'z') {
        for (int a = 0; a < ref; a++) {
            c += 1;
            if (c > 'z')
                c = 'a';
        }
    }
    else if (c >= 'A' && c <= 'Z') {
        for (int a = 0; a < ref; a++) {
            c += 1;
            if (c > 'Z')
                c = 'A';
        }
    }
    std::cout << c;
    index++;
}

void OneTime::decryptChar(char c)
{
    int ref = 0;

    if (key[index] == '\0')
        index = 0;
    ref = key[index] - 'a';
    if (c >= 'a' && c <= 'z') {
        for (int a = 0; a < ref; a++) {
            c -= 1;
            if (c < 'a')
                c = 'z';
        }
    }
    else if (c >= 'A' && c <= 'Z') {
        for (int a = 0; a < ref; a++) {
            c -= 1;
            if (c < 'A')
                c = 'Z';
        }
    }
    std::cout << c;
    index++;
}

OneTime::OneTime(const std::string &rec)
{
    index = 0;
    key.assign(rec);
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
}
