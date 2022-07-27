/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** mapHandle
*/

#ifndef MAPHANDLE_HPP_
    #define MAPHANDLE_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class mapHandle
{
    public:
        mapHandle(const char *path);
        ~mapHandle();

        void restoreSave() {current = save;};
        std::vector<std::string> current;
    private:
        std::vector<std::string> save;
        int index;
};

#endif /* !MAPHANDLE_HPP_ */
