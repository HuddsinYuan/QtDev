#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->Login);
    client = new QTcpSocket(this);

    connect(client, SIGNAL(readyRead()),SLOT(OnReadyRead()));
    connect(client, SIGNAL(connected()), SLOT(OnConnected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnConnected() {

    ui->stackedWidget->setCurrentWidget(ui->chatpage);
    QString username = ui->textName->text();
    client->write(QString("/newuser:" + username + "\n").toUtf8());
}

void MainWindow::OnReadyRead() {
    QRegExp newuserexp("^/newusers:(.*)$");
    QRegExp wordexp("^/(.*):(.*)$");

    while(client->canReadLine()) {
    QString message = QString::fromUtf8(client->readLine()).trimmed();

    qDebug() << message ;

    if(newuserexp.indexIn(message) != -1) {
        QStringList users = newuserexp.cap(1).split(",");
        ui->listWidget->clear();
        foreach(QString user, users) {
            qDebug() << user;
            new QListWidgetItem(QPixmap(":/user.png") , user, ui->listWidget);
        }
    }
    else if(wordexp.indexIn(message) != -1) {
        QString user = wordexp.cap(1);
        QString message = wordexp.cap(2);
        ui->chatroom->append("<b>" + user + "</b>:" + message);

        qDebug() << "User: " + user;
        qDebug() << "Mesg: " + message;
    }
    }
}

void MainWindow::on_btnLogin_clicked()
{
    QString ipaddr = ui->textHost->text();
    qDebug() << "Serve: " << ipaddr ;
    client->connectToHost(ipaddr, 4400);
}

void MainWindow::on_btnsay_clicked()
{
    QString line = ui->textsay->text().trimmed();

    if(!line.isEmpty()) {
        client->write(QString("/message:" + line + "\n").toUtf8());
    }

    ui->textsay->clear();
    ui->textsay->setFocus();
}
