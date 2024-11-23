QT += core gui widgets network

QT += webenginewidgets

RC_FILE = app_icon.rc


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filedownloader.cpp \
    main.cpp \
    onlineide.cpp

HEADERS += \
    filedownloader.h \
    onlineide.h

FORMS += \
    onlineide.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc

DISTFILES += \
    app_icon.rc \
    app_icon.rc
