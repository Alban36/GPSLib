TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    latitude_test.cpp

LIBS += -lpthread -lgtest -pthread

