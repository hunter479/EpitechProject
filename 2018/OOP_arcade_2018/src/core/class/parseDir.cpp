/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** parseDir
*/

#include <iostream>
#include <unistd.h>
#include <algorithm>
#include "parseDir.hpp"

void parseDir::changeLib(int v)
{
    if (_list.size() <= 1)
        return;
    if (v == 1) {
        std::rotate(_list.begin(), _list.begin() + 1,
        _list.end());
    } else if (v == -1) {
        std::rotate(_list.rbegin(), _list.rbegin() + 1,
        _list.rend());
    }
    usleep(50000);
}

void parseDir::recupContent(const std::string path)
{
    struct dirent *dp;
    DIR* dirp = opendir(path.c_str());

    if (!dirp)
        throw std::invalid_argument("recupContent Failed");
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            _list.push_back(dp->d_name);
        }
    }
    closedir(dirp);
}

const char *parseDir::getCurrent()
{
    return (_list.front().c_str());
}

void parseDir::parseGame(const std::string default_path)
{
    try {
        recupContent(default_path);
        if (_list.size() == 0) {
            _list.push_back("No Lib");
        } else
            for (size_t i = 0; i < _list.size(); i++)
                _list.at(i).assign((default_path + _list.at(i).data()));
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        throw;
    };
}

void parseDir::parseLib(const char *passed_lib, const std::string default_path)
{
    bool pos;
    std::string rec = passed_lib;

    try {
        recupContent(default_path);
    for (size_t i = 0; i < _list.size(); i++) {
        if (rec.find(_list.at(i).data()) != std::string::npos) {
            _list.at(i).assign(rec);
            pos = true;
        }
        else
            _list.at(i).assign((default_path + _list.at(i).data()));
    };
    if (pos == false) {
        _list.push_back(passed_lib);
        changeLib(-1);
    } else {
        while (rec.find(_list.front().data()) == std::string::npos)
            changeLib(-1);
    }
    } catch (const std::exception &e) {
        throw;
    };
}
