QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administratorwindow.cpp \
    inventory.cpp \
    item.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    member.cpp \
    registerwindow.cpp \
    storemanagerwindow.cpp

HEADERS += \
    administratorwindow.h \
    date.h \
    inventory.h \
    item.h \
    loginwindow.h \
    mainwindow.h \
    manager.h \
    member.h \
    registerwindow.h \
    storemanagerwindow.h

FORMS += \
    administratorwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    registerwindow.ui \
    storemanagerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
