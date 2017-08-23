QT       += core network

QT       -= gui

TARGET = TBFramework
TEMPLATE = lib

SOURCES += src/update.cpp \
            src/tbreceiver.cpp

HEADERS += include/update.h \
            include/tbreceiver.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
