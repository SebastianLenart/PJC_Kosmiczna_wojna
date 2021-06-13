QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomba.cpp \
    button.cpp \
    cialakrazace.cpp \
    cialaniebieskie.cpp \
    czarnadziura.cpp \
    enemy.cpp \
    game.cpp \
    main.cpp \
    menu.cpp \
    mglawica.cpp \
    planety.cpp \
    player.cpp \
    pocisk.cpp \
    pociskkula.cpp \
    pocisklaser.cpp \
    pociskpodwojny.cpp \
    satelity.cpp \
    ship.cpp \
    shipblue.cpp \
    shipgreen.cpp \
    shipred.cpp \
    teleportacja.cpp \
    tunel.cpp \
    wynik.cpp \
    zjawiska.cpp

HEADERS += \
    bomba.h \
    button.h \
    cialakrazace.h \
    cialaniebieskie.h \
    czarnadziura.h \
    enemy.h \
    game.h \
    menu.h \
    mglawica.h \
    planety.h \
    player.h \
    pocisk.h \
    pociskkula.h \
    pocisklaser.h \
    pociskpodwojny.h \
    satelity.h \
    ship.h \
    shipblue.h \
    shipgreen.h \
    shipred.h \
    teleportacja.h \
    tunel.h \
    wynik.h \
    zjawiska.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
