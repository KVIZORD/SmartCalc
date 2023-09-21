#include "include/mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->num0Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num1Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num2Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num3Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num4Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num5Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num6Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num7Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num8Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->num9Button, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);

  connect(ui_->minusButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->plusButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->multiplyButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->divideButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);

  connect(ui_->closeBracketButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->openBracketButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->pointButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->expButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->scienceNotationButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->varXButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);

  connect(ui_->funcAcosButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcAtanButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcCosButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcLnButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcLogButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcModButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcSinButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcSqrtButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);
  connect(ui_->funcTanButton, &QPushButton::clicked, this,
          &MainWindow::addToExpressionFromButton);

  connect(ui_->allClearButton, &QPushButton::clicked, this,
          &MainWindow::clearCurrentExpression);
  connect(ui_->removeSymButton, &QPushButton::clicked, this,
          &MainWindow::removeLastSymbolFromCurrentExpression);

	connect(ui_->buildGraphButton, &QPushButton::clicked, this,
          &MainWindow::updateGraphExpression);
  connect(ui_->buildGraphButton, &QPushButton::clicked, &graph_,
          &Graph::updateGraphInformation);
}

QString MainWindow::getCurrentExpression() {
  return ui_->expressionLineEdit->text();
}
void MainWindow::setCurrentExpression(QString text) {
  ui_->expressionLineEdit->setText(text);
}
void MainWindow::clearCurrentExpression() { setCurrentExpression(""); }
void MainWindow::removeLastSymbolFromCurrentExpression() {
  if (!getCurrentExpression().isEmpty()) {
    QString expression = getCurrentExpression().chopped(1);
    setCurrentExpression(expression);
  }
}

void MainWindow::addToExpressionFromButton() {
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

  if (clickedButton) {
    QString buttonText = clickedButton->text();

    if (clickedButton->objectName().startsWith("func")) {
      buttonText += "(";
    }

    setCurrentExpression(getCurrentExpression() + buttonText);
  }
}

QPushButton *MainWindow::getCalculateButton() { return ui_->calculateButton; }

QPushButton *MainWindow::getGraphButton() { return ui_->buildGraphButton; }

double MainWindow::getVariableXValue() { return ui_->varXDoubleSpin->value(); }

std::list<std::string> MainWindow::getExpressionHistory() {
  return expressionHistory_;
}

void MainWindow::addToExpressionHistory(std::string expression) {
  if (expressionHistory_.size() == kMaxHistorySize) {
    expressionHistory_.pop_back();
  }
  expressionHistory_.push_front(expression);

  updateHistoryExpressions();
}

void MainWindow::updateHistoryExpressions() {
  QString history = "";
  for (std::string i : expressionHistory_) {
    history += QString::fromStdString(i + "\n");
  }

  ui_->historyTextEdit->setPlainText(history);
}

void MainWindow::updateGraphExpression() {
  graph_.setCurrentExpression(getCurrentExpression().toStdString());
}

void MainWindow::showGraphPlotterWindow() {
  graph_.updateGraph();
  graph_.show();
}

MainWindow::~MainWindow() { delete ui_; }
