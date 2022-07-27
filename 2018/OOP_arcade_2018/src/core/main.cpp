/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include <iostream>
#include <unistd.h>
#include "usage.hpp"
#include "core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: not enough argument\n";
        Usage();
        return (84);
    }
    try {
        Core aled(av[1]);
        aled.launchGame();
    }
    catch (const std::exception &e) {
        return (84);
    };
    return (0);
}
