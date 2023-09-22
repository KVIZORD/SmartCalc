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
      "№", "Сумма платежа", "Платеж по основному долгу", "Платеж по процентам",
      "Остаток долга"};

  explicit CreditCalculator(QWidget *parent = nullptr);
  double getAmount();
  double getTerm();
  double getRate();
  std::string getRepaymentType();
  QPushButton *getCalculateButton();
  ~CreditCalculator();
  void updatePaymentDetailTable();
  void addToTable(int row, int column, QString value);
  void setOverpayment(QString overpayment);
  void setTotalPayment(QString total_payment);

 private:
  void addTableData();
  Ui::CreditCalculator *ui_;
  std::unique_ptr<QStandardItemModel> model_;
};

}  // namespace s21

#endif  // __SMARTCALC_V2_0_SRC_VIEW_CREDIT_CALCULATOR_H__
