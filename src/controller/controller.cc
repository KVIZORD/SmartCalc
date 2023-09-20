#include "controller.h"

#include <cmath>

namespace s21 {

Controller::Controller(MainWindow *view, Calculator *calculator)
    : view_(view), calculator_(calculator) {
  connect(view_->GetCalculateButton(), &QPushButton::clicked, this,
          &Controller::Calculate);
  connect(view_->GetGraphButton(), &QPushButton::clicked, this,
          &Controller::CalculateGraphValues);

  connect(view_->graph_.GetXStartSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::CalculateGraphValues);
  connect(view_->graph_.GetXEndSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::CalculateGraphValues);
  connect(view_->graph_.GetYStartSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::CalculateGraphValues);
  connect(view_->graph_.GetYEndSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::CalculateGraphValues);
  connect(view_->graph_.GetStepSpinBox(),
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &Controller::CalculateGraphValues);
}

void Controller::Calculate() {
  double result;

  double var_x = view_->GetVarXValue();
  std::string expression = view_->GetExpression().toStdString();
  std::unordered_map<std::string, double> var_values = {{"x", var_x}};

  try {
    result = calculator_->Calculate(expression, var_values);
  } catch (const std::invalid_argument &e) {
    result = std::numeric_limits<double>::quiet_NaN();
  }

  view_->ClearExpression();

  if (std::isnan(result)) {
    view_->AddToHistoryExpressions("Error");
  } else {
    view_->AddToHistoryExpressions(expression + "=" + std::to_string(result));
  }
}

void Controller::CalculateGraphValues() {
  view_->graph_.ClearGraph();

  double x_start = view_->graph_.GetXStart();
  double x_end = view_->graph_.GetXEnd();
  double step = view_->graph_.GetStep();

  std::string expression = view_->GetExpression().toStdString();

  for (double i = x_start; i <= x_end; i += step) {
    std::unordered_map<std::string, double> var_values = {{"x", i}};
    view_->graph_.AddPoint(i, calculator_->Calculate(expression, var_values));
  }

  view_->graph_.UpdateGraph();
  view_->ShowGraphWindow();
}

}  // namespace s21