// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <QMainWindow>
#include <QDockWidget>
#include <QAction>
#include <QStatusBar>

#include "LayoutWidget.hpp"
#include "LayoutDrawer.hpp"
#include "../layout/Layout.hpp"
#include "LayoutWidget.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT
private:
  // Dock widgets
  QDockWidget              *p_dockConsole       = nullptr,
                           *p_dockLayout        = nullptr;
  // Actions
  QAction                  *p_actFileOpen       = nullptr,
                           *p_actFileExit       = nullptr,
                           *p_actHelpAbout      = nullptr,
                           *p_actHelpAboutQt    = nullptr;
  // Status bar
  QStatusBar               *p_statusBar         = nullptr;
  // Layout
  LayoutDrawer             *p_drawer            = nullptr;
  Layout                    layout;
  LayoutWidget             *p_layoutWidget      = nullptr;
public:
  MainWindow();
 ~MainWindow();
public:
private:
  void InitActions();
  void InitMenubar();
  void InitToolbar();
  void InitStatusbar();
  void InitMainUI();
private slots:
  void OnMenu_File_Open();
  void OnMenu_File_Exit();
  void OnMenu_Help_About();
  void OnMenu_Help_AboutQt();
};
