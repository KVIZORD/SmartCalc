#include "credit.h"

#include <cmath>

namespace s21 {

Credit::Credit(double amount, int term, double rate, RepaymentType type) {
  loan_amount_ = amount;
  loan_term_months_ = term;
  annual_interest_rate = rate / 100.0;
  repayment_type = type;

  calculatePayments();
}

double Credit::calculateAnnuityMonthlyPayment() const {
  if (repayment_type == RepaymentType::Annuity) {
    return payments[0];
  } else {
    return 0.0;
  }
}

std::vector<double> Credit::calculateDifferentiatedPayments() const {
  if (repayment_type == RepaymentType::Differentiated) {
    return payments;
  } else {
    return {};
  }
}

double Credit::calculateOverpayment() const {
  return calculateTotalPayment() - loan_amount_;
}

double Credit::calculateTotalPayment() const {
  double total_payment = 0.0;
  for (double payment : payments) {
    total_payment += payment;
  }
  return total_payment;
}

void Credit::calculatePayments() {
  if (repayment_type == RepaymentType::Annuity) {
    double monthly_rate = annual_interest_rate / 12.0;
    double monthly_payment =
        loan_amount_ *
        (monthly_rate * pow(1 + monthly_rate, loan_term_months_)) /
        (pow(1 + monthly_rate, loan_term_months_) - 1);
    payments.assign(loan_term_months_, monthly_payment);
  } else if (repayment_type == RepaymentType::Differentiated) {
    double monthly_interest_rate = annual_interest_rate / 12.0;
    payments.resize(loan_term_months_);

    for (int i = 0; i < loan_term_months_; ++i) {
      double monthly_payment =
          loan_amount_ / loan_term_months_ +
          (loan_amount_ - i * (loan_amount_ / loan_term_months_)) *
              monthly_interest_rate;
      payments[i] = monthly_payment;
    }
  }
}

std::vector<Credit::PaymentDetail> Credit::calculatePaymentDetails() const {
  std::vector<PaymentDetail> payment_details;

  if (repayment_type == RepaymentType::Annuity) {
    double monthly_rate = annual_interest_rate / 12.0;
    double remaining_balance = loan_amount_;

    for (int i = 0; i < loan_term_months_; ++i) {
      double interest_payment = remaining_balance * monthly_rate;
      double principal_payment = payments[0] - interest_payment;
      remaining_balance -= principal_payment;
      if (remaining_balance < 0) remaining_balance = 0;

      PaymentDetail detail;
      detail.number = i + 1;
      detail.total_payment = payments[0];
      detail.principal_payment = principal_payment;
      detail.interest_payment = interest_payment;
      detail.remaining_balance = remaining_balance;

      payment_details.push_back(detail);
    }
  } else if (repayment_type == RepaymentType::Differentiated) {
    double monthly_interest_rate = annual_interest_rate / 12.0;
    double remaining_balance = loan_amount_;

    for (int i = 0; i < loan_term_months_; ++i) {
      double principal_payment = loan_amount_ / loan_term_months_;
      double interest_payment = remaining_balance * monthly_interest_rate;
      remaining_balance -= principal_payment;
      if (remaining_balance < 0) remaining_balance = 0;

      PaymentDetail detail;
      detail.number = i + 1;
      detail.total_payment = principal_payment + interest_payment;
      detail.principal_payment = principal_payment;
      detail.interest_payment = interest_payment;
      detail.remaining_balance = remaining_balance;

      payment_details.push_back(detail);
    }
  }

  return payment_details;
}
}  // namespace s21
