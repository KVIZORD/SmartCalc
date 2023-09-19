#include "controller.h"

#include <cmath>

namespace s21 {

void Controller::Calculate() {
  double result;
  std::string expression = view_->GetExpression().toStdString();

  try {
    result = calculator_->Calculate(expression);
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