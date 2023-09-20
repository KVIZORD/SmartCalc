
#include "include/graph.h"

#include <QDoubleSpinBox>

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent), ui_(new Ui::Graph) {
  ui_->setupUi(this);

  ui_->graphWidget->addGraph();

  connect(ui_->xStartDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::updateGraphInformation);
  connect(ui_->xEndDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::updateGraphInformation);
  connect(ui_->yStartDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::updateGraphInformation);
  connect(ui_->yEndDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::updateGraphInformation);
  connect(ui_->stepDoubleSpin,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Graph::updateGraphInformation);
}

Graph::~Graph() { delete ui_; }

void Graph::updateGraphInformation() {
  x_start_ = ui_->xStartDoubleSpin->value();
  x_end_ = ui_->xEndDoubleSpin->value();
  y_start_ = ui_->yStartDoubleSpin->value();
  y_end_ = ui_->yEndDoubleSpin->value();
  step_ = ui_->stepDoubleSpin->value();
}

void Graph::updateGraph() {
  ui_->expressionLineEdit->setText(QString::fromStdString(expression_));
  ui_->graphWidget->xAxis->setRange(x_start_, x_end_);
  ui_->graphWidget->yAxis->setRange(y_start_, y_end_);

  QVector<double> qX(x_.begin(), x_.end());
  QVector<double> qY(y_.begin(), y_.end());

  ui_->graphWidget->graph(0)->setData(qX, qY);

  ui_->graphWidget->replot();
}

void Graph::addPoint(double x, double y) {
  x_.push_back(x);
  y_.push_back(y);
}

void Graph::clearGraph() {
  x_.clear();
  y_.clear();
}

double Graph::getXStart() { return x_start_; }
double Graph::getXEnd() { return x_end_; }
double Graph::getyStart() { return y_start_; }
double Graph::getyEnd() { return y_end_; }
double Graph::getStep() { return step_; }

std::string Graph::getCurrentExpression() { return expression_; }

QDoubleSpinBox *Graph::getXStartSpinBox() { return ui_->xStartDoubleSpin; }
QDoubleSpinBox *Graph::getXEndSpinBox() { return ui_->xEndDoubleSpin; }
QDoubleSpinBox *Graph::getYStartSpinBox() { return ui_->yStartDoubleSpin; }
QDoubleSpinBox *Graph::getYEndSpinBox() { return ui_->yEndDoubleSpin; }
QDoubleSpinBox *Graph::getStepSpinBox() { return ui_->stepDoubleSpin; }
