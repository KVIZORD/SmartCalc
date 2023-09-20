#include "include/mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->num0Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num1Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num2Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num3Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num4Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num5Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num6Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num7Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num8Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->num9Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui_->minusButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->plusButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->multiplyButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->divideButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui_->closeBracketButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->openBracketButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->pointButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->expButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->scienceNotationButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->varXButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui_->funcAcosButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcAtanButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcCosButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcLnButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcLogButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcModButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcSinButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcSqrtButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui_->funcTanButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui_->allClearButton, &QPushButton::clicked, this,
          &MainWindow::ClearExpression);
  connect(ui_->removeSymButton, &QPushButton::clicked, this,
          &MainWindow::RemoveLastSymFromExpression);

  connect(ui_->buildGraphButton, &QPushButton::clicked, &graph_,
          &Graph::UpdateGraphInformation);
}

QString MainWindow::GetExpression() { return ui_->expressionLineEdit->text(); }
void MainWindow::SetExpression(QString text) {
  ui_->expressionLineEdit->setText(text);
}
void MainWindow::ClearExpression() { SetExpression(""); }
void MainWindow::RemoveLastSymFromExpression() {
  if (!GetExpression().isEmpty()) {
    QString expression = GetExpression().chopped(1);
    SetExpression(expression);
  }
}

void MainWindow::AddTextFromButtonToExpression() {
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

  if (clickedButton) {
    QString buttonText = clickedButton->text();

    if (clickedButton->objectName().startsWith("func")) {
      buttonText += "(";
    }

    SetExpression(GetExpression() + buttonText);
  }
}

QPushButton *MainWindow::GetCalculateButton() const {
  return ui_->calculateButton;
}

QPushButton *MainWindow::GetGraphButton() const {
  return ui_->buildGraphButton;
}

double MainWindow::GetVarXValue() const { return ui_->varXDoubleSpin->value(); }

std::list<std::string> MainWindow::GetHistoryExpressions() const {
  return expressionHistory_;
}

void MainWindow::AddToHistoryExpressions(std::string expression) {
  if (expressionHistory_.size() == kMaxHistorySize) {
    expressionHistory_.pop_back();
  }
  expressionHistory_.push_front(expression);

  UpdateHistoryExpressions();
}

void MainWindow::UpdateHistoryExpressions() {
  QString history = "";
  for (std::string i : expressionHistory_) {
    history += QString::fromStdString(i + "\n");
  }

  ui_->historyTextEdit->setPlainText(history);
}

void MainWindow::ShowGraphWindow() { graph_.show(); }

MainWindow::~MainWindow() { delete ui_; }
