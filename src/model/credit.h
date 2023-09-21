#ifndef __SMARTCALC_V2_0_SRC_MODEL_CREDIT_H__
#define __SMARTCALC_V2_0_SRC_MODEL_CREDIT_H__

#include <cmath>
#include <vector>

class Credit {
 public:
  enum class RepaymentType { Annuity, Differentiated };

  Credit(double amount, int term, double rate, RepaymentType type);
  double calculateAnnuityMonthlyPayment() const;
  std::vector<double> calculateDifferentiatedPayments() const;
  double calculateOverpayment() const;
  double calculateTotalPayment() const;

 private:
  void calculatePayments();

  double loan_amount_;
  int loan_term_months_;
  double annual_interest_rate;
  RepaymentType repayment_type;
  std::vector<double> payments;
};

#endif  // __SMARTCALC_V2_0_SRC_MODEL_CREDIT_H__
