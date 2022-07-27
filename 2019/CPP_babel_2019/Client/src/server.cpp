#include <iostream>
#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
}

Server::~Server()
{
}

void Server::createButton(void)
{
    _reply->setWindowTitle("Call");
    _reply->setText("Someone is calling you... Accept ?");
    _reply->resize(400,250);
    _reply->addButton(QMessageBox::Yes);
    _reply->addButton(QMessageBox::No);
    _reply->show();
}

void Server::sendUdpMessage(QString message, const std::string &ip, const std::string &port)
{
    QByteArray data;
    QHostAddress addr;

    std::cout << "IP FROM EDO: " << ip << " PORT FROM EDO: " << port << std::endl;
    addr.setAddress(ip.c_str());
    data.append(message);
    _socket->writeDatagram(data, addr, std::atoi(port.c_str()));
}

void Server::launch(unsigned short port, const QString &ip, QTextBrowser *browser)
{
    QHostAddress addr;

    _textBrowser = browser;
    addr.setAddress(ip);
    _socket = new QUdpSocket(this);
    _socket->bind(addr, port);
}
