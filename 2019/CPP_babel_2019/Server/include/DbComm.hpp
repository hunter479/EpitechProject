/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** dbComm
*/

#ifndef DBCOMM_HPP_
#define DBCOMM_HPP_

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <map>
#include <boost/asio.hpp>
#include "User.hpp"
#include "Contact.hpp"
#include "Serial.hpp"
#include "Dbcall.hpp"
#include "rfc.hpp"

class DbComm
{
	public:
		DbComm(const DbComm &) = delete;
		~DbComm();
		const std::string command(const std::string &, User *, Contact *);
		static DbComm *getInstance(void);

	private:
		const std::string getCode(const std::string &cmd);
		const std::string getSerial(const std::string &cmd);
		User *execCommandAuth(const std::string &, User *);

	private:
		DbComm();
		std::map<std::string, std::string> _refCode;
		std::map<std::string, User *(User::*)(User *)> _userInterface;
		std::map<std::string, std::string (Contact::*)(const std::string &cmd)> _contact;
		static DbComm *_instance;
		std::string to_send;
		std::string to_recup;
};

#endif /* !DBCOMM_HPP_ */
