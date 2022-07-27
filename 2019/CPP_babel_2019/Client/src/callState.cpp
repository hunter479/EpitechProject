/*
** EPITECH PROJECT, 2019
** Client
** File description:
** callState
*/

#include "mainwindow.h"

void MainWindow::startCall(void)
{
    _callManager = CallManager::getInstance();
    std::string targetCall = "on Call with " + _currentContact->getUsername();

    _onCall = true;
    targetCall += _currentContact->getUsername();
    ui->call_button->setText(targetCall.c_str());
    ui->call_button->setStyleSheet("background-color:rgb(58, 61, 201)");
    _callManager->startCall(_udpServ.getServSocket(), std::atoi(_currentContact->getPort().c_str()), _currentContact->getIp());
}

void MainWindow::isCalling(void)
{
    _udpServ._reply = new QMessageBox(this);
    _udpServ.createButton();
    connect(_udpServ._reply, &QMessageBox::buttonClicked, this, &MainWindow::analyse_MessageBox_state);
    _buttonState = true;
}

void MainWindow::stopCalling(void)
{
    if (_buttonState == true) {
        delete _udpServ._reply;
        _buttonState = false;
    }
}

void MainWindow::callRejected(void)
{
    delete _asking;
}

void MainWindow::callAccepted(void)
{
    startCall();
    delete _asking;   
}

void MainWindow::callFinished(void)
{
    _callManager->stopCall();
    ui->call_button->setText("Call");
    ui->call_button->setStyleSheet("background-color:rgb(125, 10, 10)");
    _onCall = false;
}