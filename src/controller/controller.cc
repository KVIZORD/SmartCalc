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

  view_->ClearExpression();

  if (std::isnan(result)) {
    view_->AddToHistoryExpressions("Error");
  } else {
    view_->AddToHistoryExpressions(expression + "=" + std::to_string(result));
  }
}

// void Controller::UpdateGraph() {
// 	double x_start = view_->GetGraphValues().x_start;
// 	double x_end = view_->GetGraphValues().x_end;
// 	double y_start = view_->GetGraphValues().y_start;
// 	double y_end = view_->GetGraphValues().y_end;

//   ui_->graphWidget->xAxis->setRange(x_start, x_end);
//   ui_->graphWidget->yAxis->setRange(y_start, y_end);

// 	ui_->graphWidget->addGraph();
// 	for (int i = x_start; i < x_end; i += step){

// 	ui_->graphWidget->graph(0)->addData(i, );

// 	}

// 	ui_->graphWidget->replot();

//   ui_->functionViewTextEdit->setPlainText(GetExpression());
// }

// std::vector<double> Controller::CalculateGraphYValues() {
//   double x_start = view_->GetGraphValues().x_start;
//   double x_end = view_->GetGraphValues().x_end;
//   double y_start = view_->GetGraphValues().y_start;
//   double y_end = view_->GetGraphValues().y_end;
//   double step = view_->GetGraphValues().step;

//   std::vector<double> y;

//   std::string expression = view_->GetExpression().toStdString();

//   for (int i = x_start; i < x_end; i += step) {
//     std::unordered_map<std::string, double> var_values = {{"x", i}};
//     y.push_back(calculator_->Calculate(expression, var_values));
//   }

//   return y;
// }

}  // namespace s21