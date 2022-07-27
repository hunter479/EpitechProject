/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include <boost/serialization/access.hpp>
#include <vector>
#include "Dbcall.hpp"

class User {
	private:
        friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version){
			ar & _id;
			ar & _Fname;
			ar & _Lname;
			ar & _Username;
			ar & _Mail;
			ar & _Pwd;
			ar & _Ip;
			ar & _Port;
			ar & _Status;
			ar & _contact;
		}

	public:
		User();
		~User();
		User *Add_User(User *);
		User *GetLogin(User *);
		User *GetContact(User *);
		User *GetCall(User *);
		User *setStatusOff(User *);
		User *retrieveContactList(User *);
		void pushContact(const std::string &);
		const std::string &getFname() const;
		const std::string &getLname() const;
		const std::string &getUsername() const;
		const std::string &getMail() const;
		const std::string &getPwd() const;
		const std::string &getIp() const;
		const std::string &getPort() const;
		const std::vector<std::string> &getContactList() const;
		bool getStatus() const;
		const int getId() const;
		void setFname(const std::string &);
		void setLname(const std::string &);
		void setUsername(const std::string &);
		void setMail(const std::string &);
		void setPwd(const std::string &);
		void setIp(const std::string &);
		void setPort(const std::string &);
		void setStatus(bool);
		void setId(const int);

	private:
		int _id;
        std::string _Fname;
        std::string _Lname;
        std::string _Username;
        std::string _Mail;
        std::string _Pwd;
		std::string _Ip;
		std::string _Port;
		int _Status;
		std::vector<std::string> _contact;
	    Dbcall *_dbcall;
};

#endif /* !USER_HPP_ */
