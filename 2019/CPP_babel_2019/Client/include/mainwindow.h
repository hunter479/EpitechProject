#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QKeyEvent>
#include <QListWidget>
#include <QMessageBox>
#include <iostream>
#include <QtDebug>
#include <map>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QKeyEvent>
#include "./ui_mainwindow.h"
#include "peerTopeer_rfc.h"
#include "CallManager.hpp"
#include "server.h"
#include "User.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define login 0
#define signup 1
#define contact 2

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent *event);

    bool isConnected(void) const;
    void sendSignupDatas(void);
    void successLogin(void);
    const QString getLocalIp(void);
    int connect_to_server(QString servIp, QString servPort);

private:
    void startCall(void);
    void isCalling(void);
    void stopCalling(void);
    void callRejected(void);
    void callAccepted(void);
    void callFinished(void);

protected:
    bool    eventFilter(QObject* obj, QEvent* event);

private slots:

    void analyse_MessageBox_state();

    void analyse_askingButton_state();

    void onReadyRead();

    void readyReadUdp();

    void on_pushButton_3_clicked();

    void on_lineEdit_3_returnPressed();

    void on_actionQuitter_triggered();

    void on_actionLog_out_triggered();

    void on_add_contact_clicked();

    void on_Register_clicked();

    void on_cancel_reg_clicked();

    void on_sign_up_clicked();

    void on_servConnect_clicked();

    void on_call_button_clicked();

    void onListItemClicked(QListWidgetItem *);

private:
	const std::string getCode(const std::string &cmd);
	const std::string getSerial(const std::string &cmd);
    void logScene(const std::string code, const std::string serial);
    void ContactScene(const std::string code);
    User            *_me;
    void on_send_button_clicked();
    int _scene;


private:
    int                 _prepCall;
    std::map<std::string, void (MainWindow::*)(void)>   _states;
    bool                _buttonState;
    bool                _onCall;
    QMessageBox         *_asking;
    Server              _udpServ;
    QTcpSocket          _socket;
    QString             _servData;
    Ui::MainWindow      *ui;
    std::string         _messageReceived;
    User                *_currentContact;
    CallManager         *_callManager;
};

#endif // MAINWINDOW_H
