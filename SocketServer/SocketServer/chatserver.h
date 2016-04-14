#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMap>
#include <QSet>

class chatserver : public QTcpServer
{
    Q_OBJECT

public:
    chatserver(QObject *parent = 0);

protected slots:
    void refreshuserlist();
    void disconnected();
    void readyread();

private:
    QMap<QTcpSocket* , QString> clientname;
    QSet<QTcpSocket*> clients;

protected:
    void incomingConnection(int socketfd);
};

#endif // CHATSERVER_H
