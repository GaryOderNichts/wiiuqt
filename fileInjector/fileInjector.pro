#-------------------------------------------------
# nah I don't like QtCreator, I created this file manually
#-------------------------------------------------

#QT       += core\
#	    gui

TARGET = fileInjector
CONFIG   += console
CONFIG   -= app_bundle
DEFINES += NAND_BIN_CAN_WRITE

TEMPLATE = app

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    ../WiiUQt/blocks0to1.cpp \
    ../WiiUQt/nandbin.cpp \
    ../WiiUQt/tools.cpp \
    ../WiiUQt/aes.c \
    ../WiiUQt/sha1.c \
    ../WiiUQt/nandspare.cpp

HEADERS += ../WiiUQt/nandbin.h \
    ../WiiUQt/tools.h \
    ../WiiUQt/blocks0to1.h \
    ../WiiUQt/nandspare.h

