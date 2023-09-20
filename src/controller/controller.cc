#include "controller.h"

#include <cmath>

namespace s21 {

Controller::Controller(MainWindow *view, Calculator *calculator)
    : view_(view), calculator_(calculator) {
  connect(view_->getCalculateButton(), &QPushButton::clicked, this,
          &Controller::calculateMathExpression);
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

void Controller::calculateMathExpression() {
  double result;

  double var_x = view_->getVariableXValue();
  std::string expression = view_->getCurrentExpression().toStdString();
  std::unordered_map<std::string, double> var_values = {{"x", var_x}};

  try {
    result = calculator_->calculate(expression, var_values);
  } catch (const std::invalid_argument &e) {
    result = std::numeric_limits<double>::quiet_NaN();
  }

  view_->clearCurrentExpression();

  if (std::isnan(result)) {
    view_->addToExpressionHistory("Error");
  } else {
    view_->addToExpressionHistory(expression + "=" + std::to_string(result));
  }
}

void Controller::calculateGraphValues() {
  view_->graph_.clearGraph();

  double x_start = view_->graph_.getXStart();
  double x_end = view_->graph_.getXEnd();
  double step = view_->graph_.getStep();

  std::string expression = view_->getCurrentExpression().toStdString();

  for (double i = x_start; i <= x_end; i += step) {
    std::unordered_map<std::string, double> var_values = {{"x", i}};
    view_->graph_.addPoint(i, calculator_->calculate(expression, var_values));
  }

  view_->showGraphPlotterWindow();
}

}  // namespace s21