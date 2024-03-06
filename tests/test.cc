#include <gtest/gtest.h>

#include <cmath>

#include "model/calculator.h"
#include "model/credit.h"

s21::Calculator calculator;
const double kEpsilon = 1e-6;

TEST(MathCalculator, OperatorPlus) {
  ASSERT_EQ(2 + 3, calculator.calculate("2 + 3"));
  ASSERT_EQ(5 + (-3), calculator.calculate("5 + (-3)"));
  ASSERT_EQ(0.5 + 0.25, calculator.calculate("0.5 + 0.25"));
  ASSERT_EQ(-1.5 + 2.5, calculator.calculate("-1.5 + 2.5"));
}

TEST(MathCalculator, OperatorMinus) {
  ASSERT_EQ(5 - 3, calculator.calculate("5 - 3"));
  ASSERT_EQ(2.5 - (-1.5), calculator.calculate("2.5 - (-1.5)"));
}

TEST(MathCalculator, OperatorMultiply) {
  ASSERT_EQ(2 * 3, calculator.calculate("2 * 3"));
  ASSERT_EQ(4.5 * (-2), calculator.calculate("4.5 * (-2)"));
}

TEST(MathCalculator, OperatorDivide) {
  ASSERT_EQ(6 / 2, calculator.calculate("6 / 2"));
  ASSERT_EQ(8.0 / (-4.0), calculator.calculate("8.0 / (-4.0)"));
}

TEST(MathCalculator, OperatorPower) {
  ASSERT_EQ(pow(2, 3), calculator.calculate("2 ^ 3"));
  ASSERT_EQ(pow(4.5, 2), calculator.calculate("4.5 ^ 2"));
}

TEST(MathCalculator, OperatorMod) {
  ASSERT_EQ(7 % 3, calculator.calculate("7 mod 3"));
  ASSERT_EQ(fmod(10, 2.5), calculator.calculate("10 mod 2.5"));
}

TEST(MathCalculator, OperatorUnaryPlus) {
  ASSERT_EQ(+3, calculator.calculate("+3"));
  ASSERT_EQ(+2.5, calculator.calculate("+2.5"));
}

TEST(MathCalculator, OperatorUnaryMinus) {
  ASSERT_EQ(-3, calculator.calculate("-3"));
  ASSERT_EQ(-2.5, calculator.calculate("-2.5"));
}

TEST(MathCalculator, Cosine) {
  ASSERT_DOUBLE_EQ(cos(0.0), calculator.calculate("cos(0)"));
  ASSERT_DOUBLE_EQ(cos(1.0), calculator.calculate("cos(1)"));
}

TEST(MathCalculator, Sine) {
  ASSERT_DOUBLE_EQ(sin(0.0), calculator.calculate("sin(0)"));
  ASSERT_DOUBLE_EQ(sin(1.0), calculator.calculate("sin(1)"));
}

TEST(MathCalculator, Tangent) {
  ASSERT_DOUBLE_EQ(tan(0.0), calculator.calculate("tan(0)"));
  ASSERT_DOUBLE_EQ(tan(1.0), calculator.calculate("tan(1)"));
}

TEST(MathCalculator, Arccosine) {
  ASSERT_DOUBLE_EQ(acos(1.0), calculator.calculate("acos(1)"));
  ASSERT_DOUBLE_EQ(acos(0.5), calculator.calculate("acos(0.5)"));
}

TEST(MathCalculator, Arcsine) {
  ASSERT_DOUBLE_EQ(asin(0.0), calculator.calculate("asin(0)"));
  ASSERT_DOUBLE_EQ(asin(0.5), calculator.calculate("asin(0.5)"));
}

TEST(MathCalculator, Arctangent) {
  ASSERT_DOUBLE_EQ(atan(0.0), calculator.calculate("atan(0)"));
  ASSERT_DOUBLE_EQ(atan(1.0), calculator.calculate("atan(1)"));
}

TEST(MathCalculator, SquareRoot) {
  ASSERT_DOUBLE_EQ(sqrt(9.0), calculator.calculate("sqrt(9)"));
  ASSERT_DOUBLE_EQ(sqrt(2.0), calculator.calculate("sqrt(2)"));
}

TEST(MathCalculator, NaturalLogarithm) {
  ASSERT_DOUBLE_EQ(log(1.0), calculator.calculate("ln(1)"));
  ASSERT_DOUBLE_EQ(log(2.0), calculator.calculate("ln(2)"));
}

TEST(MathCalculator, DecimalLogarithm) {
  ASSERT_DOUBLE_EQ(log10(1.0), calculator.calculate("log(1)"));
  ASSERT_DOUBLE_EQ(log10(10.0), calculator.calculate("log(10)"));
}

TEST(MathCalculator, ExpressionsWithParentheses) {
  ASSERT_EQ((2 + 3) * 4, calculator.calculate("(2 + 3) * 4"));
  ASSERT_EQ(2 * (3 + 4), calculator.calculate("2 * (3 + 4)"));
  ASSERT_EQ((1 + 2) * (3 + 4), calculator.calculate("(1 + 2) * (3 + 4)"));
}

TEST(MathCalculator, ComplexExpressions) {
  ASSERT_EQ(-((2 + 3) * 4 / 2), calculator.calculate("-((2 + 3) * 4 / 2)"));
  ASSERT_EQ(sin(1.0) + cos(2.0) * 2.0 - sqrt(4.0),
            calculator.calculate("sin(1) + cos(2) * 2 - sqrt(4)"));
  ASSERT_EQ(10 * (3 + 2) - (4 / 2) + 1,
            calculator.calculate("10 * (3 + 2) - (4 / 2) + 1"));
}

TEST(MathCalculator, ScientificNotation) {
  ASSERT_EQ(2.5e3, calculator.calculate("2.5e3"));
  ASSERT_NEAR(1.23E-4, calculator.calculate("1.23E-4"), kEpsilon);
  ASSERT_NEAR(2.0 * 1.5e2 - (3.0 + 1.0E-3),
              calculator.calculate("2.0 * 1.5e2 - (3.0 + 1.0E-3)"), kEpsilon);
}

TEST(MathCalculator, InvalidExpressions) {
  ASSERT_THROW(calculator.calculate("(2 + 3"), std::invalid_argument);
  ASSERT_THROW(calculator.calculate("2 + 3)"), std::invalid_argument);
  ASSERT_THROW(calculator.calculate("sin()"), std::invalid_argument);
  ASSERT_THROW(calculator.calculate("()"), std::invalid_argument);
  ASSERT_THROW(calculator.calculate("() + ()"), std::invalid_argument);
  ASSERT_THROW(calculator.calculate("sin"), std::invalid_argument);
  ASSERT_THROW(calculator.calculate("1 / 0"), std::invalid_argument);
}

TEST(CreditCalculator, AnnuityPayment) {
  s21::Credit credit(100000, 12, 5, s21::Credit::RepaymentType::Annuity);

  ASSERT_NEAR(8560, credit.calculateAnnuityMonthlyPayment(), 1);
  ASSERT_NEAR(2729, credit.calculateOverpayment(), 1);
  ASSERT_NEAR(102729, credit.calculateTotalPayment(), 1);
}

TEST(CreditCalculator, Differentiated) {
  s21::Credit credit(100000, 12, 5, s21::Credit::RepaymentType::Differentiated);
  auto payments = credit.calculateDifferentiatedPayments();

  ASSERT_NEAR(8750, payments.at(0), 1);
  ASSERT_NEAR(8368, payments.at(payments.size() - 1), 1);
  ASSERT_NEAR(2708, credit.calculateOverpayment(), 1);
  ASSERT_NEAR(102708, credit.calculateTotalPayment(), 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
