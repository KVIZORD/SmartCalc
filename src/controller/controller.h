#ifndef __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__
#define __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__

#include <QMainWindow>
#include <QPushButton>

#include "../model/calculator.h"
#include "../view/mainwindow.h"

namespace s21 {

class Controller : public QObject {
  Q_OBJECT
 public:
  Controller(MainWindow *view, Calculator *calculator)
      : view_(view), calculator_(calculator) {
    connect(view_->GetCalculateButton(), &QPushButton::clicked, this,
            &Controller::Calculate);
  }

  std::vector<double> CalculateGraphYValues();
  void Calculate();

 private:
  MainWindow *view_;
  Calculator *calculator_;
};

}  // namespace s21

#endif