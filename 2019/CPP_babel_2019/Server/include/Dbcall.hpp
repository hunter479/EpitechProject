/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Dbcall
*/

#ifndef DBCALL_HPP_
#define DBCALL_HPP_

#include <string>
#include <sqlite3.h>
#include <iostream>


#define T_USER "CREATE TABLE T_USER(USR_ID INTEGER PRIMARY KEY AUTOINCREMENT, USR_Fname TEXT NOT NULL, USR_Lname TEXT NOT NULL, USR_Username TEXT UNIQUE NOT NULL, USR_Password TEXT NOT NULL, USR_Mail TEXT UNIQUE NOT NULL, USR_Ip TEXT NOT NULL, USR_Port TEXT NOT NULL, USR_Status INTEGER NOT NULL);"
#define T_CONTACT "CREATE TABLE T_CONTACT(CTT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, CTT_User TEXT NOT NULL, CTT_friendID INTEGER NOT NULL REFERENCES T_USER(USR_ID));"
#define UPDATE_USER "UPDATE T_USER SET "
#define WHERE_USER "' where USR_Username='"
#define WHERE_MAIL " where USR_Mail='"
#define DB_END "';"
#define SELECT "SELECT "
#define FROM_USER " from T_USER where USR_Username='"
#define ADD_USER "INSERT INTO T_USER (USR_Fname, USR_Lname, USR_Username, USR_Password, USR_Mail, USR_Ip, USR_Port, USR_Status) VALUES ('"

class Dbcall {
	public:
		Dbcall(const Dbcall &) = delete;
		Dbcall &operator=(const Dbcall &) = delete;
		~Dbcall();
        bool		Select_inbd(std::string , std::string, std::string);
		std::string	Add_inContact(std::string friendId, std::string username);
		static Dbcall 	*getInstance();
        bool Add_inbd(void *);
        bool Update_indb(const std::string &, std::string, std::string);
		void prepareSQL();
		void *checkLogin(void *);
		void *checkCall(void *);
		void *retrieveContact(void *);
		void *updateStatusOff(void *);
		void *retrieveContactList(void *);
		static int callbackAddContact(void *, int, char **, char **);
		static int callbackIdsame(void *, int, char **, char **);
		static int callbackSignup(void *, int, char **, char **);
		static int callbackLogin(void *, int, char **, char **);
		static int callbackCall(void *, int, char **, char **);
		static int callbackgetContact(void *, int, char **, char **);
		static int callbackgetContactList(void *, int, char **, char **);

	private:
		static Dbcall	*_instance;
        sqlite3			*_DB;
		Dbcall();
};

#endif /* !DBCALL_HPP_ */
