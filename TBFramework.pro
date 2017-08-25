QT       += core network

QT       -= gui

TARGET = TBFramework
TEMPLATE = lib

SOURCES += src/update.cpp \
            src/tbreceiver.cpp \
    src/message.cpp \
    src/user.cpp

HEADERS += include/update.h \
            include/tbreceiver.h \
    include/message.h \
    include/user.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
