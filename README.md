# LayoutViewer
Layout viewer is a project aimed to implement and test different IC layout processing algorithms.
The GUI implemented using the Qt library.

## Building the project
One can build the project using MS Visual Studio 2019, MS Visual Studuio 2022 and QtCreator.


If QtCreator is used the working path should be set to the **bin** directory.

To build the project using MS Visual Studio the **%QTDIR%** environment variable has to be set the the path where Qt library is installed. For example: QTDIR=D:\Qt\Qt5.14.1\5.14.1\msvc2017_64
Alse some dll files should be written into the **bin** folder. They are:
 - Qt5Cored.dll (for the debug mode) or Qt5Cored.dll (for the release mode)
 - Qt5Guid.dll (for the debug mode) or Qt5Gui.dll (for the release mode)
 - Qt5Widgetsd.dll (for the debug mode) or Qt5Widgets.dll (for the release mode)

### Current Version: 0.0.1
In this version only the basic functionality was implemented.
 ![v.0.0.1](https://github.com/TopGun-DICD/LayoutViewer/blob/main/resources/git/LayoutViewer_0.0.1.png)

