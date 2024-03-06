#ifndef __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__
#define __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__

#include <QMainWindow>
#include <QPushButton>
#include <list>

#include "view/creditcalculator.h"
#include "view/graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  static const int kMaxHistorySize = 5;

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void addToExpressionFromButton();
  void addToExpressionHistory(const std::string &expression);

  void setCurrentExpression(const QString &text);
  void clearCurrentExpression();
  void removeLastSymbolFromCurrentExpression();

  QPushButton *getCalculateButton();
  QPushButton *getGraphButton();
  std::list<std::string> getExpressionHistory();
  QString getCurrentExpression();
  double getVariableXValue();

 public slots:
  void showGraphPlotterWindow();
  void showCreditCalculatorWindow();

 private:
  void updateHistoryExpressions();
  void updateGraphExpression();

 public:
  Graph graph_;
  CreditCalculator credit_;

 private:
  std::list<std::string> expressionHistory_;
  Ui::MainWindow *ui_;
};

}  // namespace s21

#endif  // __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__
