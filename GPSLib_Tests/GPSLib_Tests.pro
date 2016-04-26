TEMPLATE = app
CONFIG += console
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    latitude_test.cpp

LIBS += -lpthread -lgtest -pthread -L$$PWD/../ -lGPSLib

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
