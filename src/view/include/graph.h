#ifndef GRAPH_H
#define GRAPH_H

#include <QDoubleSpinBox>
#include <QWidget>
#include <vector>

namespace Ui {
class Graph;
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  void SetExpression(std::string expression);
  void ClearGraph();
  std::string GetExpression();
  void AddPoint(double x, double y);

  double GetXStart();
  double GetXEnd();
  double GetyStart();
  double GetyEnd();
  double GetStep();

  QDoubleSpinBox *GetXStartSpinBox() const;
  QDoubleSpinBox *GetXEndSpinBox() const;
  QDoubleSpinBox *GetYStartSpinBox() const;
  QDoubleSpinBox *GetYEndSpinBox() const;
  QDoubleSpinBox *GetStepSpinBox() const;

  void UpdateGraphInformation();
  void UpdateGraph();
  ~Graph();

 private:
  double x_start_;
  double x_end_;
  double y_start_;
  double y_end_;
  double step_;

  Ui::Graph *ui_;
  std::string expression_;
  std::vector<double> x_;
  std::vector<double> y_;
};
#endif  // GRAPH_H
