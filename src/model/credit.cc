#include "credit.h"

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
