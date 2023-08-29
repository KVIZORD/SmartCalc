#include "parser.h"
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
        if (kTokens.count(token)) {
          tokens.push_back(kTokens.at(token));
        } else if (kTokens.count(token)) {
          tokens.push_back(kTokens.at(token));
        } else {
          tokens.push_back(kTokens.at(token));
        }
        token.clear();
      }
    } else if (ispunct(current_sym)) {
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

double Calculator::CalculateExpression(const std::vector<Token> &tokens) {
  std::string out;
  std::stack<Token> stc;

  for (const Token &token : tokens) {
    if (token.type == TokenType::NUMBER) {
      out += token.value;
    } else if (token.type == TokenType::FUNCTION ||
               token.type == TokenType::OPEN_BRACKET) {
      stc.push(token);
    } else if (token.type == TokenType::OPERATOR) {
      while (!stc.empty() && stc.top().type == TokenType::OPERATOR &&
             stc.top().priority > token.priority) {
        out += stc.top().value;
        stc.pop();
      }
      stc.push(token);
    } else if (token.type == TokenType::CLOSE_BRACKET) {
      while (!stc.empty() && stc.top().type != TokenType::OPEN_BRACKET) {
        out += stc.top().value;
        stc.pop();
      }
      if (!stc.empty() && stc.top().type == TokenType::FUNCTION) {
        out += stc.top().value;
        stc.pop();
      }
      if (!stc.empty() && stc.top().type == TokenType::OPEN_BRACKET) {
        stc.pop();
      }
    }
  }

  while (!stc.empty()) {
    out += stc.top().value;
    stc.pop();
  }

  std::cout << out;
  return 0;
}

} // namespace s21

int main() {
  using namespace std;
  using namespace s21;

  Calculator a;
  auto temp = a.TokenizeExpression("2 + 3 - sin(x) * 432 + e3");
  for (auto i : temp) {
    cout << i.value << endl;
  }

  a.CalculateExpression(temp);

  return 0;
}
