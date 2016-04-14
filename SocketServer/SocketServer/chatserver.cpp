#include "chatserver.h"
#include "QRegExp"
#include "QStringList"

chatserver::chatserver(QObject *parent) : QTcpServer(parent)
{
}

void chatserver::incomingConnection(int socketfd){
    QTcpSocket *client = new QTcpSocket(this);

    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    qDebug() << "New Client from " << client->peerAddress().toString();

    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(client, SIGNAL(readyRead()), this, SLOT(readyread()));

//    refreshuserlist();

}

void chatserver::refreshuserlist() {

    QStringList userlist;
    foreach(QString user, clientname.values()) {
        userlist << user;
    }
    foreach(QTcpSocket* client, clients) {
        client->write(QString("/newusers:" + userlist.join(",") + "\n").toUtf8());
    }
}

void chatserver::disconnected(){
    QTcpSocket* client = (QTcpSocket*) sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();

    clients.remove(client);
    QString tuser = clientname[client];
    clientname.remove(client);

    refreshuserlist();

    foreach(QTcpSocket* client, clients) {
        client->write(QString("/Server:" + tuser + "has left \n").toUtf8());
    }

}

void chatserver::readyread(){
    QTcpSocket *client = (QTcpSocket*) sender();

    QRegExp newUser("^/newuser:(.*)$");
    QRegExp newMessage("^/message:(.*)$");

    while(client->canReadLine()) {
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        qDebug() << line;

        if(newUser.indexIn(line) != -1) {
            QString user = newUser.cap(1);
            clientname[client] = user;
            refreshuserlist();
            foreach(QTcpSocket* uclient , clients) {
                uclient->write(QString("/Server:" + user + " has joined. \n").toUtf8());
            }

        }
        else if (newMessage.indexIn(line) != -1) {
            QString message = newMessage.cap(1);
            QString user = clientname[client];
            qDebug() <<"User: " << user;
            qDebug() <<"Message: " << message;
            foreach(QTcpSocket* uclient, clients) {
                uclient->write(QString("/" + user + ":" + message + "\n").toUtf8());
            }
        }
        else {

        }
}
}


