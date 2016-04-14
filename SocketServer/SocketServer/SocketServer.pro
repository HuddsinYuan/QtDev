QT += core
QT -= gui

QT += network

CONFIG += c++11

TARGET = SocketServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    chatserver.cpp
HEADERS += \
    chatserver.h
