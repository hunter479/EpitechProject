/*
** EPITECH PROJECT, 2019
** B-CPP-500
** File description:
** tcp_connection
*/

#include <iostream>
#include <boost/asio.hpp>
#include "tcp_connection.hpp"

session::session(tcp::socket socket) : _socket(std::move(socket))
{
    _ct = new Contact;
    _db = DbComm::getInstance();
    _me = new User;
    _ip.assign(_socket.remote_endpoint().address().to_string());
    std::cout << "Connection from :" << _ip << std::endl;
    std::memset(_data, 0, _max_length);
}

void session::start()
{
    do_read();
}

void session::do_read()
{
    auto self(shared_from_this());

    std::memset(_data, 0, _max_length);
    _socket.async_read_some(boost::asio::buffer(_data, _max_length),
    [this, self](boost::system::error_code ec, std::size_t length) {
        if (!ec) {
            do_write(std::string(_data));
        }
    });
}

void session::do_write(const std::string &cmd)
{
    auto self(shared_from_this());
    std::string to_send = _db->command(cmd, _me, _ct);

    boost::asio::async_write(_socket, boost::asio::buffer(to_send, to_send.length()),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
            if (!ec) {
                do_read();
            }
        });
}

server::server(boost::asio::io_context& io_context, short port) : _acceptor(io_context, tcp::endpoint(tcp::v4(), port))
{
    do_accept();
}

void server::do_accept()
{
    _acceptor.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket)
        {
            if (!ec) {
                std::make_shared<session>(std::move(socket))->start();
            }
            do_accept();
        });
}
