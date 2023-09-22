#ifndef __SMARTCALC_V2_0_SRC_MODEL_CALCULATOR_H__
#define __SMARTCALC_V2_0_SRC_MODEL_CALCULATOR_H__

#include <string>
#include <unordered_map>
#include <vector>

namespace s21 {

class Calculator {
 public:
  const std::size_t kMaxExpressionLength = 255;
  const std::string kUnaryOperatorFlag = "U";

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
    TokenType tokenType;
    std::string content;
    int precedence;

    Token(TokenType t, const std::string &v, int p)
        : tokenType(t), content(v), precedence(p) {}
  };

  const std::unordered_map<std::string, Token> kTokenMap = {
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
      {"log", {TokenType::FUNCTION, "log", 3}},
      {kUnaryOperatorFlag + "-",
       {TokenType::OPERATOR, kUnaryOperatorFlag + "-", 4}},
      {kUnaryOperatorFlag + "+",
       {TokenType::OPERATOR, kUnaryOperatorFlag + "+", 4}},
  };

 public:
  double calculate(
      const std::string &expression,
      const std::unordered_map<std::string, double> &variable_values);

 private:
  std::vector<Token> tokenizeExpression(const std::string &expression);
  void checkTokensValidity(const std::vector<Token> &tokens);
  std::vector<Token> convertTokensToPolishNotation(
      const std::vector<Token> &tokens);
  double execute(const std::string &oper, double first, double second);
  double execute(const std::string &func, double value);
};

}  // namespace s21
#endif  // __SMARTCALC_V2_0_SRC_MODEL_CALCULATOR_H__
