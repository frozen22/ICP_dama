#-------------------------------------------------
#
# Project created by QtCreator 2013-05-04T17:05:46
#
#-------------------------------------------------

QT       += core gui \
            xml \
            network

TARGET = dama2013
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Position.cpp \
    Player.cpp \
    Pawn.cpp \
    Figure.cpp \
    Desk.cpp \
    Queen.cpp \
    XMLGameSave.cpp \
    Move.cpp \
    Moves.cpp \
    ReplayGame.cpp \
    RandomAI.cpp \
    OnlinePlayer.cpp \
    LocalPlayer.cpp \
    Game.cpp \
    gfigure.cpp \
    ggamewindow.cpp \
    greplaywindow.cpp \
    Server.cpp \
    Client.cpp

HEADERS  += mainwindow.h \
    Position.h \
    Player.h \
    Pawn.h \
    Desk.h \
    Figure.h \
    Queen.h \
    XMLGameSave.h \
    Move.h \
    Moves.h \
    ReplayGame.h \
    RandomAI.h \
    Position.h \
    OnlinePlayer.h \
    Game.h \
    gfigure.h \
    ggamewindow.h \
    greplaywindow.h \
    Server.h \
    Client.h \
    LocalPlayer.h

FORMS    += mainwindow.ui \
    ggamewindow.ui \
    greplaywindow.ui
