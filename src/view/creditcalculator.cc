#include "view/creditcalculator.h"

#include <QTableView>

#include "ui_creditcalculator.h"

namespace s21 {

CreditCalculator::CreditCalculator(QWidget* parent)
    : QWidget(parent), ui_(new Ui::CreditCalculator) {
  ui_->setupUi(this);

  connect(ui_->calcucateButton, &QPushButton::clicked, this,
          &CreditCalculator::initializeTable);
}

CreditCalculator::~CreditCalculator() { delete ui_; }

double CreditCalculator::getAmount() { return ui_->amountdoubleSpin->value(); }
double CreditCalculator::getTerm() { return ui_->termSpinBox->value(); }
double CreditCalculator::getRate() { return ui_->rateSpinBox->value(); }

std::string CreditCalculator::getRepaymentType() {
  if (ui_->annuityRadio->isChecked()) {
    return kAnnuityPaymentType;
  } else {
    return kDifferentiatedPaymentType;
  }
}

void CreditCalculator::initializeTable() {
  model_ = std::make_unique<QStandardItemModel>();

  ui_->paymentDetailTable->horizontalHeader()->setSectionResizeMode(
      QHeaderView::ResizeToContents);
  ui_->paymentDetailTable->horizontalHeader()->setMinimumSectionSize(0);

  QStringList horizontal_headers;
  for (const std::string& title : kTitlesTable) {
    horizontal_headers << QString::fromStdString(title);
  }

  model_->setHorizontalHeaderLabels(horizontal_headers);

  updatePaymentTable();
}

QPushButton* CreditCalculator::getCalculateButton() {
  return ui_->calcucateButton;
}

void CreditCalculator::updatePaymentTable() {
  ui_->paymentDetailTable->setModel(model_.get());
}

void CreditCalculator::addToTable(int row, int column, const QString& value) {
  QStandardItem* interestItem = new QStandardItem(value);

  model_->setItem(row, column, interestItem);
}

void CreditCalculator::setOverpayment(const QString& overpayment) {
  ui_->overpaymentLineEdit->setText(overpayment);
}

void CreditCalculator::setTotalPayment(const QString& total_payment) {
  ui_->totalPaymentLineEdit->setText(total_payment);
}

}  // namespace s21
