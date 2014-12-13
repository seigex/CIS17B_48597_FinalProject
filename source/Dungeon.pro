#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T18:17:21
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dungeon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    combat_screen.cpp \
    lose_screen.cpp \
    item_screen.cpp \
    magic.cpp \
    win_screen.cpp \
    help_screen.cpp \
    savedgame.cpp \
    loadfiles.cpp \
    winscreenendgame.cpp

HEADERS  += mainwindow.h \
    declarations.h \
    combat_screen.h \
    hero.h \
    enemy.h \
    lose_screen.h \
    item_screen.h \
    magic.h \
    win_screen.h \
    help_screen.h \
    savedgame.h \
    loadfiles.h \
    Boss.h \
    winscreenendgame.h

FORMS    += mainwindow.ui \
    combat_screen.ui \
    win_screen.ui \
    magic.ui \
    lose_screen.ui \
    item_screen.ui \
    help_screen.ui \
    loadfiles.ui \
    winscreenendgame.ui

RESOURCES += \
    Map.qrc

OTHER_FILES += \
    sounds/8bitAudio1.wav

copydata.commands = $(COPY_DIR) \"$$PWD/sounds\" \"$$OUT_PWD/sounds\"
copydata2.commands = $(COPY_DIR) \"$$PWD/config\" \"$$OUT_PWD/config\"
first.depends = $(first) copydata copydata2
export(first.depends)
export(copydata.commands)
export(copydata2.commands)
QMAKE_EXTRA_TARGETS += first copydata copydata2
