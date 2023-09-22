#include "calculator.h"

#include <algorithm>
#include <cmath>
#include <locale>
#include <stack>

namespace s21 {

using Token = Calculator::Token;
using TokenType = Calculator::TokenType;

std::vector<Token> Calculator::tokenizeExpression(
    const std::string &expression) {
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

void Calculator::checkTokensValidity(const std::vector<Token> &tokens) {
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
    const std::vector<Token> &tokens) {
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
                           double second) {
  if (oper == "+") {
    return second + first;
  } else if (oper == "-") {
    return second - first;
  } else if (oper == "*") {
    return second * first;
  } else if (oper == "/") {
    return second / first;
  } else if (oper == "^") {
    return powf(second, first);
  } else if (oper == "mod") {
    return fmod(second, first);
  }
  return 0;
}

double Calculator::execute(const std::string &func, double value) {
  if (func == "sin") {
    return sin(value);
  } else if (func == "cos") {
    return cos(value);
  } else if (func == "tan") {
    return tan(value);
  } else if (func == "acos") {
    return acos(value);
  } else if (func == "asin") {
    return asin(value);
  } else if (func == "atan") {
    return atan(value);
  } else if (func == "sqrt") {
    return sqrt(value);
  } else if (func == "ln") {
    return log(value);
  } else if (func == "log") {
    return log10(value);
  } else if (func == kUnaryOperatorFlag + "+") {
    return value;
  } else if (func == kUnaryOperatorFlag + "-") {
    return -value;
  }
  return 0;
}

double Calculator::calculate(
    const std::string &expression,
    const std::unordered_map<std::string, double> &variable_values) {
  if (expression.empty()) {
    return 0;
  }
  if (expression.length() > kMaxExpressionLength) {
    throw std::invalid_argument("expression length more then 255");
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
        first = stack.top();
        stack.pop();

        res = execute(token.content, first);
        stack.push(res);
      } else {
        first = stack.top();
        stack.pop();
        second = stack.top();
        stack.pop();

        res = execute(token.content, first, second);
        stack.push(res);
      }
    } else if (token.tokenType == TokenType::FUNCTION) {
      double value = stack.top();
      double res = execute(token.content, value);
      stack.pop();
      stack.push(res);
    }
  }

  return stack.top();
}

}  // namespace s21

// int main() {
//   using namespace std;
//   using namespace s21;

//   std::unordered_map<std::string, double> values = {{"x", 5}};

//   Calculator a;
//   try {
//     std::cout << a.Calculate("5 3", values);
//   } catch (const std::invalid_argument e) {
//     std::cout << "error" << e.what();
//   }

//   return 0;
// }
