#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter = 0;
    qtimer = new QTimer(this);
    client = new QTcpSocket(this);

    QRegExp regx("[a-zA-Z0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->textEdit );
    ui->textEdit->setValidator( validator );

    connect(ui->btnsend,SIGNAL(clicked()),SLOT(sendMessage()));
    connect(client, SIGNAL(readyRead()),SLOT(showMessage()));
    connect(ui->btnconn, SIGNAL(clicked()), SLOT(startConn()));
    connect(ui->btnquit, SIGNAL(clicked()), SLOT(quitConn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::sendMessage() {
    data =  ui->textEdit->text().trimmed();
    client->write(data.toUtf8());
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}

void MainWindow::showMessage(){
    QRegExp ReceivedParse("^(.*)Received.$");
    QRegExp DataParse("^data,(.*)");
    if(client->canReadLine()){
        QString line = QString::fromUtf8(client->readLine()).trimmed();
        if(ReceivedParse.indexIn(line) != -1) {
            QString word = ReceivedParse.cap(1);
            int length = word.length();
            ui->textShow->append("you:" + word + " " + QString::number(length) + " words.");
        }
        else if(DataParse.indexIn(line)!= -1){
            QStringList datas = DataParse.cap(1).split(',');
            foreach(QString data, datas)
                ui->textShow->append(data);
            ui->textShow->append("end.");
        }
        else {
            ui->textShow->append("failed");
        }
     }

}

void MainWindow::startConn(){
    client->connectToHost(QHostAddress("127.0.0.1"), 4200);
}

void MainWindow::quitConn(){
    client->write("exit");
}
