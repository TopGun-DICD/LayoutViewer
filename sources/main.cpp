// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#if defined _WIN32
#include <windows.h>
#endif

#include <QApplication>
#include <QResource>
#include <QIcon>

#include "gui/MainWindow.hpp"

#if defined _WIN32 && defined _MSC_VER
int APIENTRY WinMain( HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     pCmdLine,
                      int       nCmdShow) {
  int     argc = 0;
  char  **argv = nullptr;
#else
int main(int argc, char* argv[]) {
#endif
  QResource::registerResource("LayoutViewer.rcc");

  QStringList paths = QCoreApplication::libraryPaths();
  paths.append(".");
  paths.append("plugins");
  paths.append("platforms");
  QCoreApplication::setLibraryPaths(paths);

  QApplication app(argc, argv);
  app.setWindowIcon(QIcon(":/other/appicon.png"));

  MainWindow *p_mainWindow = new MainWindow;
  if (!p_mainWindow)
    return 2;

  p_mainWindow->show();

  int retCode = app.exec();
  return retCode;
}
