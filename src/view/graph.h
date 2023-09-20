#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>

namespace Ui {
class Graph;
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  void SetExpression(std::string expression);
  ~Graph();

 private:
  void UpdateGraph();

  Ui::Graph *ui_;
  std::string expression_;
};

#endif  // GRAPH_H
