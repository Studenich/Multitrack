#-------------------------------------------------
#
# Project created by QtCreator 2016-06-29T11:25:56
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimplePlayer
TEMPLATE = app

SOURCES += main.cpp\
    audiotrack.cpp \
    widget.cpp \
    audiotrackwidget.cpp

HEADERS  += audiotrack.h \
    widget.h \
    audiotrackwidget.h

FORMS    += widget.ui \
    audiotrackwidget.ui

RESOURCES += \
    buttons.qrc
