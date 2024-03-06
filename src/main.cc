#include <QApplication>

#include "controller/controller.h"
#include "model/calculator.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  s21::MainWindow main_window;

  s21::Controller controller(&main_window);

  main_window.show();
  return app.exec();
}
