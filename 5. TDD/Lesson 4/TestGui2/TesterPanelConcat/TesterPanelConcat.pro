QT += widgets testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testpanelconcat.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../WidgetsLib/release/ -lWidgetsLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../WidgetsLib/debug/ -lWidgetsLib
else:unix: LIBS += -L$$OUT_PWD/../WidgetsLib/ -lWidgetsLib

INCLUDEPATH += $$PWD/../WidgetsLib
DEPENDPATH += $$PWD/../WidgetsLib
