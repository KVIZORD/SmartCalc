QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditcalculator.cpp \
    graph.cc \
    main.cc \
    mainwindow.cc \
		../controller/controller.cc \
		../model/calculator.cc \
		../model/credit.cc \
    qcustomplot.cc
HEADERS += \
    include/creditcalculator.h \
    include/graph.h \
    include/mainwindow.h \
		../controller/controller.h \
		../model/calculator.h \
		../model/credit.h \
    include/qcustomplot.h

FORMS += \
    ui/creditcalculator.ui \
    ui/graph.ui \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
