/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Contact
*/

#include <vector>
#include "Contact.hpp"
#include <boost/algorithm/string.hpp>

Contact::Contact()
{
    dbcall = Dbcall::getInstance();
}

Contact::~Contact()
{
}

std::string Contact::addCTTUser(const std::string &cmd)
{
    std::vector<std::string>    args;

    boost::split(args, cmd, [](char c) {
		return (c == '|');
	});
    return (dbcall->Add_inContact(args.at(1), args.at(2)));
}

const std::string &Contact::GetCTTUser() const
{
    return (_CttUser);
}

const std::string &Contact::GetCTTFriend() const
{
    //select here
    return (_CttFriend);
}

const std::string &Contact::GetIsvalid() const
{
    //si contact toujours dans tes contacts
    return (_Isvalid);
}

void Contact::SetCTTFriend(const std::string &)
{

}

void Contact::SetIsvalid(const std::string &)
{

}