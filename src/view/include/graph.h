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
  ~Graph();

  void setExpression(std::string expression);
  void clearGraph();
  std::string getCurrentExpression();
  void addPoint(double x, double y);

  double getXStart();
  double getXEnd();
  double getyStart();
  double getyEnd();
  double getStep();

  QDoubleSpinBox *getXStartSpinBox();
  QDoubleSpinBox *getXEndSpinBox();
  QDoubleSpinBox *getYStartSpinBox();
  QDoubleSpinBox *getYEndSpinBox();
  QDoubleSpinBox *getStepSpinBox();

  void updateGraphInformation();
  void updateGraph();
  std::string expression_;

 private:
  double x_start_;
  double x_end_;
  double y_start_;
  double y_end_;
  double step_;

  Ui::Graph *ui_;
  std::vector<double> x_;
  std::vector<double> y_;
};
#endif  // GRAPH_H
