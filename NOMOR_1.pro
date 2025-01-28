QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deleteitem.cpp \
    insertitem.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    deleteitem.h \
    insertitem.h \
    mainwindow.h

FORMS += \
    deleteitem.ui \
    insertitem.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 2540124633 - Lie Reubensto
