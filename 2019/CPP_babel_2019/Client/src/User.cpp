/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** User
*/

#include "User.hpp"

User::User()
{
}

User::~User()
{
}

const int User::getId() const
{
    return (_id);
}

const std::string &User::getFname() const
{
    return (_Fname);
};

const std::string &User::getLname() const
{
    return (_Lname);
};

const std::string &User::getUsername() const
{
    return (_Username);
};

const std::string &User::getMail() const
{
    return (_Mail);
};

const std::string &User::getPwd() const
{
    return (_Pwd);
};

const std::string &User::getIp() const
{
    return (_Ip);
};

const std::string &User::getPort() const
{
    return (_Port);
};

bool User::getStatus() const
{
    return (_Status);
};

void User::setId(const int id)
{
    _id = id;
}

void User::setFname(const std::string &str)
{
    _Fname.assign(str);
}

void User::setLname(const std::string &str)
{
    _Lname.assign(str);
}

void User::setUsername(const std::string &str)
{
    _Username.assign(str);
}

void User::setMail(const std::string &str)
{
    _Mail.assign(str);
}

void User::setPwd(const std::string &str)
{
    _Pwd.assign(str);
}

void User::setIp(const std::string &str)
{
    _Ip.assign(str);
}

void User::setPort(const std::string &str)
{
    _Port.assign(str);
}

void User::setStatus(bool c)
{
    _Status = c;
}
