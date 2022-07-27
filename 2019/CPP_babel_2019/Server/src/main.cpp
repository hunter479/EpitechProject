/*
** EPITECH PROJECT, 2019
** Server
** File description:
** main
*/

#include <iostream>
#include <boost/asio.hpp>
#include "tcp_connection.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            std::cerr << "Usage: ./server <port>\n";
            return (84);
        }
        boost::asio::io_context io_context;
        server s(io_context, std::atoi(av[1]));
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return (0);
}
