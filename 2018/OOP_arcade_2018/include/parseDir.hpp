/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** parseDir
*/

#ifndef PARSEDIR_HPP_
    #define PARSEDIR_HPP_

#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

class parseDir
{
    public:
        void parseLib(const char *, const std::string = "lib/");
        void parseGame(const std::string = "games/");
        void changeLib(const int);
        const char *getCurrent();

        std::vector<std::string> _list;
    private:
        void recupContent(const std::string);
};

#endif /* !PARSEDIR_HPP_ */
