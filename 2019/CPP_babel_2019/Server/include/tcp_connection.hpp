/*
** EPITECH PROJECT, 2019
** server
** File description:
** tcp_connection
*/

#ifndef TCP_CONNECTION_HPP_
#define TCP_CONNECTION_HPP_

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "Contact.hpp"
#include "DbComm.hpp"

using boost::asio::ip::tcp;

class server
{
    public:
        server(boost::asio::io_context& io_context, short port);

    private:
        void start();
        void do_accept();

    /*  VAR */
    private:
        tcp::acceptor _acceptor;
};

class session : public std::enable_shared_from_this<session>
{
    public:
        session(tcp::socket socket);
        void start();

    private:
        void do_read();
        void do_write(const std::string &);

    /*  VAR */
    private:
        DbComm *_db;
        User *_me;
        Contact *_ct;
        tcp::socket _socket;
        std::string _ip;
        enum { _max_length = 1024 };
        char _data[_max_length];
};

#endif /* !TCP_CONNECTION_HPP_ */
