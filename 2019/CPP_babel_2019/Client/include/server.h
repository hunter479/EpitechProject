#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QWidget>
#include <string>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextBrowser>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    void        close(void);
    void        sendUdpMessage(QString message, const std::string &ip, const std::string &port);
    void        launch(unsigned short port, const QString &ip, QTextBrowser *browser);
    void        createButton(void);

    void        setSenderPort(quint16 &port) { _sendPort = port; }
    void        setSenderIp(QHostAddress &hostAddr) { _senderIp = hostAddr; }

    QHostAddress &getSenderIp(void) { return _senderIp; }
    quint16      &getSenderPort(void) { return _sendPort; }
    QUdpSocket   *getServSocket(void) { return _socket; }
    QTextBrowser *getTextBrowser(void) { return _textBrowser; }
    QMessageBox     *_reply;

signals:

public slots:
//    void readyRead();

private:
    QTextBrowser    *_textBrowser;
    QHostAddress    _senderIp;
    quint16         _sendPort;
    QUdpSocket      *_socket;
};

#endif // SERVER_H
