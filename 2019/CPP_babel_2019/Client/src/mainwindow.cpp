/*
** EPITECH PROJECT, 2019
** Client
** File description:
** mainwindow
*/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), _udpServ(this), _socket(this),  ui(new Ui::MainWindow)
{
    _prepCall = 0;
    _onCall = false;
    _buttonState = false;
    _callManager = nullptr;
    _currentContact = nullptr;
    _me = new User;
    _states[__120__] = &MainWindow::isCalling;
    _states[__130__] = &MainWindow::stopCalling;
    _states[__140__] = &MainWindow::callRejected;
    _states[__150__] = &MainWindow::callAccepted;
    _states[__160__] = &MainWindow::callFinished;
    ui->setupUi(this);
    connect(ui->listWidget, &QListWidget::itemClicked,
            this, &MainWindow::onListItemClicked);
    ui->stackedWidget->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent   *key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
            if (ui->stackedWidget->currentIndex() == 4) {
                on_servConnect_clicked();
            } else if (ui->stackedWidget->currentIndex() == 1) {
                    if (ui->Register->hasFocus() == true)
                        on_Register_clicked();
                    else
                        on_pushButton_3_clicked();
            } else if (ui->stackedWidget->currentIndex() == 0) {
                if (ui->cancel_reg->hasFocus() == true) {
                    on_cancel_reg_clicked();
                } else
                    on_sign_up_clicked();
            }            
            return true;
        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "BRUH",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        if (_onCall == true) {
            _callManager->stopCall();
            _udpServ.sendUdpMessage(__160__, _currentContact->getIp(), _currentContact->getPort());
            _onCall = false;
        }
        std::string message = "210|" + Serial::save<User *>(_me);
        _socket.write(message.c_str());
    }
}

const QString MainWindow::getLocalIp(void)
{
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address : QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
            return (address.toString());
    }
    return (nullptr);
}

void MainWindow::logScene(const std::string code, const std::string serial)
{
    if (code.compare("042") == 0) {
        delete _me;
        _me = Serial::load<User *>(getSerial(serial));
        successLogin();
        return;
    } else {
        if (_scene == login) {
            ui->lineEdit_2->clear();
            QMessageBox::warning(this, "Warning", "Wrong username or password.");
        }
        if (_scene == signup)
            QMessageBox::warning(this, "Error", "Failed to send data");
    }
}

void MainWindow::ContactScene(const std::string message)
{
    std::string token = message.substr(0, message.find("|"));
    if (token == "042") {
        std::string ret = getSerial(message);
        _currentContact = Serial::load<User *>(ret);
        int status = _currentContact->getStatus();
        if (status == true) {
            ui->label_2->setText("Connected");
            ui->label_2->setStyleSheet("background-color:rgb(0, 255, 0)");
        } else if (status == false) {
            ui->label_2->setText("Disconnected");
            ui->label_2->setStyleSheet("background-color:rgb(255, 0, 0)");
        }
    } else if (token == "404")
        std::cerr << "Can't load contact" << std::endl;
}

void MainWindow::onReadyRead()
{
    _servData = QString::fromLocal8Bit(_socket.readAll());

    _messageReceived = _servData.toStdString();
    std::string token = _messageReceived.substr(0, _messageReceived.find("|"));
    std::cout << "TOKEN: " << token << " | " << _messageReceived << std::endl;
    if (token == "042") {
        std::string ret = getSerial(_messageReceived);
        _currentContact = Serial::load<User *>(ret);
        if (_prepCall == 1) {
            _prepCall = 0;
            isCalling();
            return;
        }
    }
    if (_messageReceived == "200") {
        QString txt = ui->lineEdit_4->text();
        ui->listWidget->addItem(txt);
        return;
    } else if (_messageReceived == "201") {
        QMessageBox::warning(this, "Add Contact", "No such user.");
        return;
    }

    if (_messageReceived == "203") {
        QMessageBox::warning(this, "Add Contact", "Already in friend list.");
        return;
    }
    if (_messageReceived == "204") {
        QMessageBox::warning(this, "Add Contact", "Can't add yourself in friend list.");
        return;        
    }

    if (_scene == login || _scene == signup)
        logScene(getCode(_messageReceived), getSerial(_messageReceived));
    if (_scene == contact) {
        ContactScene(_messageReceived);
    }
}

/*
 * =====================================
 * TOOL BAR OPTIONS
 * =====================================
*/

void MainWindow::on_actionQuitter_triggered()
{
}

void MainWindow::on_actionLog_out_triggered()
{
}

/*
 * =====================================
 * SIGN UP AND LOGGIN OPTIONS
 * =====================================
*/

int MainWindow::connect_to_server(QString servIp, QString servPort)
{
    if (servIp.isNull() == true || servIp.isEmpty() == true)
        servIp = "127.0.0.1";
    if (servPort.isNull() == true || servPort.isEmpty() == true)
        servPort = "4242";
    _socket.connectToHost(servIp, servPort.toShort());
    if (_socket.waitForConnected(3000))
        return 0;
    return 1;
}

bool MainWindow::isConnected(void) const
{
    bool connected = (_socket.state() == QTcpSocket::ConnectedState);
    return connected;
}

void MainWindow::on_servConnect_clicked()
{
    if (connect_to_server(ui->servIp->text(), ui->servPort->text()) == 0) {
        connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        ui->stackedWidget->setCurrentIndex(1);
    } else
        QMessageBox::warning(this, "Warning", "Couldn't connect to server");
}

void MainWindow::on_Register_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_cancel_reg_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::sendSignupDatas(void)
{
    try {
        const std::string file = getLocalIp().toStdString();

        _me->setFname(ui->first_name_reg->text().toStdString());
        _me->setLname(ui->last_name_reg->text().toStdString());
        _me->setUsername(ui->user_reg->text().toStdString());
        _me->setIp(file);
        _me->setMail(ui->mail_reg->text().toStdString());
        _me->setPwd(ui->pass_reg->text().toStdString());
        _me->setPort(ui->port_reg->text().toStdString());
        std::string info = "120|" + Serial::save(_me);

        _scene = signup;
        _socket.write(info.c_str());
    } catch(std::exception &e) {
        QMessageBox::warning(this, "Error", "Failed to send data");
    }
}

void MainWindow::on_sign_up_clicked()
{
    QString pass = ui->pass_reg->text();
    QString conf_pass = ui->conf_pass_reg->text();

    if (ui->user_reg->text().isNull() || ui->user_reg->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please choose an username.");
        ui->user_reg->setFocus();
        ui->pass_reg->clear();
        ui->conf_pass_reg->clear();
    } else if (pass == conf_pass && pass.isEmpty() == false && pass.isNull() == false) {
        sendSignupDatas();
    } else {
        QMessageBox::warning(this, "Warning", "Please choose a password.");
        ui->pass_reg->clear();
        ui->conf_pass_reg->clear();
    }
}

void MainWindow::successLogin()
{
    ui->lineEdit_3->setFocus();
    if (_scene == login) {
        ui->push_6->setText(ui->lineEdit->text());
        for (auto i : _me->getVector())
            ui->listWidget->addItem(i.c_str());
    } else
        ui->push_6->setText(ui->user_reg->text());
    ui -> stackedWidget -> setCurrentIndex(2);
    _udpServ.launch(std::atoi(_me->getPort().c_str()), getLocalIp(), ui->textBrowser);
    connect(_udpServ.getServSocket(), SIGNAL(readyRead()), this, SLOT(readyReadUdp()));
}

void MainWindow::on_pushButton_3_clicked()
{
    _me->setUsername(ui->lineEdit->text().toStdString());
    _me->setPwd(ui->lineEdit_2->text().toStdString());
    _me->setPort(ui->port_edit_login->text().toStdString());
    _me->setIp(getLocalIp().toStdString());
    std::string info = "130|" + Serial::save(_me);

    if (_me->getPort().empty() == true) {
        QMessageBox::warning(this, "Warning", "Please put an open port in the field");
        return;
    }
    _scene = login;
    _socket.write(info.c_str());
}

/*
 * =====================================
 * HOME / PROFILE
 * =====================================
*/

void MainWindow::on_add_contact_clicked()
{
    QString txt = ui->lineEdit_4->text();
    std::string message;

    message = "200|" + std::to_string(_me->getId()) + "|" + txt.toStdString(); 
    _socket.write(message.c_str());
}

/*
 * =====================================
 * CHAT / CALL
 * =====================================
*/

void MainWindow::analyse_MessageBox_state()
{
    QAbstractButton *button = _udpServ._reply->clickedButton();

    if (button->text() == "&Yes") {
        _udpServ.sendUdpMessage(__150__, _currentContact->getIp(), _currentContact->getPort());
        startCall();
    } else {
        _udpServ.sendUdpMessage(__140__, _currentContact->getIp(), _currentContact->getPort());
    }
}

void MainWindow::readyReadUdp()
{
    QUdpSocket  *udpSock = _udpServ.getServSocket();
    QByteArray  buffer;
    QString     message;
    std::vector<std::string>    args;

    buffer.resize(udpSock->pendingDatagramSize());
    udpSock->readDatagram(buffer.data(), buffer.size(), &_udpServ.getSenderIp(), &_udpServ.getSenderPort());
    message = buffer;

    boost::split(args, message.toStdString(), [](char c) {
		return (c == ':');
	});
    if (args.at(0).compare("isPending") == 0) {
        _prepCall = 1;
        User *newMe = new User;
        newMe->setId(std::atoi(args.at(1).c_str()));

        std::string message = "220|";
        std::string save = Serial::save<User *>(newMe);
        message += save;
        _socket.write(message.c_str());
        return;
    }
    if (_states[args.at(0)] != nullptr) {
        (this->*_states[message.toStdString()])();
        return;
    }
    if (_onCall == false) {
        ui->textBrowser->append(buffer);
    } else if (_onCall == true) {
        if (ui->call_button->text() == "Call" && _udpServ.getServSocket()->bytesAvailable() == 0) {
            _onCall = false;
        } else {
            QString test = buffer;
            _callManager->receiveDecodedSound(test.toStdString());
        }
    }
}

void MainWindow::on_send_button_clicked()
{
    QString user = ui->lineEdit->text();
    QString ret = ui->lineEdit_3->text();

    if (_onCall == false) {
        _udpServ.sendUdpMessage(user + ": " + ret + "\n", _currentContact->getIp(), _currentContact->getPort());
        ui->textBrowser->append(user + ": " + ret + "\n");
        ui->lineEdit_3->clear();
    }
}

void MainWindow::onListItemClicked(QListWidgetItem *item)
{
    std::string targetCall = "Call ";
    std::string message;
    if (_onCall == false) {
        std::string newUsername;
        newUsername.assign(item->text().toStdString());
        if (_currentContact != nullptr && 
            newUsername.compare(_currentContact->getUsername()) != 0)
            ui->textBrowser->clear();

        _currentContact = new User;
        _currentContact->setUsername(item->text().toStdString());

        targetCall += _currentContact->getUsername();
        ui->call_button->setText(targetCall.c_str());
        message = "202|" + Serial::save<User *>(_currentContact);
        _socket.write(message.c_str());
        _scene = contact;
    }
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    QString user = ui->lineEdit->text();
    QString ret = ui->lineEdit_3->text();

    if (_onCall == false) {
        _udpServ.sendUdpMessage(user + ": " + ret + "\n", _currentContact->getIp(), _currentContact->getPort());
        ui->textBrowser->append(user + ": " + ret + "\n");
        ui->lineEdit_3->clear();
    }
}

void MainWindow::analyse_askingButton_state(void)
{
    _udpServ.sendUdpMessage(__130__, _currentContact->getIp(), _currentContact->getPort());
}

void MainWindow::on_call_button_clicked()
{
    if (_onCall == false && _currentContact != nullptr && _currentContact->getStatus() == true && _me->getId() != _currentContact->getId()) {
        QString message;
        int id = _me->getId();
        std::string rfc = "isPending:" + std::to_string(id);
        message = rfc.c_str();
        _udpServ.sendUdpMessage(message, _currentContact->getIp(), _currentContact->getPort());
        _asking = new QMessageBox(this);
        _asking->setWindowTitle("Call");
        _asking->setText("Calling user");
        _asking->resize(400,250);
        _asking->addButton(QMessageBox::Cancel);
        _asking->show();
        connect(_asking, &QMessageBox::buttonClicked, this, &MainWindow::analyse_askingButton_state);
    } else if (_currentContact != nullptr && _currentContact->getStatus() == true && _me->getId() != _currentContact->getId()) {
        _callManager->stopCall();
        _udpServ.sendUdpMessage(__160__, _currentContact->getIp(), _currentContact->getPort());
        ui->call_button->setText("Call");
        ui->call_button->setStyleSheet("background-color:rgb(255, 0, 0)");
    }
}

/*
 * =====================================
 * Comm / Serv
 * =====================================
*/

const std::string MainWindow::getCode(const std::string &cmd)
{
    std::string token = cmd.substr(0, cmd.find("|"));
    return (token);
}

const std::string MainWindow::getSerial(const std::string &cmd)
{
    std::string ret(cmd);

    ret.erase(0, ret.find("|") + 1);
    return (ret);
}