#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->num0Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num1Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num2Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num3Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num4Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num5Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num6Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num7Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num8Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->num9Button, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui->minusButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->plusButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->multiplyButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->divideButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui->closeBracketButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->openBracketButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->pointButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->expButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->scienceNotationButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->varXButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui->funcAcosButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcAtanButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcCosButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcLnButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcLogButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcModButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcSinButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcSqrtButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);
  connect(ui->funcTanButton, &QPushButton::clicked, this,
          &MainWindow::AddTextFromButtonToExpression);

  connect(ui->allClearButton, &QPushButton::clicked, this,
          &MainWindow::ClearExpression);
  connect(ui->removeSymButton, &QPushButton::clicked, this,
          &MainWindow::RemoveLastSymFromExpression);
}

QString MainWindow::GetExpression() { return ui->expressionLabel->text(); }
void MainWindow::SetExpression(QString text) {
  ui->expressionLabel->setText(text);
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
  return ui->calculateButton;
}

MainWindow::~MainWindow() { delete ui; }
