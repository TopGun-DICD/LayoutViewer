// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "MainWindow.hpp"

#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QtGlobal>
#include <QMessageBox>

#include <ctime>

#include "Logger.hpp"
#include "dialogs/About.hpp"
#include "../layout/LayoutReader.hpp"

MainWindow::MainWindow() : QMainWindow(nullptr) {
  setAttribute(Qt::WA_DeleteOnClose);
  setWindowTitle(QString("LayoutViewer - v0.0.1"));
  resize(QSize(1200, 800));

  Logger::Init(this);

  InitMainUI();
  InitActions();
  InitMenubar();
  InitToolbar();
  InitStatusbar();

  Logger::Info("LayoutViewer has started");
}

MainWindow::~MainWindow() {
  Logger::Free();
}

void MainWindow::InitActions() {
  // Menu "File"
  p_actFileOpen = new QAction(QIcon(QPixmap(":/toolbar/file_open.png")), "Open", this);
  p_actFileOpen->setStatusTip("Open dialog to select design and libraries to analyze");
  p_actFileOpen->setToolTip("Open design and libraries...");
  connect(p_actFileOpen, SIGNAL(triggered()), SLOT(OnMenu_File_Open()));

  p_actFileExit = new QAction(tr("Exit"), this);
  p_actFileExit->setStatusTip("Exit this application");
  p_actFileExit->setToolTip("Exit");
  connect(p_actFileExit, SIGNAL(triggered()), SLOT(OnMenu_File_Exit()));

  // Menu "Help"
  p_actHelpAbout = new QAction("About", this);
  connect(p_actHelpAbout, SIGNAL(triggered()), SLOT(OnMenu_Help_About()));
  p_actHelpAboutQt = new QAction(QIcon(QPixmap(":/toolbar/help_qt.png")), "About Qt", this);
  connect(p_actHelpAboutQt, SIGNAL(triggered()), SLOT(OnMenu_Help_AboutQt()));
}

void MainWindow::InitMenubar() {
  QMenu *p_menuFile   = new QMenu("File");
  QMenu *p_menuHelp   = new QMenu("Help");

  // File
  p_menuFile->addAction(p_actFileOpen);
  p_menuFile->addSeparator();
  p_menuFile->addAction(p_actFileExit);
  
  // Help
  p_menuHelp->addAction(p_actHelpAbout);
  p_menuHelp->addAction(p_actHelpAboutQt);

  menuBar()->addMenu(p_menuFile);
  menuBar()->addMenu(p_menuHelp);
}

void MainWindow::InitToolbar() {
  QToolBar *p_toolBar = new QToolBar(this);
  p_toolBar->setIconSize(QSize(32, 32));

  p_toolBar->addAction(p_actFileOpen);
  //p_toolBar->addSeparator();

  addToolBar(Qt::TopToolBarArea, p_toolBar);
}

void MainWindow::InitStatusbar() {
  p_statusBar = new QStatusBar(this);
  setStatusBar(p_statusBar);
}

void MainWindow::InitMainUI() {
  // Console with Log
  p_dockConsole = new QDockWidget(tr("Console"), this);
  p_dockConsole->setWidget(Logger::p_logWidget);
  addDockWidget(Qt::BottomDockWidgetArea, p_dockConsole);
  p_dockConsole->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
  p_dockConsole->setAllowedAreas(Qt::BottomDockWidgetArea);

  // Project
  p_dockLayout = new QDockWidget(tr("Layout"), this);
  p_layoutWidget = new LayoutWidget(this, &layout);
  p_dockLayout->setWidget(p_layoutWidget);
  addDockWidget(Qt::LeftDockWidgetArea, p_dockLayout);
  p_dockLayout->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
  p_dockLayout->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
  
  p_drawer = new LayoutDrawer(this, &layout);
  setCentralWidget(p_drawer);
}

void MainWindow::OnMenu_File_Open() {
  QString fileName = QFileDialog::getOpenFileName(this, "Open layout", "tests/", "All supported layout types(*.gds *.gds2 *.gdsii *.msk);;GDSII files (*.gds *.gds2 *.gdsii);;Microwind files (*.msk);;All files (*.*)");
  if (fileName.isEmpty())
    return;
#ifdef _MSC_VER
  LayoutReader *p_reader = GetReader(fileName.toStdWString());
#else
  LayoutReader *p_reader = GetReader(fileName.toStdString());
#endif
  if (!p_reader) {
    Logger::Error(QString("Couldn't find appropriate reader for the given file: '%1'").arg(fileName));
    return;
  }
  layout.Clear();
  p_reader->Read(&layout);
  FreeReader(p_reader);

  p_layoutWidget->UpdateLayoutInfo();
  p_drawer->update();
}

void MainWindow::OnMenu_File_Exit() {
  close();
}

void MainWindow::OnMenu_Help_About() {
  Dialog_About dlg(this);
  dlg.exec();
}

void MainWindow::OnMenu_Help_AboutQt() {
  QMessageBox::aboutQt(this);
}

