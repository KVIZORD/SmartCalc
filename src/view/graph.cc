#include "graph.h"

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QWidget(parent), ui_(new Ui::Graph) {
  ui_->setupUi(this);
}

Graph::~Graph() { delete ui_; }

void Graph::SetExpression(std::string expression) {
  expression_ = expression;
  UpdateGraph();
}

void Graph::UpdateGraph() {
  ui_->functionViewTextEdit->setPlainText(QString::fromStdString(expression_));
}