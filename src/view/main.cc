#include <QApplication>

#include "../controller/controller.h"
#include "../model/calculator.h"
#include "include/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow view;

  s21::Controller controller(&view);

  view.show();
  return app.exec();
}
