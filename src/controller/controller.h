#ifndef __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__
#define __SMARTCALC_V2_0_SRC_CONTROLLER_CONTROLLER_H__

#include <QMainWindow>
#include <QPushButton>

#include "view/mainwindow.h"

namespace s21 {

class Controller : public QObject {
  Q_OBJECT
 public:
  const std::string kErrorCalculateMessage = "Ошибка вычисления";

 public:
  explicit Controller(MainWindow *view);

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