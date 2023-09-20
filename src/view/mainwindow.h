#ifndef __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__
#define __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__

#include <QMainWindow>
#include <QPushButton>
#include <list>
#include "graph.h"

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

  void AddTextFromButtonToExpression();

  QString GetExpression();
  void SetExpression(QString text);
  void ClearExpression();
  void RemoveLastSymFromExpression();
  QPushButton *GetCalculateButton() const;
  double GetVarXValue() const;
  std::list<std::string> GetHistoryExpressions() const;
  void AddToHistoryExpressions(std::string expression);
	void ShowGraphWindow();

 private:
  void UpdateHistoryExpressions();

 public:
  static const int kMaxHistorySize = 5;

 private:
  std::list<std::string> expressionHistory_;
  Ui::MainWindow *ui_;
	Graph graph_;
};
#endif  // __SMARTCALC_V2_0_SRC_VIEW_MAINWINDOW_H__
