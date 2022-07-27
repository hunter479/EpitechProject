/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaNurse
*/

#include <iostream>
#include <fstream>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

void    KoalaNurse::timeCheck(void)
{
    if (_work == 0) {
        std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
        _work = 1;
    } else if (_work == 1) {
        std::cout << "Nurse " << id << ": Time to get to go home";
        std::cout << " to my eucalyptus forest!" << std::endl;
        _work = 0;
    }
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream    files;
    std::string     drug;
    size_t  pos = -1;

    pos = filename.find(".report");
    files.open(filename);
    if (files.is_open() && pos != -1) {
        std::getline(files, drug);
        files.close();
        filename.erase(pos, filename.length());
        std::cout << "Nurse " << id << ": Kreog! M." <<filename;
        std::cout << " needs a " << drug << " !\n";
        return (drug);
    } else
        return (std::string());
}

void    KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

KoalaNurse::KoalaNurse(std::string str)
{
    id.append(str);
    _work = 0;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id << ": ";
    std::cout << "Finally some rest!" << std::endl;
}