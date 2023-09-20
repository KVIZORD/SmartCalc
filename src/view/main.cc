#include <QApplication>

#include "include/mainwindow.h"
#include "../controller/controller.h"
#include "../model/calculator.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow view;
	s21::Calculator calculator;

	s21::Controller controller(&view, &calculator);
	
  view.show();
  return app.exec();
}
