#-------------------------------------------------
#
# Project created by QtCreator 2021-12-04T15:58:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShareCountv5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
LIBS += -lboost_serialization

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    Person.cpp \
    Group.cpp \
    GroupListModel.cpp \
    GroupList.cpp \
    DialogGroupList.cpp \
    Money.cpp \
    User.cpp \
    Recepisse.cpp \
    AddPayerDialog.cpp \
    ConvertToAmount.cpp \
    Payee.cpp \
    ReceiptUI.cpp \
    ReceiptCollection.cpp \
    ReceiptCollectionModel.cpp \
    ReceiptPayerModel.cpp \
    PayeeListDialog.cpp

HEADERS += \
        MainWindow.h \
    Person.h \
    Group.h \
    GroupListModel.h \
    DialogGroupList.h \
    GroupList.h \
    User.h \
    Money.h \
    Recepisse.h \
    ConvertToAmount.h \
    AddPayerDialog.h \
    Payee.h \
    QStringSerialize.h \
    ReceiptUI.h \
    ReceiptUI.h \
    ReceiptCollection.h \
    ReceiptCollectionModel.h \
    ReceiptPayerModel.h \
    PayeeListDialog.h


FORMS += \
    DialogGroupList.ui \
    MainWindow.ui \
    DialogGroupList.ui \
    GroupList.ui \
    AddPayerDialog.ui \
    ReceiptUI.ui \
    PayeeListDialog.ui
