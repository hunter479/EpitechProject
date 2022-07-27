/*
** EPITECH PROJECT, 2019
** ex06
** File description:
** ToyStory
*/

#include <fstream>
#include <iostream>
#include "ToyStory.hpp"

static bool analyse_str(const std::string &str, Toy &ref)
{
    std::string path;
    Toy::Error err;

    if (str.compare(0, 8, "picture:") == 0) {
        path = str.substr(8);
        if (ref.setAscii(path) == false) {
            err = ref.getLastError();
            err.setType(Toy::Error::PICTURE);
            std::cout << err.where() << ": " << err.what() << std::endl;
        } else
            std::cout << ref.getAscii();
        return (true);
    } else
        return (false);
}

void ToyStory::tellMeAStory(const std::string &filename, Toy &toy1, bool (Toy::*func1)(const std::string &str1), Toy &toy2, bool (Toy::*func2)(const std::string &str2))
{
    std::ifstream myfile(filename);
    std::string tmp;
    Toy::Error err;
    bool who = false;

    if (myfile.is_open()) {
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
        while (getline(myfile, tmp)) {
            if (who == false) {
                if (analyse_str(tmp, toy1)  == true)
                    who = false;
                else {
                    if ((toy1.*func1)(tmp) == false) {
                        err = toy1.getLastError();
                        err.setType(Toy::Error::SPEAK);
                        std::cout << err.where() << ": " << err.what() << std::endl;
                    }
                    who = true;
                }
            } else {
                if (analyse_str(tmp, toy2) == true)
                    who = true;
                else {
                    if ((toy2.*func2)(tmp) == false) {
                        err = toy2.getLastError();
                        err.setType(Toy::Error::SPEAK);
                        std::cout << err.where() << ": " << err.what() << std::endl;
                    }
                    who = false;
                }
            }
        }
        myfile.close();
    } else
        std::cout << "Bad Story" << std::endl;
}

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}
