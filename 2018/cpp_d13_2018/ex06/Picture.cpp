/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** Picture
*/

#include <fstream>
#include <iostream>
#include "Picture.hpp"

const Picture &Picture::operator=(const Picture &other)
{
    if (this != &other)
        this->data.assign(other.data);
    return (*this);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream myfile;

    if (file.empty()) {
        data.assign("");
        return (true);
    }
    myfile.open(file);
    if (myfile.is_open()) {
        data.assign(std::istreambuf_iterator<char>(myfile.rdbuf()), std::istreambuf_iterator<char>());
        myfile.close();
        return (true);
    } else {
        data.assign("ERROR");
        return (false);
    }
    return (true);
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}
