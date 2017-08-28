QT       += core network

QT       -= gui

TARGET = TBFramework
TEMPLATE = lib

SOURCES += src/update.cpp \
            src/tbreceiver.cpp \
    src/user.cpp \
    src/message.cpp

HEADERS += include/update.h \
            include/tbreceiver.h \
    include/user.h \
    include/message.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
