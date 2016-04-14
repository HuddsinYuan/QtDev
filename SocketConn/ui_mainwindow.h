/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QStackedWidget *stackedWidget;
    QWidget *Login;
    QFrame *frame_2;
    QLineEdit *textHost;
    QLineEdit *textName;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnLogin;
    QWidget *chatpage;
    QTextEdit *chatroom;
    QListWidget *listWidget;
    QLineEdit *textsay;
    QPushButton *btnsay;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 800, 521));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 500));
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        frame_2 = new QFrame(Login);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(230, 160, 341, 181));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Plain);
        textHost = new QLineEdit(frame_2);
        textHost->setObjectName(QString::fromUtf8("textHost"));
        textHost->setGeometry(QRect(90, 40, 181, 31));
        textName = new QLineEdit(frame_2);
        textName->setObjectName(QString::fromUtf8("textName"));
        textName->setGeometry(QRect(90, 90, 181, 31));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 59, 16));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 59, 16));
        btnLogin = new QPushButton(frame_2);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(100, 140, 115, 32));
        stackedWidget->addWidget(Login);
        chatpage = new QWidget();
        chatpage->setObjectName(QString::fromUtf8("chatpage"));
        chatroom = new QTextEdit(chatpage);
        chatroom->setObjectName(QString::fromUtf8("chatroom"));
        chatroom->setGeometry(QRect(10, 10, 581, 431));
        listWidget = new QListWidget(chatpage);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(600, 10, 181, 431));
        textsay = new QLineEdit(chatpage);
        textsay->setObjectName(QString::fromUtf8("textsay"));
        textsay->setGeometry(QRect(10, 450, 581, 31));
        btnsay = new QPushButton(chatpage);
        btnsay->setObjectName(QString::fromUtf8("btnsay"));
        btnsay->setGeometry(QRect(610, 450, 115, 32));
        stackedWidget->addWidget(chatpage);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        btnLogin->setText(QApplication::translate("MainWindow", "Log In", 0, QApplication::UnicodeUTF8));
        btnsay->setText(QApplication::translate("MainWindow", "Say", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
