QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = bin
OBJECTS_DIR=generated_files
MOC_DIR=generated_files
UI_DIR=headers

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp 


HEADERS += \
    mainwindow.h \


FORMS += \
    mainwindow.ui \


include(Account/account.pri)
include(CB/cb.pri)
include(CMS/cms.pri)
include(Comm/comm.pri)
include(CB/cb.pri)
include(DT/dt.pri)
include(Ecom/ecom.pri)
include(Forum/forum.pri)
include(HR/hr.pri)
include(License/license.pri)
include(PM/pm.pri)
include(TT/tt.pri)
include(Services/Services.pri)


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
