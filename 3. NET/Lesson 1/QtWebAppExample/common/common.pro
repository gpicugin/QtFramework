QT += core network
QT -= gui

TARGET = common
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES += main.cpp \
    webconfigurator.cpp \
    webconfiguratorpage.cpp

HEADERS += \
    webconfigurator.h \
    webconfiguratorpage.h \
    httpsettings.hpp

RESOURCES += \
    resources.qrc
