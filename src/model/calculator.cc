#include "calculator.h"

#include <algorithm>
#include <cmath>
#include <iostream>
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

    if ((current_sym == '-' || current_sym == '+') &&
        (i == 0 || expression[i - 1] == '(')) {  // unary operators
      tokens.push_back({TokenType::NUMBER, "0", -1});
      tokens.push_back(kTokens.at(token));
      token.clear();
      continue;
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

  for (auto i : tokens) {
    std::cout << i.value << std::endl;
  }

  return tokens;
}

void Calculator::CheckTokensValidity(const std::vector<Token> &tokens) {
  int brackets_counter = 0;
  TokenType prev_type;

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
    } else if (prev_type == TokenType::OPERATOR && token.type == TokenType::OPERATOR){
			// throw std::invalid_argument("Two operators in a row");
		}

    prev_type = token.type;
  }

  if (brackets_counter != 0) {
    throw std::invalid_argument("Error brackets");
  }
}

std::vector<Token> Calculator::ConvertTokensToPolishNotation(
    const std::vector<Token> &tokens) {
  std::vector<Token> polish_notation;
  std::stack<Token> stack_tokens;

  for (const Token &token : tokens) {
    if (token.type == TokenType::NUMBER) {
      polish_notation.push_back(token);
    } else if (token.type == TokenType::OPEN_BRACKET ||
               token.type == TokenType::FUNCTION) {
      stack_tokens.push(token);
    } else if (token.type == TokenType::OPERATOR) {
      while (!stack_tokens.empty() &&
             stack_tokens.top().type == TokenType::OPERATOR &&
             stack_tokens.top().priority >= token.priority) {
        polish_notation.push_back(stack_tokens.top());
        stack_tokens.pop();
      }
      stack_tokens.push(token);
    } else if (token.type == TokenType::CLOSE_BRACKET) {
      while (!stack_tokens.empty() &&
             stack_tokens.top().type != TokenType::OPEN_BRACKET) {
        polish_notation.push_back(stack_tokens.top());
        stack_tokens.pop();
      }
      if (!stack_tokens.empty()) {
        stack_tokens.pop();
      }
      if (!stack_tokens.empty() &&
          stack_tokens.top().type == TokenType::FUNCTION) {
        polish_notation.push_back(stack_tokens.top());
        stack_tokens.pop();
      }
    }
  }

  while (!stack_tokens.empty()) {
    polish_notation.push_back(stack_tokens.top());
    stack_tokens.pop();
  }
  return polish_notation;
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
      stack.push(std::stod(token.value));
    } else if (token.type == TokenType::OPERATOR) {
      double first = stack.top();
      stack.pop();
      double second = stack.top();
      stack.pop();

      double res = Execute(token.value, first, second);
      stack.push(res);
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

int main() {
  using namespace std;
  using namespace s21;

  Calculator a;
  try {
    std::cout << a.Calculate("5e+10");
  } catch (const std::invalid_argument e) {
    std::cout << "error";
  }

  return 0;
}
