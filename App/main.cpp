#include "mainwindow.hpp"
#include "Application.hpp"

using namespace std;

//// int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
int main(int argc, char ** argv)
  {

  // Application app(argc, argv);
  int argcCustom = 0;
  Application app(argcCustom, 0);
  MainWindow mainWindow;// = new MainWindow();

  mainWindow.show();
  return app.exec();
  }

