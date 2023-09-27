#include "controller.h"

#include <QStandardItemModel>
#include <cmath>

#include "../model/calculator.h"
#include "../model/credit.h"

namespace s21 {

Controller::Controller(MainWindow* view) : view_(view) {
  connectMathCalculatorElements();
  connectGraphElements();
  connectCreditCalculatorElements();
}

void Controller::connectMathCalculatorElements() {
  connect(view_->getCalculateButton(), &QPushButton::clicked, this,
          &Controller::calculateMathExpression);
}

void Controller::connectGraphElements() {
  connect(view_->getGraphButton(), &QPushButton::clicked, this,
          &Controller::calculateGraphValues);
  connect(view_->graph_.getXStartSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::calculateGraphValues);
  connect(view_->graph_.getXEndSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::calculateGraphValues);
  connect(view_->graph_.getYStartSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::calculateGraphValues);
  connect(view_->graph_.getYEndSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::calculateGraphValues);
  connect(view_->graph_.getStepSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::calculateGraphValues);
}

void Controller::connectCreditCalculatorElements() {
  connect(view_->credit_.getCalculateButton(), &QPushButton::clicked, this,
          &Controller::calculateCredit);
}

void Controller::calculateMathExpression() {
  Calculator calculator;
  double result;

  double var_x = view_->getVariableXValue();
  std::string expression = view_->getCurrentExpression().toStdString();
  std::unordered_map<std::string, double> var_values = {{"x", var_x}};

  try {
    result = calculator.calculate(expression, var_values);
  } catch (const std::invalid_argument& e) {
    result = std::numeric_limits<double>::quiet_NaN();
  }

  view_->clearCurrentExpression();

  if (std::isnan(result)) {
    view_->addToExpressionHistory(kErrorMessage);
  } else {
    view_->addToExpressionHistory(expression + "=" + std::to_string(result));
  }
}

void Controller::calculateGraphValues() {
  Calculator calculator;
  view_->graph_.clearGraph();

  double x_start = view_->graph_.getXStart();
  double x_end = view_->graph_.getXEnd();
  double step = view_->graph_.getStep();

  std::string expression = view_->graph_.getCurrentExpression();

  for (double i = x_start; i <= x_end; i += step) {
    std::unordered_map<std::string, double> var_values = {{"x", i}};
    view_->graph_.addPoint(i, calculator.calculate(expression, var_values));
  }

  view_->showGraphPlotterWindow();
}

void Controller::calculateCredit() {
  double amount = view_->credit_.getAmount();
  int term = view_->credit_.getTerm();
  double rate = view_->credit_.getRate();
  Credit::RepaymentType repayment_type;

  if (view_->credit_.getRepaymentType() == view_->credit_.kAnnuityPaymentType) {
    repayment_type = Credit::RepaymentType::Annuity;
  } else {
    repayment_type = Credit::RepaymentType::Differentiated;
  }

  Credit credit(amount, term, rate, repayment_type);
  std::vector<Credit::PaymentDetail> payment_detail =
      credit.calculatePaymentDetails();

  int row = 0;

  for (auto i : payment_detail) {
    view_->credit_.addToTable(row, 0, QString::number(i.number));
    view_->credit_.addToTable(row, 1, QString::number(i.total_payment));
    view_->credit_.addToTable(row, 2, QString::number(i.principal_payment));
    view_->credit_.addToTable(row, 3, QString::number(i.interest_payment));
    view_->credit_.addToTable(row, 4, QString::number(i.remaining_balance));

    ++row;
  }

  view_->credit_.setOverpayment(QString::number(credit.calculateOverpayment()));
  view_->credit_.setTotalPayment(
      QString::number(credit.calculateTotalPayment()));

  view_->credit_.updatePaymentTable();
}

}  // namespace s21