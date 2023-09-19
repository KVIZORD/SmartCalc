#include "calculator.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <locale>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

namespace s21 {

using Token = Calculator::Token;
using TokenType = Calculator::TokenType;

std::vector<Token> Calculator::TokenizeExpression(
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
          tokens.back().type == TokenType::OPERATOR) {
        tokens.push_back(kTokens.at(kUnaryOperatorFlag + token));
        token.clear();
        continue;
      } else {
        tokens.push_back(kTokens.at(token));
        token.clear();
        continue;
      }
    } else if (token == "e" || token == "E") {  // science notation
      tokens.push_back(kTokens.at("*"));
      tokens.push_back({TokenType::NUMBER, "10", -1});
      tokens.push_back(kTokens.at("^"));
      token.clear();
    } else if (isdigit(current_sym) || current_sym == '.') {
      if (!isdigit(next_sym) && next_sym != '.') {
        tokens.push_back({TokenType::NUMBER, token, -1});
        token.clear();
      }
    } else if (kTokens.count(token)) {
      tokens.push_back(kTokens.at(token));
      token.clear();
    }
  }

  if (!(token.empty())) {
    tokens.push_back({TokenType::UNKNOWN, token, -1});
  }

  // for (auto i : tokens) {
  //   std::cout << i.value << std::endl;
  // }
  // std::cout << std::endl;

  return tokens;
}

void Calculator::CheckTokensValidity(const std::vector<Token> &tokens) {
  int brackets_counter = 0;
  int operator_counter = 0;
  Token previous_token({TokenType::UNKNOWN, "", -1});

  for (Token token : tokens) {
    if (token.type == TokenType::NUMBER) {
      int count = std::count_if(token.value.begin(), token.value.end(),
                                [](char ch) { return ch == '.'; });
      if (count > 1) {
        throw std::invalid_argument("Unknown token");
      }
      std::stod(token.value);
    } else if (token.type == TokenType::OPEN_BRACKET) {
      brackets_counter++;
    } else if (token.type == TokenType::CLOSE_BRACKET) {
      brackets_counter--;
    } else if (token.type == TokenType::UNKNOWN) {
      throw std::invalid_argument("Unknown token");
    } else if (token.type == TokenType::OPERATOR) {
      if (previous_token.type == TokenType::OPERATOR) {
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

std::vector<Token> Calculator::ConvertTokensToPolishNotation(
    const std::vector<Token> &tokens) {
  std::vector<Token> output;
  std::stack<Token> operatorStack;

  for (const Token &token : tokens) {
    if (token.type == TokenType::NUMBER) {
      output.push_back(token);
    } else if (token.type == TokenType::OPERATOR) {
      while (!operatorStack.empty() &&
             operatorStack.top().type == TokenType::OPERATOR &&
             operatorStack.top().priority >= token.priority) {
        output.push_back(operatorStack.top());
        operatorStack.pop();
      }
      operatorStack.push(token);
    } else if (token.type == TokenType::OPEN_BRACKET) {
      operatorStack.push(token);
    } else if (token.type == TokenType::CLOSE_BRACKET) {
      while (!operatorStack.empty() &&
             operatorStack.top().type != TokenType::OPEN_BRACKET) {
        output.push_back(operatorStack.top());
        operatorStack.pop();
      }
      if (!operatorStack.empty() &&
          operatorStack.top().type == TokenType::OPEN_BRACKET) {
        operatorStack.pop();
      }
    }
  }

  while (!operatorStack.empty()) {
    output.push_back(operatorStack.top());
    operatorStack.pop();
  }

  // for (auto i : output) {
  //   std::cout << i.value << std::endl;
  // }
  // std::cout << std::endl;

  return output;
}

double Calculator::Execute(std::string oper, double first, double second) {
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

double Calculator::Execute(std::string func, double value) {
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

double Calculator::Calculate(const std::string expression) {
  if (expression.empty()) {
    return 0;
  }
  if (expression.length() > kMaxExpressionLength) {
    throw std::invalid_argument("expression length more then 255");
  }

  std::vector<Token> tokens = TokenizeExpression(expression);
  CheckTokensValidity(tokens);

  std::vector<Token> polish = ConvertTokensToPolishNotation(tokens);
  std::stack<double> stack;

  for (auto token : polish) {
    if (token.type == TokenType::NUMBER) {
      std::locale::global(std::locale("C"));

      stack.push(std::stod(token.value));
    } else if (token.type == TokenType::OPERATOR) {
      double first, second, res;

      if (token.value[0] == kUnaryOperatorFlag[0]) {
        first = stack.top();
        stack.pop();

        res = Execute(token.value, first);
        stack.push(res);
      } else {
        first = stack.top();
        stack.pop();
        second = stack.top();
        stack.pop();

        res = Execute(token.value, first, second);
        stack.push(res);
      }
    } else if (token.type == TokenType::FUNCTION) {
      double value = stack.top();
      double res = Execute(token.value, value);
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

//   Calculator a;
//   try {
//     std::cout << a.Calculate("");
//   } catch (const std::invalid_argument e) {
//     std::cout << "error" << e.what();
//   }

//   return 0;
// }
