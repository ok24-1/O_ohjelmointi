TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        asiakas.cpp \
        luottotili.cpp \
        main.cpp \
        pankkitili.cpp

HEADERS += \
    asiakas.h \
    luottotili.h \
    pankkitili.h

QT += widgets
