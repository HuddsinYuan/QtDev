#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textShow->setText("aaa");
    counter = 0;
    data = "this is client";
    qtimer = new QTimer(this);
    qtimer->start(1000);
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("127.0.0.1"), 21000);

    connect(ui->btnsend,SIGNAL(clicked()),SLOT(sendMessage()));
    connect(client, SIGNAL(readyRead()),SLOT(showMessage()));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage() {
//    client->write(this->data);
    data =  ui->textEdit->toPlainText();
    client->write(data.toAscii());
    ui->textEdit->clear();
}

void MainWindow::showMessage(){
    if(client->canReadLine())
          ui->textShow->setText(client->readAll());
}
