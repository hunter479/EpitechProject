/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** main
*/

#include <iostream>
#include <fstream>

int read_file(char *file)
{
    std::ifstream    files;
    std::string str;

    files.open(file);
    if (files.is_open()) {
        while (std::getline(files, str))
            std::cout << str << '\n';
        files.close();
        return (0);
    } else
        std::cout << "my_cat: <" << file << ">: No such file or directory\n";
    return (1);
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./ my_cat file [...]" << std::endl;
        return (84);
    }
    while (i < ac) {
        read_file(av[i]);
        i++;
    }
    return (0);
}
