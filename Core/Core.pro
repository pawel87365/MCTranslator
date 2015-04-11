TEMPLATE = lib
CONFIG += staticlib

QMAKE_LFLAGS += /INCREMENTAL:NO

#Just for notice. Qt Core is included by default.
QT       += core

HEADERS += Translator.hpp
HEADERS += MorseCodeChars.hpp

SOURCES += Translator.cpp
SOURCES += MorseCodeChars.cpp