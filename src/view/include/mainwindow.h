#ifndef __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__
#define __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__

#include <QMainWindow>
#include <QPushButton>
#include <list>

#include "graph.h"
#include "creditcalculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void addToExpressionFromButton();
  QString getCurrentExpression();
  void setCurrentExpression(QString text);
  void clearCurrentExpression();
  void removeLastSymbolFromCurrentExpression();
  QPushButton *getCalculateButton();
  QPushButton *getGraphButton();
  double getVariableXValue();
  std::list<std::string> getExpressionHistory();
  void addToExpressionHistory(std::string expression);
  void showGraphPlotterWindow();
  void showCreditCalculatorWindow();

 private:
  void updateHistoryExpressions();
	void updateGraphExpression();

 public:
  static const int kMaxHistorySize = 5;
  Graph graph_;
	CreditCalculator credit_;

 private:
  std::list<std::string> expressionHistory_;
  Ui::MainWindow *ui_;
};
#endif  // __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__
