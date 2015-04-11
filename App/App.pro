TEMPLATE = app

#QMAKE_LFLAGS += /INCREMENTAL:NO

QT       += gui widgets network testlib sql multimedia

HEADERS += Application.hpp

SOURCES += \
	Application.cpp \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../Core/ -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/release/Core.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/debug/Core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/libCore.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Gui/release/ -lGui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Gui/debug/ -lGui
else:unix: LIBS += -L$$OUT_PWD/../Gui/ -lGui

INCLUDEPATH += $$PWD/../Gui
DEPENDPATH += $$PWD/../Gui

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Gui/release/Gui.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Gui/debug/Gui.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Gui/libGui.a

