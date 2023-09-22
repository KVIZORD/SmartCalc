#ifndef __SMARTCALC_V2_0_SRC_VIEW_CREDIT_CALCULATOR_H__
#define __SMARTCALC_V2_0_SRC_VIEW_CREDIT_CALCULATOR_H__

#include <QPushButton>
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class CreditCalculator;
}

namespace s21 {

class CreditCalculator : public QWidget {
  Q_OBJECT

 public:
  const std::list<std::string> kTitlesTable = {
      "№", "Ежемесячный платеж", "Платеж по основному долгу",
      "Платеж по процентам", "Остаток долга"};

 public:
  explicit CreditCalculator(QWidget *parent = nullptr);
  ~CreditCalculator();

  double getAmount();
  double getTerm();
  double getRate();
  std::string getRepaymentType();
  QPushButton *getCalculateButton();

  void setOverpayment(const QString &overpayment);
  void setTotalPayment(const QString &total_payment);

  void updatePaymentTable();
  void addToTable(int row, int column, const QString &value);

 private:
  void initializeTable();

 private:
  Ui::CreditCalculator *ui_;
  std::unique_ptr<QStandardItemModel> model_;
};

}  // namespace s21

#endif  // __SMARTCALC_V2_0_SRC_VIEW_CREDIT_CALCULATOR_H__
