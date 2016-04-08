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
    QString data;
    QTimer* qtimer;

    int counter;

protected slots:
    void sendMessage(void);
    void showMessage(void);
    void startConn(void);
    void quitConn(void);

private slots:
    void on_btnquit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
