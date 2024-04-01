equals(QT_MAJOR_VERSION, 5) {
    QT += core gui widgets opengl
} else {
    QT += core gui widgets opengl openglwidgets
}

TARGET = HDLDebugger

Release:DESTDIR = ../../bin
Release:OBJECTS_DIR = ../../bin
Release:MOC_DIR = ../../bin/.moc
Release:RCC_DIR = ../../bin
Release:UI_DIR = ../../bin/.ui

Debug:DESTDIR = ../../bin
Debug:OBJECTS_DIR = ../../bin
Debug:MOC_DIR = ../../bin/.moc
Debug:RCC_DIR = ../../bin
Debug:UI_DIR = ../../bin/.ui

CONFIG += c++1z static

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    ../../sources/gui/LayoutDrawer.hpp \
    ../../sources/gui/LayoutWidget.hpp \
    ../../sources/gui/Logger.hpp \
    ../../sources/gui/MainWindow.hpp \ \
    ../../sources/gui/dialogs/About.hpp \
    ../../sources/layout/GDSIIHelperFunctions.hpp \
    ../../sources/layout/GDSIITypes.hpp \
    ../../sources/layout/Layout.hpp \
    ../../sources/layout/LayoutProcessing.hpp \
    ../../sources/layout/LayoutReader.hpp \
    ../../sources/layout/LayoutReader_CIF.hpp \
    ../../sources/layout/LayoutReader_DXF.hpp \
    ../../sources/layout/LayoutReader_GDSIIascii.hpp \
    ../../sources/layout/LayoutReader_GDSIIbin.hpp \
    ../../sources/layout/LayoutReader_MAG.hpp \
    ../../sources/layout/LayoutReader_MSK.hpp \
    ../../sources/layout/LayoutReader_OASIS.hpp \
    ../../sources/layout/LayoutWriter.hpp \
    ../../sources/layout/LayoutWriter_CIF.hpp \
    ../../sources/layout/LayoutWriter_DXF.hpp \
    ../../sources/layout/LayoutWriter_GDSIIascii.hpp \
    ../../sources/layout/LayoutWriter_GDSIIbin.hpp \
    ../../sources/layout/LayoutWriter_MAG.hpp \
    ../../sources/layout/LayoutWriter_MSK.hpp \
    ../../sources/layout/LayoutWriter_OASIS.hpp \
    ../../sources/layout/LinuxCompat.hpp


SOURCES += \
    ../../sources/gui/LayoutDrawer.cpp \
    ../../sources/gui/LayoutWidget.cpp \
    ../../sources/gui/Logger.cpp \
    ../../sources/gui/MainWindow.cpp \
    ../../sources/gui/dialogs/About.cpp \
    ../../sources/layout/GDSIIHelperFunctions.cpp \
    ../../sources/layout/LayoutProcessing.cpp \
    ../../sources/layout/LayoutReader.cpp \
    ../../sources/layout/LayoutReader_CIF.cpp \
    ../../sources/layout/LayoutReader_DXF.cpp \
    ../../sources/layout/LayoutReader_GDSIIascii.cpp \
    ../../sources/layout/LayoutReader_GDSIIbin.cpp \
    ../../sources/layout/LayoutReader_MAG.cpp \
    ../../sources/layout/LayoutReader_MSK.cpp \
    ../../sources/layout/LayoutReader_OASIS.cpp \
    ../../sources/layout/LayoutWriter.cpp \
    ../../sources/layout/LayoutWriter_CIF.cpp \
    ../../sources/layout/LayoutWriter_DXF.cpp \
    ../../sources/layout/LayoutWriter_GDSIIascii.cpp \
    ../../sources/layout/LayoutWriter_GDSIIbin.cpp \
    ../../sources/layout/LayoutWriter_MAG.cpp \
    ../../sources/layout/LayoutWriter_MSK.cpp \
    ../../sources/layout/LayoutWriter_OASIS.cpp \
    ../../sources/main.cpp 

RESOURCES += \
    ../../resources/LayoutViewer.qrc
