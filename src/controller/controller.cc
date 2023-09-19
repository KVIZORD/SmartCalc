#include "controller.h"

#include <cmath>

namespace s21 {

void Controller::Calculate() {
  double result;

  double var_x = view_->GetVarXValue();
  std::string expression = view_->GetExpression().toStdString();
  std::unordered_map<std::string, double> var_values = {{"x", var_x}};

  try {
    result = calculator_->Calculate(expression, var_values);
  } catch (const std::invalid_argument& e) {
    result = std::numeric_limits<double>::quiet_NaN();
  }

  if (std::isnan(result)) {
    view_->SetExpression("Error");
  } else {
    view_->SetExpression(QString::number(result));
  }
}

}  // namespace s21