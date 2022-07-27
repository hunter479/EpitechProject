/*
** EPITECH PROJECT, 2019
** cpp_d06_2018
** File description:
** KoalaDoctor
*/

#include <fstream>
#include <iostream>
#include "KoalaDoctor.hpp"

void    KoalaDoctor::timeCheck(void)
{
    if (_work == 0) {
        std::cout << "Dr." << name << ": Time to get to work!" << std::endl;
        _work = 1;
    } else if (_work == 1) {
        std::cout << "Dr." << name << ": Time to get to go home";
        std::cout << " to my eucalyptus forest!" << std::endl;
        _work = 0;
    }
}

void    KoalaDoctor::diagnose(SickKoala *patient)
{
    std::ofstream myfile;
    std::string report = patient->getName();

    report.insert(report.size(), ".report");
    std::cout << "Dr." << name << ": So what's goerking you Mr.";
    std::cout << patient->getName() << " ?" << std::endl;
    patient->poke();
    myfile.open(report);
    myfile << tab[std::rand() % 5];
}

KoalaDoctor::KoalaDoctor(std::string doc)
{
    name.append(doc);
    std::cout << "Dr." << name << ": I'm Dr." << name;
    std::cout << " ! How do you kreog?" << std::endl;
    tab[0] = "mars\n";
    tab[1] = "Buronzand\n";
    tab[2] = "Viagra\n";
    tab[3] = "Extasy\n";
    tab[4] = "Eucalyptus leaf\n";
}

KoalaDoctor::~KoalaDoctor()
{
}
