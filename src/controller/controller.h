#ifndef __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__
#define __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__

#include <QMainWindow>
#include <QPushButton>

#include "../view/include/mainwindow.h"

namespace s21 {

class Controller : public QObject {
  Q_OBJECT
 public:
  Controller(MainWindow *view);

 public slots:
  void calculateGraphValues();
  void calculateMathExpression();
  void calculateCredit();

 private:
  void connectGraphElements();
  void connectMathCalculatorElements();
  void connectCreditCalculatorElements();

 private:
  MainWindow *view_;
};

}  // namespace s21

#endif  // __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__