#ifndef __SMARTCALC_V2_0_SRC_MODEL_PARSES_H__
#define __SMARTCALC_V2_0_SRC_MODEL_PARSES_H__

#include <string>
#include <unordered_map>
#include <vector>

namespace s21 {

class Calculator {
public:
  enum class TokenType {
    NUMBER,
    VARIABLE,
    FUNCTION,
    OPERATOR,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    UNKNOWN
  };

  struct Token {
    TokenType type;
    std::string value;
    int priority;

    Token(TokenType t, const std::string &v, int p)
        : type(t), value(v), priority(p) {}
  };

  const std::unordered_map<std::string, Token> kTokens = {
      {"x", {TokenType::VARIABLE, "x", -1}},
      {"X", {TokenType::VARIABLE, "X", -1}},
      {"(", {TokenType::OPEN_BRACKET, "(", -1}},
      {")", {TokenType::CLOSE_BRACKET, ")", -1}},
      {"+", {TokenType::OPERATOR, "+", 1}},
      {"-", {TokenType::OPERATOR, "-", 1}},
      {"*", {TokenType::OPERATOR, "*", 2}},
      {"/", {TokenType::OPERATOR, "/", 2}},
      {"mod", {TokenType::OPERATOR, "mod", 2}},
      {"^", {TokenType::OPERATOR, "^", 3}},
      {"sin", {TokenType::FUNCTION, "sin", 3}},
      {"cos", {TokenType::FUNCTION, "cos", 3}},
      {"tan", {TokenType::FUNCTION, "tan", 3}},
      {"acos", {TokenType::FUNCTION, "acos", 3}},
      {"asin", {TokenType::FUNCTION, "asin", 3}},
      {"atan", {TokenType::FUNCTION, "atan", 3}},
      {"sqrt", {TokenType::FUNCTION, "sqrt", 3}},
      {"ln", {TokenType::FUNCTION, "ln", 3}},
      {"log", {TokenType::FUNCTION, "log", 3}}};

  std::vector<Token> TokenizeExpression(const std::string &expression);
  double CalculateExpression(const std::vector<Token> &tokens);

private:
  void CheckTokensValidity(const std::vector<Token> &tokens);
};

} // namespace s21
#endif // __SMARTCALC_V2_0_SRC_MODEL_PARSES_H__
