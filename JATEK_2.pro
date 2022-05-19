TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        application.cpp \
        button.cpp \
        examplecheckbox.cpp \
        main.cpp \
        spinbox.cpp \
        statictext.cpp \
        tabla.cpp \
        tile.cpp \
        widgets.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lgraphics64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lgraphics64d
else:unix: LIBS += -L$$PWD/./ -lgraphics64

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2_ttf.dll


INCLUDEPATH += $$PWD/SDL2
DEPENDPATH += $$PWD/SDL2

HEADERS += \
    application.hpp \
    button.hpp \
    examplecheckbox.hpp \
    spinbox.hpp \
    statictext.hpp \
    tabla.hpp \
    tile.hpp \
    widgets.hpp

