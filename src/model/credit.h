#ifndef __SMARTCALC_V2_0_SRC_MODEL_CREDIT_H__
#define __SMARTCALC_V2_0_SRC_MODEL_CREDIT_H__

#include <vector>

namespace s21 {

class Credit {
 public:
  enum class RepaymentType { Annuity, Differentiated };

  struct PaymentDetail {
    int number;
    double total_payment;
    double principal_payment;
    double interest_payment;
    double remaining_balance;
  };

  Credit(double amount, int term, double rate, RepaymentType type);
  double calculateAnnuityMonthlyPayment() const;
  std::vector<double> calculateDifferentiatedPayments() const;
  double calculateOverpayment() const;
  double calculateTotalPayment() const;
  std::vector<PaymentDetail> calculatePaymentDetails()
      const;  // Новый метод для детализированных платежей

 private:
  void calculatePayments();

  double loan_amount_;
  int loan_term_months_;
  double annual_interest_rate;
  RepaymentType repayment_type;
  std::vector<double> payments;
};

}  // namespace s21

#endif  // __SMARTCALC_V2_0_SRC_MODEL_CREDIT_H__