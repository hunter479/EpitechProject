/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Contact
*/

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include "Dbcall.hpp"
#include <string>

class Contact {
	public:
		Contact();
		~Contact();

        std::string addCTTUser(const std::string &);

        const std::string &GetCTTUser() const;
        const std::string &GetCTTFriend() const;
        const std::string &GetIsvalid() const;
        void SetCTTFriend(const std::string &);
        void SetIsvalid(const std::string &);

	private:
        Dbcall	        *dbcall;
        std::string     _CttUser;
        std::string     _CttFriend;
        std::string     _Isvalid;
};

#endif /* !CONTACT_HPP_ */