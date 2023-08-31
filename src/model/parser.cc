#include "parser.h"
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

namespace s21 {

using Token = Calculator::Token;
using TokenType = Calculator::TokenType;

std::vector<Token>
Calculator::TokenizeExpression(const std::string &expression) {
  std::vector<Token> tokens;
  std::string token;

  for (size_t i = 0; i < expression.size(); ++i) {
    char current_sym = expression[i];
    char next_sym = (i != expression.size() - 1) ? expression[i + 1] : '\0';
    char prev_sym = (i != 0) ? expression[i - 1] : '\0';

    if (isspace(current_sym)) {
      continue;
    }

    token += current_sym;

    if (isdigit(current_sym) || current_sym == '.') {
      if (i == expression.size() - 1 ||
          (!isdigit(next_sym) && next_sym != '.')) {
        tokens.push_back({TokenType::NUMBER, token, -1});
        token.clear();
      }
    } else if (isalpha(current_sym)) {
      if (i == expression.size() - 1 || !isalpha(next_sym)) {
        if (token == "e" || token == "E") {
          tokens.push_back(kTokens.at("*"));
          tokens.push_back({TokenType::NUMBER, "10", -1});
          tokens.push_back(kTokens.at("^"));
          token.clear();
        } else if (kTokens.count(token)) {
          tokens.push_back(kTokens.at(token));
        } else if (kTokens.count(token)) {
          tokens.push_back(kTokens.at(token));
        } else {
          tokens.push_back(kTokens.at(token));
        }
        token.clear();
      }
    } else if (ispunct(current_sym)) {
      if (current_sym == '-' || current_sym == '+') {
        if (i == 0 || prev_sym == '(') {
          tokens.push_back({TokenType::NUMBER, "0", -1});
          tokens.push_back(kTokens.at(token));
          token.clear();
          continue;
        }
      }
      if (kTokens.count(token)) {
        tokens.push_back(kTokens.at(token));
      } else {
        tokens.push_back({TokenType::UNKNOWN, token, -1});
      }
      token.clear();
    } else {
      tokens.push_back({TokenType::UNKNOWN, token, -1});
      token.clear();
    }
  }

  return tokens;
}

std::vector<Token>
Calculator::ConvertTokensToPolishNotation(const std::vector<Token> &tokens) {
  std::vector<Token> polish_notation;
  std::stack<Token> stack_tokens;

  for (const Token &token : tokens) {
    if (token.type == TokenType::NUMBER || token.type == TokenType::FUNCTION) {
      polish_notation.push_back(token);
    } else if (token.type == TokenType::OPEN_BRACKET) {
      stack_tokens.push(token);
    } else if (token.type == TokenType::OPERATOR) {
      while (!stack_tokens.empty() &&
             stack_tokens.top().type == TokenType::OPERATOR &&
             stack_tokens.top().priority > token.priority) {
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
      if (!stack_tokens.empty() &&
          stack_tokens.top().type == TokenType::OPEN_BRACKET) {
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
  }
  return 0;
}

double Calculator::Calculate(const std::string expression) {
  std::vector<Token> tokens = TokenizeExpression(expression);
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
  std::cout << stack.top() << std::endl;
  return stack.top();
}

} // namespace s21

int main() {
  using namespace std;
  using namespace s21;

  Calculator a;
  a.Calculate("2-2-5");

  return 0;
}
