QT       += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    administratorwindow.cpp \
    dbmanager.cpp \
    inventory.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    member.cpp \
    storemanagerwindow.cpp

HEADERS += \
    admin.h \
    administratorwindow.h \
    date.h \
    dbmanager.h \
    inventory.h \
    item.h \
    mainwindow.h \
    manager.h \
    member.h \
    storemanagerwindow.h

FORMS += \
    admin.ui \
    administratorwindow.ui \
    mainwindow.ui \
    storemanagerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
