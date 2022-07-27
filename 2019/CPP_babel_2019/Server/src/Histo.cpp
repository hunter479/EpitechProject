/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Histo
*/

#include <boost/algorithm/string.hpp>
#include "Serial.hpp"
#include "Histo.hpp"

Histo::Histo()
{
    dbcall = Dbcall::getInstance();
}

Histo::~Histo()
{
}

std::string Histo::getHisto(const std::string &cmd)
{
    std::vector<std::string>    args;

    boost::split(args, cmd, [](char c) {
		return (c == '|');
	});

    std::string toRet = "502|";
    toRet += Serial::save((Histo *)dbcall->getHisto(args.at(1), args.at(2)));
    return toRet;
}

std::string Histo::uploadHisto(const std::string &cmd)
{
    std::vector<std::string>    args;

    boost::split(args, cmd, [](char c) {
		return (c == '|');
	});
    dbcall->uploadHisto(args.at(1), args.at(2), args.at(3));
    return "uploadHisto";
}