#ifndef __SMARTCALC_V2_0_SRC_MODEL_CALCULATOR_H__
#define __SMARTCALC_V2_0_SRC_MODEL_CALCULATOR_H__

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
      {"e", {TokenType::OPERATOR, "e", 1}},
      {"E", {TokenType::OPERATOR, "E", 1}},
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

  const std::size_t kMaxExpressionLength = 255;

 public:
  double Calculate(const std::string expression);

 private:
  std::vector<Token> TokenizeExpression(const std::string &expression);
  void CheckTokensValidity(const std::vector<Token> &tokens);
  std::vector<Token> ConvertTokensToPolishNotation(
      const std::vector<Token> &tokens);
  double Execute(std::string oper, double first, double second);
  double Execute(std::string func, double value);
};

}  // namespace s21
#endif  // __SMARTCALC_V2_0_SRC_MODEL_CALCULATOR_H__
