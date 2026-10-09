#-------------------------------------------------
#
# Project created by QtCreator 2026-10-09
# 基于samp4_9 QTableWidget使用
# 作者：许龙奇  学号：2024414290337
#
#-------------------------------------------------
QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = samp4_9
TEMPLATE = app
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    qwmainwind.cpp

HEADERS += \
    qwmainwind.h

FORMS += \
    qwmainwind.ui

RESOURCES += \
    res.qrc

RC_ICONS = AppIcon.ico
