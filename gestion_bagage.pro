QT       += core gui  charts network multimedia multimediawidgets charts printsupport widgets axcontainer serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui  serialport
CONFIG += c++11
QT       += core gui sql
QT++= sql
CONFIG += console
QT       += core gui sql printsupport
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Avion.cpp \
    arduino.cpp\
    avions.cpp \
    connection.cpp \
    exportexcelobject.cpp \
    gestion_voyageur.cpp \
    login.cpp \
    main.cpp \
    bagages.cpp\
    menu.cpp \
    smtp.cpp \
    voyageur.cpp

HEADERS += \
    Avion.h \
    arduino.h \
    avions.h \
    connection.h \
    exportexcelobject.h \
    gestion_voyageur.h \
    login.h \
includers.h \
    bagages.h \
    menu.h \
    smtp.h \
    voyageur.h

FORMS += \
    avions.ui \
    gestion_voyageur.ui \
    login.ui \
    bagages.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


