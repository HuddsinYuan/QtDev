#include <QCoreApplication>
#include <chatserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    chatserver *server =  new chatserver();

    bool success = server->listen(QHostAddress::Any, 4400);

    if(!success) {
        qFatal("failed");
    }

    qDebug() << "Ready" ;

    return a.exec();
}
