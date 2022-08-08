QT += widgets testlib

CONFIG += qt warn_on depend_includepath testcase

CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES +=  tst_testpanelconcat.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../WidgetLib/release/ -lWidgetLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../WidgetLib/debug/ -lWidgetLib
else:unix: LIBS += -L$$OUT_PWD/../WidgetLib/ -lWidgetLib

INCLUDEPATH += $$PWD/../WidgetLib
DEPENDPATH += $$PWD/../WidgetLib
