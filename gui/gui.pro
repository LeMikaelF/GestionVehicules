TEMPLATE = app
TARGET = gui
QT += core \
    gui
HEADERS += DialogueSupprimer.h \
    DialogueVehicule.h \
    DialogueCamion.h \
    Gui.h
SOURCES += DialogueSupprimer.cpp \
    DialogueVehicule.cpp \
    DialogueCamion.cpp \
    main.cpp \
    Gui.cpp
FORMS += DialogueSupprimer.ui \
    DialogueVehicule.ui \
    DialogueCamion.ui \
    Gui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
