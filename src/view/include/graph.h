#ifndef __SMARTCALC_V2_0_SRC_VIEW_GRAPH_H__
#define __SMARTCALC_V2_0_SRC_VIEW_GRAPH_H__

#include <QDoubleSpinBox>
#include <QWidget>
#include <vector>

namespace Ui {
class Graph;
}

namespace s21 {

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();

  void clearGraph();
  void setCurrentExpression(std::string expression);
  std::string getCurrentExpression();
  void addPoint(double x, double y);

  double getXStart();
  double getXEnd();
  double getYStart();
  double getYEnd();
  double getStep();

  QDoubleSpinBox *getXStartSpinBox();
  QDoubleSpinBox *getXEndSpinBox();
  QDoubleSpinBox *getYStartSpinBox();
  QDoubleSpinBox *getYEndSpinBox();
  QDoubleSpinBox *getStepSpinBox();

  void updateGraphInformation();
  void updateGraph();

 private:
  double x_start_;
  double x_end_;
  double y_start_;
  double y_end_;
  double step_;

  std::string expression_;

  Ui::Graph *ui_;
  std::vector<double> x_;
  std::vector<double> y_;
};

}  // namespace s21

#endif  // __SMARTCALC_V2_0_SRC_VIEW_GRAPH_H__
