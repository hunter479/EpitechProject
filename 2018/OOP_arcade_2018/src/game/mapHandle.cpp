/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** mapHandle
*/

#include "mapHandle.hpp"

mapHandle::mapHandle(const char *path)
{
    std::ifstream    files;
    std::string str;

    index = 0;
    files.open(path);
    if (files.is_open()) {
        while (std::getline(files, str))
            current.push_back(str);
        files.close();
    } else {
        std::cerr << "failed get map\n";
        throw std::exception();
    }
    save = current;
}

mapHandle::~mapHandle()
{
}