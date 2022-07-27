/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MapGen
*/

#include <time.h>
#include "MapGen.hpp"

const std::string MapGen::mapPattern2()
{
    std::string map;
    map.append("XXXXXXXXXXXXXXXXX\n");
    map.append("XSSOOXOOOOOXOOSSX\n");
    map.append("XSXXOXOXOXOXOXXSX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XOXOXOXOXOXOXOXOX\n");
    map.append("XOOOXOOOOOOOXOOOX\n");
    map.append("XOXOXXOXOXOXXOXOX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XOXOXXOXOXOXXOXOX\n");
    map.append("XOOOXOOOOOOOXOOOX\n");
    map.append("XOXOXOXOXOXOXOXOX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XSXXOXOXOXOXOXXSX\n");
    map.append("XSSOOXOOOOOXOOSSX\n");
    map.append("XXXXXXXXXXXXXXXXX\n");
    return (map);
}

const std::string MapGen::mapPattern1()
{
    std::string map;
    map.append("XXXXXXXXXXXXXXXXX\n");
    map.append("XSSOOOOOOOOOOOSSX\n");
    map.append("XSXOXOXOXOXOXOXSX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XOXOXOXOXOXOXOXOX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XOXOXOXOXOXOXOXOX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XOXOXOXOXOXOXOXOX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XOXOXOXOXOXOXOXOX\n");
    map.append("XOOOOOOOOOOOOOOOX\n");
    map.append("XSXOXOXOXOXOXOXSX\n");
    map.append("XSSOOOOOOOOOOOSSX\n");
    map.append("XXXXXXXXXXXXXXXXX\n");
    return (map);
}

const char MapGen::doPutBox(const int modulo, const int check)
{
    if (rand() % modulo == check)
        return (GRA);
    else
        return (BOX);
}

std::vector<std::string> MapGen::putBox(const std::string map)
{
    std::string tmp;
    std::vector<std::string> ret;

    for (char i : map) {
        if (i == '\n') {
            ret.push_back(tmp);
            tmp.clear();
        } else if (i == 'O'){
            tmp.push_back(doPutBox(3, 2));
        } else
            tmp.push_back(i);
    }
    return (ret);
}


MapGen::MapGen()
{
    std::string map = mapPattern1();
    if (rand() % 2 == 0) {
        throw putBox(mapPattern1());
    } else {
        throw putBox(mapPattern2());
    }
}

MapGen::~MapGen()
{
}
