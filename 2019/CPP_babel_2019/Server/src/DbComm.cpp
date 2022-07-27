/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** DbComm
*/

#include "DbComm.hpp"

DbComm *DbComm::_instance = 0;

DbComm::DbComm()
{
    _contact[rfc_add] = &Contact::addCTTUser;
    _userInterface[rfc_signup] = &User::Add_User;
    _userInterface[rfc_login] = &User::GetLogin;
    _userInterface[rfc_getContact] = &User::GetContact;
    _userInterface[rfc_statusOff] = &User::setStatusOff;
    _userInterface[rfc_getCall] = &User::GetCall;
}

DbComm::~DbComm()
{
}

DbComm *DbComm::getInstance(void)
{
    if (DbComm::_instance == nullptr) {
        DbComm::_instance = new DbComm();
    }
    return (DbComm::_instance);
}

const std::string DbComm::getCode(const std::string &cmd)
{
    std::string token = cmd.substr(0, cmd.find("|"));
    return (token);
}

const std::string DbComm::getSerial(const std::string &cmd)
{
    std::string ret(cmd);

    ret.erase(0, ret.find("|") + 1);
    return (ret);
}

User *DbComm::execCommandAuth(const std::string &cmd, User *obj)
{
    std::string code = getCode(cmd);
    std::string serial = getSerial(cmd);

    try {
        if (_userInterface[code] != nullptr)
            return ((obj->*_userInterface[code])(Serial::load<User>(serial)));
        return (nullptr);
    } catch(std::exception &e) {
        return (nullptr);
    }
}

const std::string DbComm::command(const std::string &cmd, User *obj, Contact *ct)
{
    std::string code = getCode(cmd);
    User *ptr = nullptr;

    if (_contact[code] != nullptr)
        return ((ct->*_contact[code])(cmd));
    if (_userInterface[code] != nullptr)
            ptr = execCommandAuth(cmd, obj);
    if (ptr) {
        code = "042|" + Serial::save(ptr);
        return (code);
    }
    return ("404|Error");
}