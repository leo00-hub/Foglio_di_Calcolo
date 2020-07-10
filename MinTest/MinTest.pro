QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

INCLUDEPATH += /home/leonardo/Foglio_di_Calcolo

TEMPLATE = app

SOURCES +=  tst_mintest.cpp
