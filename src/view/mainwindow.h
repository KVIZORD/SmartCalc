#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  static const int kMaxHistorySize = 5;

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
  void addToHistoryExpression(std::string expression);

 private:
  void updateHistoryExpressions();
  std::list<std::string> expressionHistory_;
  Ui::MainWindow *ui_;
};
#endif  // MAINWINDOW_H
