/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Dbcall
*/

#include "User.hpp"
#include "Dbcall.hpp"
Dbcall *Dbcall::_instance = 0;


Dbcall::Dbcall()
{
    prepareSQL();
}

Dbcall::~Dbcall()
{
}

Dbcall *Dbcall::getInstance()
{
    if (_instance == nullptr)
        _instance = new Dbcall;
    return (_instance);
}

int Dbcall::callbackAddContact(void *NotUsed, int argc, char **data, char **columns)
{
    if (argc != 0)
        return 1;
    return 0;
}

void Dbcall::prepareSQL()
{
    char *errmsg = nullptr;

    if (sqlite3_open_v2("Babel.db", &_DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(_DB) << std::endl;
        throw std::exception();
    } else {
        std::cout << "Babel.db is open" << std::endl;
    }
    if ((sqlite3_exec(_DB, T_USER, NULL, 0, &errmsg)) != SQLITE_OK) {
        std::cerr << "Can't Create Table USER: " << errmsg << std::endl;
        sqlite3_free(errmsg);
    } else {
        std::cerr << "Table USER created succesfully" << std::endl;
    }
    if (sqlite3_exec(_DB, T_CONTACT, NULL, 0, &errmsg) != SQLITE_OK) {
        std::cerr << "Can't Create Table CONTACT: " << errmsg << std::endl;
        sqlite3_free(errmsg);
    } else {
        std::cerr << "Table CONTACT created succesfully" << std::endl;
    }
}

int Dbcall::callbackIdsame(void *ptr, int ac, char **data, char **TName)
{
    std::string id = reinterpret_cast<char *>(ptr);

    if (id.compare(data[0]) == 0)
        return (1);
    return (0);
}

bool Dbcall::Select_inbd(std::string col, std::string username, std::string friendId)
{
    std::string sql("SELECT " + col + " FROM T_USER WHERE USR_Username=\"" + username + "\";");

    int rc = sqlite3_exec(_DB, sql.c_str(), Dbcall::callbackAddContact, NULL, NULL);
    if (rc == 0)
        return false;
    return true;
}

std::string Dbcall::Add_inContact(std::string friendId, std::string username)
{
    char *zErrMsg = 0;
    std::string sql("SELECT * FROM T_CONTACT INNER JOIN T_USER ON CTT_friendID=USR_ID WHERE USR_ID=" + friendId + " AND CTT_User='" + username + "';");
    std::string data("201");
    std::string data1("200");
    std::string insert("INSERT INTO T_CONTACT(CTT_User, CTT_friendID) VALUES ('" + username + "', " + friendId + ");");

    if (Select_inbd("*", username, friendId) == false)
        return data;
    std::string tmp = "SELECT * FROM T_USER WHERE USR_Username='" + username + "';";
    if (sqlite3_exec(_DB, tmp.c_str(), Dbcall::callbackIdsame, (void *)friendId.c_str(), NULL) == 4)
        return (std::string("204"));
    if (sqlite3_exec(_DB, sql.c_str(), Dbcall::callbackAddContact, NULL, NULL) != SQLITE_OK)
        return (std::string("203"));
    int rc = sqlite3_exec(_DB, insert.c_str(), Dbcall::callbackAddContact, (void *)(data.c_str()), &zErrMsg);
    if (rc != SQLITE_OK) {
        sqlite3_free(&zErrMsg);
        return (data);
    }
    return data1;
}

int Dbcall::callbackSignup(void *ptrUser, int ac, char **av, char **azCoLname)
{
    User *ptr = reinterpret_cast<User *>(ptrUser);

    ptr->setId(std::atoi(av[0]));
    return (0);
}

bool Dbcall::Add_inbd(void *ptrUser)
{
    User *ptr = reinterpret_cast<User *>(ptrUser);
    char *zErrMsg = 0;
    int rc = 0;
    std::string concat = ADD_USER + ptr->getFname() + "', '" + ptr->getLname() + "', '" + ptr->getUsername() + "', '" + ptr->getPwd() + "', '" + ptr->getMail() + "', '" + ptr->getIp() + "', '" + ptr->getPort() + "', '" + std::to_string(ptr->getStatus()) + "');";
    std::string c2 = "SELECT * FROM T_USER WHERE USR_Username = '" + ptr->getUsername() + "'";
    std::string tmp = "SELECT * FROM T_USER WHERE USR_Username='" + ptr->getUsername() + "';";

    if (sqlite3_exec(_DB, tmp.c_str(), Dbcall::callbackAddContact, NULL, NULL) == 4)
        return (false);
    rc = sqlite3_exec(_DB, concat.c_str(), NULL, reinterpret_cast<void *>(ptr), &zErrMsg);
    rc = sqlite3_exec(_DB, c2.c_str(), Dbcall::callbackSignup, reinterpret_cast<void *>(ptr), &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << " Failed to ADD in T_USER " << zErrMsg << std::endl;
        sqlite3_free(&zErrMsg);
        return (false);
    } else {
        Update_indb("USR_Port", ptr->getPort(), ptr->getUsername());
        Update_indb("USR_Status", "1", ptr->getUsername());
        return (true);
    }
}

int Dbcall::callbackLogin(void *ptrUser, int ac, char **av, char **azCoLname)
{
    User *ptr = reinterpret_cast<User *>(ptrUser);
    int index_usr = 0;
    int index_pwd = 0;
    int i = 0;
    std::string username_ref("USR_Username");
    std::string password_ref("USR_Password");

    while (av[i] != nullptr) {
        if (index_usr == 0 && username_ref.compare(azCoLname[i]) == 0)
            index_usr = i;
        if (index_pwd == 0 && password_ref.compare(azCoLname[i]) == 0)
            index_pwd = i;
        i += 1;
    }
    if (ptr->getUsername().compare(av[index_usr]) == 0 && ptr->getPwd().compare(av[index_pwd]) == 0) {
        ptr->setId(std::atoi(av[0]));
        ptr->setFname(std::string(av[1]));
        ptr->setLname(std::string(av[2]));
        ptr->setUsername(std::string(av[3]));
        ptr->setPwd(std::string(av[4]));
        ptr->setMail(std::string(av[5]));
        ptr->setStatus(true);
        return (1);
    }
    return (0);
}

void *Dbcall::checkLogin(void *ptrUser)
{
    int rc = 0;
    User *ptr = reinterpret_cast<User *>(ptrUser);
    std::string cmd = "SELECT * FROM T_USER;";

    rc = sqlite3_exec(_DB, cmd.c_str(), Dbcall::callbackLogin, reinterpret_cast<void *>(ptr), NULL);
    if (rc == 4) {
        std::cout << ptr->getUsername() << " logged succesfully" << std::endl;
        if (Update_indb("USR_Port", ptr->getPort(), ptr->getUsername()) == false)
            return (nullptr);
        if (Update_indb("USR_Status", "1", ptr->getUsername()) == false)
            return (nullptr);
        if (Update_indb("USR_Ip", ptr->getIp(), ptr->getUsername()) == false)
            return (nullptr);
        return (ptr);
    } else {
        return (nullptr);
    }
}

int Dbcall::callbackCall(void *ptrUser, int ac, char **av, char **azCoLname)
{
    User *ptr = reinterpret_cast<User *>(ptrUser);
    int index_usr = 0;
    int i = 0;
    std::string id_ref("USR_ID");

    while (av[i] != nullptr) {
        if (index_usr == 0 && id_ref.compare(azCoLname[i]) == 0)
            index_usr = i;
        i += 1;
    }
    if (ptr->getId() == std::atoi(av[index_usr])) {
        ptr->setFname(std::string(av[1]));
        ptr->setLname(std::string(av[2]));
        ptr->setUsername(std::string(av[3]));
        ptr->setPwd(std::string(av[4]));
        ptr->setMail(std::string(av[5]));
        ptr->setIp(std::string(av[6]));
        ptr->setPort(std::string(av[7]));
        ptr->setStatus(std::atoi(av[8]));
        return (1);
    }
    return (0);
}

void *Dbcall::checkCall(void *ptrUser)
{
    int rc = 0;
    User *ptr = reinterpret_cast<User *>(ptrUser);
    std::string cmd = "SELECT * FROM T_USER;";

    rc = sqlite3_exec(_DB, cmd.c_str(), Dbcall::callbackCall, reinterpret_cast<void *>(ptr), NULL);
    if (rc == 4) {
        return (ptr);
    } else {
        return (nullptr);
    }
}


int Dbcall::callbackgetContact(void *ptrUser, int ac, char **av, char **azCoLname)
{
    int i = 0;
    User *ptr = reinterpret_cast<User *>(ptrUser);
    int index_usr = 0;
    std::string username_ref("USR_Username");

    while (av[i] != nullptr) {
        if (index_usr == 0 && username_ref.compare(azCoLname[i]) == 0)
            index_usr = i;
        i += 1;
    }
    if (ptr->getUsername().compare(av[index_usr]) == 0) {
        ptr->setId(std::atoi(av[0]));
        ptr->setFname(std::string(av[1]));
        ptr->setLname(std::string(av[2]));
        ptr->setUsername(std::string(av[3]));
        ptr->setIp(std::string(av[6]));
        ptr->setPort(std::string(av[7]));
        ptr->setStatus(std::atoi(av[8]));
        return (1);
    }
    return (0);
}

void *Dbcall::retrieveContact(void *ptrUser)
{
    int rc = 0;
    User *ptr = reinterpret_cast<User *>(ptrUser);
    std::string cmd = "SELECT * FROM T_USER;";

    rc = sqlite3_exec(_DB, cmd.c_str(), Dbcall::callbackgetContact, reinterpret_cast<void *>(ptr), NULL);
    if (rc == 4) {
        return (ptr);
    } else {
        return (nullptr);
    }
}


int Dbcall::callbackgetContactList(void *ptrUser, int ac, char **av, char **azCoLname)
{
    User *ptr = reinterpret_cast<User *>(ptrUser);

    if (av[0]) {
        ptr->pushContact(av[0]);
    }
    return (0);
}

void *Dbcall::retrieveContactList(void *ptrUser)
{
    int rc = 0;
    User *ptr = reinterpret_cast<User *>(ptrUser);
    std::string cmd = "SELECT CTT_User FROM T_CONTACT WHERE CTT_friendID=\"" + std::to_string(ptr->getId()) + "\"";

    rc = sqlite3_exec(_DB, cmd.c_str(), Dbcall::callbackgetContactList, reinterpret_cast<void *>(ptr), NULL);
    return (ptr);
}

void *Dbcall::updateStatusOff(void *ptrUser)
{
    int rc = 0;
    User *ptr = reinterpret_cast<User *>(ptrUser);

    if (Update_indb("USR_Status", "0", ptr->getUsername()) == false)
        return (nullptr);
    ptr->setStatus(false);
    return (ptr);
}

bool Dbcall::Update_indb(const std::string &col, std::string data, std::string username)
{
    char *errmsg = nullptr;
    std::string concat = UPDATE_USER + col + " = '" + data + WHERE_USER + username + DB_END;

    if (sqlite3_exec(_DB, concat.c_str(), NULL, 0, NULL) != SQLITE_OK) {
        std::cerr << " Failed to Update" << col << ": " << &errmsg << std::endl;
        sqlite3_free(errmsg);
        return (false);
    }
    return (true);
}
