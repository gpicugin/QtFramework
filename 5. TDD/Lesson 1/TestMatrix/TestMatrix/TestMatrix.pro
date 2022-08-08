QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tmatrix.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Matrix/release/ -lMatrix
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Matrix/debug/ -lMatrix
else:unix: LIBS += -L$$OUT_PWD/../Matrix/ -lMatrix

INCLUDEPATH += $$PWD/../Matrix
DEPENDPATH += $$PWD/../Matrix
