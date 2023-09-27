#include "calculator.h"

#include <algorithm>
#include <cmath>
#include <locale>
#include <stack>

namespace s21 {

using Token = Calculator::Token;
using TokenType = Calculator::TokenType;

std::vector<Token> Calculator::tokenizeExpression(
    const std::string &expression) const {
  std::vector<Token> tokens;
  std::string token;

  for (size_t i = 0; i < expression.size(); ++i) {
    char current_sym = expression[i];
    char next_sym = (i != expression.size() - 1) ? expression[i + 1] : '\0';

    if (isspace(current_sym)) {
      continue;
    }

    token += current_sym;

    if (current_sym == '-' || current_sym == '+') {
      if ((i == 0 || expression[i - 1] == '(') ||
          tokens.back().tokenType == TokenType::OPERATOR) {
        tokens.push_back(kTokenMap.at(kUnaryOperatorFlag + token));
        token.clear();
        continue;
      } else {
        tokens.push_back(kTokenMap.at(token));
        token.clear();
        continue;
      }
    } else if (token == "e" || token == "E") {
      tokens.push_back(kTokenMap.at("*"));
      tokens.push_back({TokenType::NUMBER, "10", -1});
      tokens.push_back(kTokenMap.at("^"));
      token.clear();
    } else if (isdigit(current_sym) || current_sym == '.') {
      if (!isdigit(next_sym) && next_sym != '.') {
        tokens.push_back({TokenType::NUMBER, token, -1});
        token.clear();
      }
    } else if (kTokenMap.count(token)) {
      tokens.push_back(kTokenMap.at(token));
      token.clear();
    }
  }

  if (!(token.empty())) {
    tokens.push_back({TokenType::UNKNOWN, token, -1});
  }

  return tokens;
}

void Calculator::checkTokensValidity(const std::vector<Token> &tokens) const {
  int brackets_counter = 0;
  int operator_counter = 0;
  Token previous_token({TokenType::UNKNOWN, "", -1});

  for (Token token : tokens) {
    if (token.tokenType == TokenType::NUMBER) {
      int count = std::count_if(token.content.begin(), token.content.end(),
                                [](char ch) { return ch == '.'; });
      if (count > 1) {
        throw std::invalid_argument("Unknown token");
      }
      std::stod(token.content);
    } else if (token.tokenType == TokenType::OPEN_BRACKET) {
      brackets_counter++;
    } else if (token.tokenType == TokenType::CLOSE_BRACKET) {
      brackets_counter--;
    } else if (token.tokenType == TokenType::UNKNOWN) {
      throw std::invalid_argument("Unknown token");
    } else if (token.tokenType == TokenType::OPERATOR) {
      if (previous_token.tokenType == TokenType::OPERATOR) {
        operator_counter++;
        if (operator_counter > 2) {
          throw std::invalid_argument("More than two operators in a row");
        }
      } else {
        operator_counter = 1;
      }
    }
    previous_token = token;
  }

  if (brackets_counter != 0) {
    throw std::invalid_argument("Error brackets");
  }
}

std::vector<Token> Calculator::convertTokensToPolishNotation(
    const std::vector<Token> &tokens) const {
  std::vector<Token> output;
  std::stack<Token> operatorStack;

  for (const Token &token : tokens) {
    if (token.tokenType == TokenType::NUMBER ||
        token.tokenType == TokenType::VARIABLE) {
      output.push_back(token);
    } else if (token.tokenType == TokenType::FUNCTION ||
               token.tokenType == TokenType::OPEN_BRACKET) {
      operatorStack.push(token);
    } else if (token.tokenType == TokenType::OPERATOR) {
      while (!operatorStack.empty() &&
             operatorStack.top().tokenType == TokenType::OPERATOR &&
             token.precedence <= operatorStack.top().precedence) {
        output.push_back(operatorStack.top());
        operatorStack.pop();
      }
      operatorStack.push(token);
    } else if (token.tokenType == TokenType::CLOSE_BRACKET) {
      while (!operatorStack.empty() &&
             operatorStack.top().tokenType != TokenType::OPEN_BRACKET) {
        output.push_back(operatorStack.top());
        operatorStack.pop();
      }
      if (!operatorStack.empty() &&
          operatorStack.top().tokenType == TokenType::OPEN_BRACKET) {
        operatorStack.pop();
        if (!operatorStack.empty() &&
            operatorStack.top().tokenType == TokenType::FUNCTION) {
          output.push_back(operatorStack.top());
          operatorStack.pop();
        }
      }
    }
  }

  while (!operatorStack.empty()) {
    output.push_back(operatorStack.top());
    operatorStack.pop();
  }

  return output;
}

double Calculator::execute(const std::string &oper, double first,
                           double second) const {
  if (oper == "+") {
    return second + first;
  } else if (oper == "-") {
    return second - first;
  } else if (oper == "*") {
    return second * first;
  } else if (oper == "/") {
    if (first == 0) {
      throw std::invalid_argument("Division by zero");
    }
    return second / first;
  } else if (oper == "^") {
    if (second < 0 && first != floor(first)) {
      throw std::invalid_argument(
          "Negative number raised to a non-integer power");
    }
    return powf(second, first);
  } else if (oper == "mod") {
    if (first == 0) {
      throw std::invalid_argument("Modulo division by zero");
    }
    return fmod(second, first);
  }
  throw std::invalid_argument("Invalid operator: " + oper);
}

double Calculator::execute(const std::string &func, double value) const {
  if (func == "sin") {
    return sin(value);
  } else if (func == "cos") {
    return cos(value);
  } else if (func == "tan") {
    return tan(value);
  } else if (func == "acos") {
    if (value < -1 || value > 1) {
      throw std::invalid_argument("Invalid input for acos");
    }
    return acos(value);
  } else if (func == "asin") {
    if (value < -1 || value > 1) {
      throw std::invalid_argument("Invalid input for asin");
    }
    return asin(value);
  } else if (func == "atan") {
    return atan(value);
  } else if (func == "sqrt") {
    if (value < 0) {
      throw std::invalid_argument("Square root of a negative number");
    }
    return sqrt(value);
  } else if (func == "ln") {
    if (value <= 0) {
      throw std::invalid_argument("Natural logarithm of a non-positive number");
    }
    return log(value);
  } else if (func == "log") {
    if (value <= 0) {
      throw std::invalid_argument("Logarithm of a non-positive number");
    }
    return log10(value);
  } else if (func == kUnaryOperatorFlag + "+") {
    return value;
  } else if (func == kUnaryOperatorFlag + "-") {
    return -value;
  }
  throw std::invalid_argument("Invalid function: " + func);
}

double Calculator::calculate(
    const std::string &expression,
    const std::unordered_map<std::string, double> &variable_values) const {
  if (expression.empty()) {
    return 0;
  }
  if (expression.length() > kMaxExpressionLength) {
    throw std::invalid_argument("expression length more than 255");
  }

  std::vector<Token> tokens = tokenizeExpression(expression);
  checkTokensValidity(tokens);

  std::vector<Token> polish = convertTokensToPolishNotation(tokens);
  std::stack<double> stack;

  for (auto token : polish) {
    if (token.tokenType == TokenType::VARIABLE) {
      stack.push(variable_values.at(token.content));
    } else if (token.tokenType == TokenType::NUMBER) {
      std::locale::global(std::locale("C"));
      stack.push(std::stod(token.content));
    } else if (token.tokenType == TokenType::OPERATOR) {
      double first, second, res;

      if (token.content[0] == kUnaryOperatorFlag[0]) {
        if (stack.size() < 1) {
          throw std::invalid_argument("Not enough operands for unary operator");
        }

        first = stack.top();
        stack.pop();

        res = execute(token.content, first);
        stack.push(res);
      } else {
        if (stack.size() < 2) {
          throw std::invalid_argument(
              "Not enough operands for binary operator");
        }

        first = stack.top();
        stack.pop();
        second = stack.top();
        stack.pop();

        res = execute(token.content, first, second);
        stack.push(res);
      }
    } else if (token.tokenType == TokenType::FUNCTION) {
      if (stack.empty()) {
        throw std::invalid_argument("Not enough operands for function");
      }

      double value = stack.top();
      double res = execute(token.content, value);
      stack.pop();
      stack.push(res);
    }
  }

  if (stack.size() != 1) {
    throw std::invalid_argument("Invalid expression: unexpected stack size");
  }

  return stack.top();
}

double Calculator::calculate(const std::string &expression) const {
  return calculate(expression, std::unordered_map<std::string, double>());
}

}  // namespace s21