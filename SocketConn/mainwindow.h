#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTcpSocket *client;
    int counter;

private slots:
    void on_btnLogin_clicked();

    void on_btnsay_clicked();

    void OnConnected();
    void OnReadyRead();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
