lessThan(QT_MAJOR_VERSION, 5): error(This project requires Qt 5 or later)

QT += core gui widgets quick

MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = $$PWD/bin

TARGET = widgetsandqml
TEMPLATE = app

SOURCES += main.cpp mainwindow.cpp \
    qmlcontainer.cpp

HEADERS  += mainwindow.h \
    qmlcontainer.h

FORMS    += mainwindow.ui \
    qmlcontainer.ui

OTHER_FILES += main.qml

RESOURCES += \
    qml.qrc
