/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <iomanip>

int toConvert(double temp, std::string metric)
{
    if (metric.compare("Fahrenheit") == 0) {
        temp = 5.0 / 9.0 * (temp - 32);
        metric = "Celsius";
    }
    else if (metric.compare("Celsius") == 0) {
        temp = temp * 9 / 5 + 32;
        metric = "Fahrenheit";
    }
    else
        return (84);
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << temp;
    std::cout << std::setw(16) << metric.c_str() << std::endl;
    return (0);
}

int main(int ac, char **av)
{
    std::string str;
    double  temp = 0;

    std::cin >> temp;
    std::cin >> str;
    toConvert(temp, str);
    return (0);
}
