TEMPLATE = app
TARGET = gui 

QT        += core gui 

HEADERS   += Gui.h
SOURCES   += main.cpp \
    Gui.cpp
FORMS     += Gui.ui    
RESOURCES +=
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
