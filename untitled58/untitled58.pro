#-------------------------------------------------
#
# Project created by QtCreator 2020-06-14T16:26:44
#
#-------------------------------------------------

QT       += core gui
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#CONFIG += c++11
TARGET = untitled58
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    button.cpp \
    youxi.cpp \
    waypoint.cpp \
    map.cpp \
    plistreader.cpp \
    towerposition.cpp \
    tower.cpp \
    jianta.cpp \
    bullet.cpp \
    enemy.cpp \
    chaita.cpp

HEADERS += \
        mainwindow.h \
    button.h \
    youxi.h \
    waypoint.h \
    map.h \
    towerposition.h \
    plistreader.h \
    tower.h \
    jianta.h \
    panju.h \
    bullet.h \
    enemy.h \
    chaita.h

FORMS += \
        mainwindow.ui \
    youxi.ui \
    jianta.ui \
    chaita.ui

RESOURCES += \
    re.qrc

DISTFILES +=





