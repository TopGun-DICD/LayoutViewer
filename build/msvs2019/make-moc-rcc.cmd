@echo off

set QT_BIN=%QTDIR%\bin

set MOC=%QT_BIN%\moc.exe
set RCC=%QT_BIN%\rcc.exe

:: == Main ==
%MOC% -o moc\moc_MainWindow.cpp 			..\..\sources\gui\MainWindow.hpp
%MOC% -o moc\moc_Logger.cpp 				..\..\sources\gui\Logger.hpp
%MOC% -o moc\moc_LayoutWidget.cpp 			..\..\sources\gui\LayoutWidget.hpp
%MOC% -o moc\moc_LayoutDrawer.cpp 			..\..\sources\gui\LayoutDrawer.hpp
:: == Dialogs ==
%MOC% -o moc\moc_About.cpp 					..\..\sources\gui\dialogs\About.hpp

:: == Resources ==
%RCC% -binary ..\..\resources\LayoutViewer.qrc -o ..\..\bin\LayoutViewer.rcc

pause
