#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T22:01:17
#
#-------------------------------------------------

QT       -= core gui

TARGET = GPSLib
TEMPLATE = lib

DEFINES += GPSLIB_LIBRARY

SOURCES += gpslib.cpp

HEADERS += gpslib.h\
        GPSLib_global.h \
    gps_data_types.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEC3B152D
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = GPSLib.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
