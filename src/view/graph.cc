
#include "include/graph.h"

#include <QDoubleSpinBox>

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent), ui_(new Ui::Graph) {
  ui_->setupUi(this);

  ui_->graphWidget->addGraph();

  connect(ui_->xStartDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::UpdateGraphInformation);
  connect(ui_->xEndDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::UpdateGraphInformation);
  connect(ui_->yStartDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::UpdateGraphInformation);
  connect(ui_->yEndDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::UpdateGraphInformation);
  connect(ui_->stepDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::UpdateGraphInformation);
}

Graph::~Graph() { delete ui_; }

void Graph::UpdateGraphInformation() {
  x_start_ = ui_->xStartDoubleSpin->value();
  x_end_ = ui_->xEndDoubleSpin->value();
  y_start_ = ui_->yStartDoubleSpin->value();
  y_end_ = ui_->yEndDoubleSpin->value();
  step_ = ui_->stepDoubleSpin->value();
}

void Graph::UpdateGraph() {
  ui_->functionViewTextEdit->setPlainText(QString::fromStdString(expression_));
  ui_->graphWidget->xAxis->setRange(x_start_, x_end_);
  ui_->graphWidget->yAxis->setRange(y_start_, y_end_);

  QVector<double> qX(x_.begin(), x_.end());
  QVector<double> qY(y_.begin(), y_.end());

  ui_->graphWidget->graph(0)->setData(qX, qY);

  ui_->graphWidget->replot();
}

void Graph::AddPoint(double x, double y) {
  x_.push_back(x);
  y_.push_back(y);
}

void Graph::ClearGraph() {
  x_.clear();
  y_.clear();
}

double Graph::GetXStart() { return x_start_; }
double Graph::GetXEnd() { return x_end_; }
double Graph::GetyStart() { return y_start_; }
double Graph::GetyEnd() { return y_end_; }
double Graph::GetStep() { return step_; }

std::string Graph::GetExpression() { return expression_; }

QDoubleSpinBox *Graph::GetXStartSpinBox() const {
  return ui_->xStartDoubleSpin;
}
QDoubleSpinBox *Graph::GetXEndSpinBox() const { return ui_->xEndDoubleSpin; }
QDoubleSpinBox *Graph::GetYStartSpinBox() const {
  return ui_->yStartDoubleSpin;
}
QDoubleSpinBox *Graph::GetYEndSpinBox() const { return ui_->yEndDoubleSpin; }
QDoubleSpinBox *Graph::GetStepSpinBox() const { return ui_->stepDoubleSpin; }
