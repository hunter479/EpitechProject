/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** User
*/

#include "User.hpp"

User::User()
{
    _dbcall = Dbcall::getInstance();
}

User::~User()
{
}

User *User::Add_User(User *rec)
{
    bool ret;

    if (_dbcall == nullptr || rec == nullptr) {
        std::cerr << "Obj is null" << std::endl;
        return (nullptr);
    }
    ret = _dbcall->Add_inbd(rec);
    if (ret == true) {
        this->_id = rec->_id;
        this->_Fname = rec->_Fname;
        this->_Lname = rec->_Lname;
        this->_Username = rec->_Username;
        this->_Mail = rec->_Mail;
        this->_Pwd = rec->_Pwd;
        this->_Ip = rec->_Ip;
        this->_Port = rec->_Port;
        this->_Status = rec->_Status;
    }
    return (ret == false ? nullptr : this);
}

const int User::getId() const
{
    return (_id);
}

User *User::GetLogin(User *rec)
{
    void *result = _dbcall->checkLogin(reinterpret_cast<void*>(rec));
    if (result)
        result = retrieveContactList(reinterpret_cast<User *>(result));
    return (reinterpret_cast<User *>(result));
}

User *User::setStatusOff(User *rec)
{
    void *result = _dbcall->updateStatusOff(reinterpret_cast<void*>(rec));
    return (reinterpret_cast<User *>(result));
}

User *User::GetCall(User *rec)
{
    void *result = _dbcall->checkCall(reinterpret_cast<void*>(rec));
    return (reinterpret_cast<User *>(result));
}

User *User::GetContact(User *rec)
{
    void *result = _dbcall->retrieveContact(reinterpret_cast<void*>(rec));
    return (reinterpret_cast<User *>(result));
}

User *User::retrieveContactList(User *rec)
{
    void *result = _dbcall->retrieveContactList(reinterpret_cast<void*>(rec));
    return (reinterpret_cast<User *>(result));
}

void User::pushContact(const std::string &str)
{
    _contact.push_back(str);
}

const std::string &User::getFname() const
{
    return (_Fname);
}

const std::string &User::getLname() const
{
    return (_Lname);
}

const std::string &User::getUsername() const
{
    return (_Username);
}

const std::string &User::getMail() const
{
    return (_Mail);
}

const std::string &User::getPwd() const
{
    return (_Pwd);
}

const std::string &User::getIp() const
{
    return (_Ip);
}

const std::string &User::getPort() const
{
    return (_Port);
}

bool User::getStatus() const
{
    return (_Status);
}

const std::vector<std::string> &User::getContactList() const
{
    return (_contact);
}

void User::setId(const int id)
{
    _id = id;
}

void User::setFname(const std::string &str)
{
    _Fname = str;
}

void User::setLname(const std::string &str)
{
    _Lname = str;
}

void User::setUsername(const std::string &str)
{
    _Username = str;
}

void User::setMail(const std::string &str)
{
    _Mail = str;
}

void User::setPwd(const std::string &str)
{
    _Pwd = str;
}

void User::setIp(const std::string &str)
{
    _Ip = str;
}

void User::setPort(const std::string &str)
{
    _Port = str;
}

void User::setStatus(bool b)
{
    _Status = b;
}