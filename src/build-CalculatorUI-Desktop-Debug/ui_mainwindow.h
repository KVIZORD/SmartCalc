/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *mathCalcucator;
    QGridLayout *gridLayout_3;
    QGridLayout *mainLayout;
    QPushButton *divideButton;
    QPushButton *openBracketButton;
    QPushButton *num8Button;
    QPushButton *removeSymButton;
    QPushButton *num0Button;
    QPushButton *funcAtanButton;
    QPushButton *num2Button;
    QPushButton *funcCosButton;
    QPushButton *funcLogButton;
    QPushButton *plusButton;
    QPushButton *scienceNotationButton;
    QPushButton *funcSinButton;
    QPushButton *funcLnButton;
    QPushButton *num3Button;
    QPushButton *calculateButton;
    QPushButton *num6Button;
    QPushButton *expButton;
    QPushButton *multiplyButton;
    QPushButton *pointButton;
    QPushButton *funcModButton;
    QPushButton *num5Button;
    QPushButton *minusButton;
    QPushButton *num1Button;
    QPushButton *num4Button;
    QPushButton *allClearButton;
    QPushButton *closeBracketButton;
    QPushButton *funcAcosButton;
    QPushButton *num7Button;
    QVBoxLayout *screenLayout;
    QLineEdit *expressionLineEdit;
    QPlainTextEdit *historyTextEdit;
    QPushButton *funcSqrtButton;
    QPushButton *num9Button;
    QPushButton *funcTanButton;
    QHBoxLayout *varXLayout;
    QPushButton *varXButton;
    QLabel *varXLabel;
    QDoubleSpinBox *varXDoubleSpin;
    QPushButton *buildGraphButton;
    QWidget *graph;
    QGridLayout *gridLayout;
    QLabel *xEndLabel;
    QLabel *stepLabel;
    QLabel *yStartLabel;
    QDoubleSpinBox *stepDoubleSpin;
    QDoubleSpinBox *xEndDoubleSpin;
    QLabel *yEndLabel;
    QLabel *xStartLabel;
    QDoubleSpinBox *yStartDoubleSpin;
    QDoubleSpinBox *yEndDoubleSpin;
    QDoubleSpinBox *xStartDoubleSpin;
    QPlainTextEdit *functionViewTextEdit;
    QCustomPlot *graphWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(957, 590);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        mathCalcucator = new QWidget();
        mathCalcucator->setObjectName(QString::fromUtf8("mathCalcucator"));
        gridLayout_3 = new QGridLayout(mathCalcucator);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mainLayout = new QGridLayout();
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        divideButton = new QPushButton(mathCalcucator);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(divideButton->sizePolicy().hasHeightForWidth());
        divideButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(divideButton, 2, 6, 1, 1);

        openBracketButton = new QPushButton(mathCalcucator);
        openBracketButton->setObjectName(QString::fromUtf8("openBracketButton"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openBracketButton->sizePolicy().hasHeightForWidth());
        openBracketButton->setSizePolicy(sizePolicy1);

        mainLayout->addWidget(openBracketButton, 1, 3, 1, 1);

        num8Button = new QPushButton(mathCalcucator);
        num8Button->setObjectName(QString::fromUtf8("num8Button"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(num8Button->sizePolicy().hasHeightForWidth());
        num8Button->setSizePolicy(sizePolicy2);

        mainLayout->addWidget(num8Button, 2, 4, 1, 1);

        removeSymButton = new QPushButton(mathCalcucator);
        removeSymButton->setObjectName(QString::fromUtf8("removeSymButton"));
        sizePolicy1.setHeightForWidth(removeSymButton->sizePolicy().hasHeightForWidth());
        removeSymButton->setSizePolicy(sizePolicy1);

        mainLayout->addWidget(removeSymButton, 1, 6, 1, 1);

        num0Button = new QPushButton(mathCalcucator);
        num0Button->setObjectName(QString::fromUtf8("num0Button"));
        sizePolicy.setHeightForWidth(num0Button->sizePolicy().hasHeightForWidth());
        num0Button->setSizePolicy(sizePolicy);

        mainLayout->addWidget(num0Button, 5, 3, 1, 1);

        funcAtanButton = new QPushButton(mathCalcucator);
        funcAtanButton->setObjectName(QString::fromUtf8("funcAtanButton"));
        sizePolicy.setHeightForWidth(funcAtanButton->sizePolicy().hasHeightForWidth());
        funcAtanButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(funcAtanButton, 5, 1, 1, 1);

        num2Button = new QPushButton(mathCalcucator);
        num2Button->setObjectName(QString::fromUtf8("num2Button"));
        sizePolicy2.setHeightForWidth(num2Button->sizePolicy().hasHeightForWidth());
        num2Button->setSizePolicy(sizePolicy2);

        mainLayout->addWidget(num2Button, 4, 4, 1, 1);

        funcCosButton = new QPushButton(mathCalcucator);
        funcCosButton->setObjectName(QString::fromUtf8("funcCosButton"));
        sizePolicy.setHeightForWidth(funcCosButton->sizePolicy().hasHeightForWidth());
        funcCosButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(funcCosButton, 3, 1, 1, 1);

        funcLogButton = new QPushButton(mathCalcucator);
        funcLogButton->setObjectName(QString::fromUtf8("funcLogButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(funcLogButton->sizePolicy().hasHeightForWidth());
        funcLogButton->setSizePolicy(sizePolicy3);

        mainLayout->addWidget(funcLogButton, 3, 2, 1, 1);

        plusButton = new QPushButton(mathCalcucator);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        sizePolicy.setHeightForWidth(plusButton->sizePolicy().hasHeightForWidth());
        plusButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(plusButton, 5, 6, 1, 1);

        scienceNotationButton = new QPushButton(mathCalcucator);
        scienceNotationButton->setObjectName(QString::fromUtf8("scienceNotationButton"));
        sizePolicy.setHeightForWidth(scienceNotationButton->sizePolicy().hasHeightForWidth());
        scienceNotationButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(scienceNotationButton, 2, 0, 1, 1);

        funcSinButton = new QPushButton(mathCalcucator);
        funcSinButton->setObjectName(QString::fromUtf8("funcSinButton"));
        sizePolicy.setHeightForWidth(funcSinButton->sizePolicy().hasHeightForWidth());
        funcSinButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(funcSinButton, 2, 1, 1, 1);

        funcLnButton = new QPushButton(mathCalcucator);
        funcLnButton->setObjectName(QString::fromUtf8("funcLnButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(funcLnButton->sizePolicy().hasHeightForWidth());
        funcLnButton->setSizePolicy(sizePolicy4);

        mainLayout->addWidget(funcLnButton, 2, 2, 1, 1);

        num3Button = new QPushButton(mathCalcucator);
        num3Button->setObjectName(QString::fromUtf8("num3Button"));
        sizePolicy.setHeightForWidth(num3Button->sizePolicy().hasHeightForWidth());
        num3Button->setSizePolicy(sizePolicy);

        mainLayout->addWidget(num3Button, 4, 5, 1, 1);

        calculateButton = new QPushButton(mathCalcucator);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        sizePolicy.setHeightForWidth(calculateButton->sizePolicy().hasHeightForWidth());
        calculateButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(calculateButton, 5, 5, 1, 1);

        num6Button = new QPushButton(mathCalcucator);
        num6Button->setObjectName(QString::fromUtf8("num6Button"));
        sizePolicy.setHeightForWidth(num6Button->sizePolicy().hasHeightForWidth());
        num6Button->setSizePolicy(sizePolicy);

        mainLayout->addWidget(num6Button, 3, 5, 1, 1);

        expButton = new QPushButton(mathCalcucator);
        expButton->setObjectName(QString::fromUtf8("expButton"));
        sizePolicy.setHeightForWidth(expButton->sizePolicy().hasHeightForWidth());
        expButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(expButton, 5, 2, 1, 1);

        multiplyButton = new QPushButton(mathCalcucator);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));
        sizePolicy3.setHeightForWidth(multiplyButton->sizePolicy().hasHeightForWidth());
        multiplyButton->setSizePolicy(sizePolicy3);

        mainLayout->addWidget(multiplyButton, 3, 6, 1, 1);

        pointButton = new QPushButton(mathCalcucator);
        pointButton->setObjectName(QString::fromUtf8("pointButton"));
        sizePolicy3.setHeightForWidth(pointButton->sizePolicy().hasHeightForWidth());
        pointButton->setSizePolicy(sizePolicy3);

        mainLayout->addWidget(pointButton, 5, 4, 1, 1);

        funcModButton = new QPushButton(mathCalcucator);
        funcModButton->setObjectName(QString::fromUtf8("funcModButton"));
        sizePolicy3.setHeightForWidth(funcModButton->sizePolicy().hasHeightForWidth());
        funcModButton->setSizePolicy(sizePolicy3);

        mainLayout->addWidget(funcModButton, 1, 2, 1, 1);

        num5Button = new QPushButton(mathCalcucator);
        num5Button->setObjectName(QString::fromUtf8("num5Button"));
        sizePolicy2.setHeightForWidth(num5Button->sizePolicy().hasHeightForWidth());
        num5Button->setSizePolicy(sizePolicy2);

        mainLayout->addWidget(num5Button, 3, 4, 1, 1);

        minusButton = new QPushButton(mathCalcucator);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        sizePolicy.setHeightForWidth(minusButton->sizePolicy().hasHeightForWidth());
        minusButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(minusButton, 4, 6, 1, 1);

        num1Button = new QPushButton(mathCalcucator);
        num1Button->setObjectName(QString::fromUtf8("num1Button"));
        sizePolicy.setHeightForWidth(num1Button->sizePolicy().hasHeightForWidth());
        num1Button->setSizePolicy(sizePolicy);

        mainLayout->addWidget(num1Button, 4, 3, 1, 1);

        num4Button = new QPushButton(mathCalcucator);
        num4Button->setObjectName(QString::fromUtf8("num4Button"));
        sizePolicy.setHeightForWidth(num4Button->sizePolicy().hasHeightForWidth());
        num4Button->setSizePolicy(sizePolicy);

        mainLayout->addWidget(num4Button, 3, 3, 1, 1);

        allClearButton = new QPushButton(mathCalcucator);
        allClearButton->setObjectName(QString::fromUtf8("allClearButton"));
        sizePolicy1.setHeightForWidth(allClearButton->sizePolicy().hasHeightForWidth());
        allClearButton->setSizePolicy(sizePolicy1);

        mainLayout->addWidget(allClearButton, 1, 5, 1, 1);

        closeBracketButton = new QPushButton(mathCalcucator);
        closeBracketButton->setObjectName(QString::fromUtf8("closeBracketButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(closeBracketButton->sizePolicy().hasHeightForWidth());
        closeBracketButton->setSizePolicy(sizePolicy5);

        mainLayout->addWidget(closeBracketButton, 1, 4, 1, 1);

        funcAcosButton = new QPushButton(mathCalcucator);
        funcAcosButton->setObjectName(QString::fromUtf8("funcAcosButton"));
        sizePolicy.setHeightForWidth(funcAcosButton->sizePolicy().hasHeightForWidth());
        funcAcosButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(funcAcosButton, 1, 1, 1, 1);

        num7Button = new QPushButton(mathCalcucator);
        num7Button->setObjectName(QString::fromUtf8("num7Button"));
        sizePolicy3.setHeightForWidth(num7Button->sizePolicy().hasHeightForWidth());
        num7Button->setSizePolicy(sizePolicy3);

        mainLayout->addWidget(num7Button, 2, 3, 1, 1);

        screenLayout = new QVBoxLayout();
        screenLayout->setObjectName(QString::fromUtf8("screenLayout"));
        expressionLineEdit = new QLineEdit(mathCalcucator);
        expressionLineEdit->setObjectName(QString::fromUtf8("expressionLineEdit"));
        expressionLineEdit->setMaxLength(255);
        expressionLineEdit->setReadOnly(true);

        screenLayout->addWidget(expressionLineEdit);

        historyTextEdit = new QPlainTextEdit(mathCalcucator);
        historyTextEdit->setObjectName(QString::fromUtf8("historyTextEdit"));
        historyTextEdit->setReadOnly(true);

        screenLayout->addWidget(historyTextEdit);

        screenLayout->setStretch(1, 2);

        mainLayout->addLayout(screenLayout, 0, 0, 1, 7);

        funcSqrtButton = new QPushButton(mathCalcucator);
        funcSqrtButton->setObjectName(QString::fromUtf8("funcSqrtButton"));
        sizePolicy.setHeightForWidth(funcSqrtButton->sizePolicy().hasHeightForWidth());
        funcSqrtButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(funcSqrtButton, 4, 2, 1, 1);

        num9Button = new QPushButton(mathCalcucator);
        num9Button->setObjectName(QString::fromUtf8("num9Button"));
        sizePolicy5.setHeightForWidth(num9Button->sizePolicy().hasHeightForWidth());
        num9Button->setSizePolicy(sizePolicy5);

        mainLayout->addWidget(num9Button, 2, 5, 1, 1);

        funcTanButton = new QPushButton(mathCalcucator);
        funcTanButton->setObjectName(QString::fromUtf8("funcTanButton"));
        sizePolicy.setHeightForWidth(funcTanButton->sizePolicy().hasHeightForWidth());
        funcTanButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(funcTanButton, 4, 1, 1, 1);

        varXLayout = new QHBoxLayout();
        varXLayout->setObjectName(QString::fromUtf8("varXLayout"));
        varXButton = new QPushButton(mathCalcucator);
        varXButton->setObjectName(QString::fromUtf8("varXButton"));
        sizePolicy1.setHeightForWidth(varXButton->sizePolicy().hasHeightForWidth());
        varXButton->setSizePolicy(sizePolicy1);

        varXLayout->addWidget(varXButton);

        varXLabel = new QLabel(mathCalcucator);
        varXLabel->setObjectName(QString::fromUtf8("varXLabel"));

        varXLayout->addWidget(varXLabel);

        varXDoubleSpin = new QDoubleSpinBox(mathCalcucator);
        varXDoubleSpin->setObjectName(QString::fromUtf8("varXDoubleSpin"));
        sizePolicy.setHeightForWidth(varXDoubleSpin->sizePolicy().hasHeightForWidth());
        varXDoubleSpin->setSizePolicy(sizePolicy);
        varXDoubleSpin->setMaximum(9999999999.000000000000000);

        varXLayout->addWidget(varXDoubleSpin);


        mainLayout->addLayout(varXLayout, 1, 0, 1, 1);

        buildGraphButton = new QPushButton(mathCalcucator);
        buildGraphButton->setObjectName(QString::fromUtf8("buildGraphButton"));
        sizePolicy.setHeightForWidth(buildGraphButton->sizePolicy().hasHeightForWidth());
        buildGraphButton->setSizePolicy(sizePolicy);

        mainLayout->addWidget(buildGraphButton, 3, 0, 3, 1);

        mainLayout->setRowStretch(0, 4);
        mainLayout->setRowStretch(1, 1);
        mainLayout->setRowStretch(2, 1);
        mainLayout->setRowStretch(3, 1);
        mainLayout->setRowStretch(4, 1);
        mainLayout->setRowStretch(5, 1);

        gridLayout_3->addLayout(mainLayout, 0, 0, 1, 1);

        tabWidget->addTab(mathCalcucator, QString());
        graph = new QWidget();
        graph->setObjectName(QString::fromUtf8("graph"));
        gridLayout = new QGridLayout(graph);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        xEndLabel = new QLabel(graph);
        xEndLabel->setObjectName(QString::fromUtf8("xEndLabel"));

        gridLayout->addWidget(xEndLabel, 2, 0, 1, 1);

        stepLabel = new QLabel(graph);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));

        gridLayout->addWidget(stepLabel, 5, 0, 1, 1);

        yStartLabel = new QLabel(graph);
        yStartLabel->setObjectName(QString::fromUtf8("yStartLabel"));

        gridLayout->addWidget(yStartLabel, 3, 0, 1, 1);

        stepDoubleSpin = new QDoubleSpinBox(graph);
        stepDoubleSpin->setObjectName(QString::fromUtf8("stepDoubleSpin"));

        gridLayout->addWidget(stepDoubleSpin, 5, 1, 1, 1);

        xEndDoubleSpin = new QDoubleSpinBox(graph);
        xEndDoubleSpin->setObjectName(QString::fromUtf8("xEndDoubleSpin"));
        xEndDoubleSpin->setMinimum(-1000000.000000000000000);
        xEndDoubleSpin->setMaximum(1000000.000000000000000);

        gridLayout->addWidget(xEndDoubleSpin, 2, 1, 1, 1);

        yEndLabel = new QLabel(graph);
        yEndLabel->setObjectName(QString::fromUtf8("yEndLabel"));

        gridLayout->addWidget(yEndLabel, 4, 0, 1, 1);

        xStartLabel = new QLabel(graph);
        xStartLabel->setObjectName(QString::fromUtf8("xStartLabel"));

        gridLayout->addWidget(xStartLabel, 1, 0, 1, 1);

        yStartDoubleSpin = new QDoubleSpinBox(graph);
        yStartDoubleSpin->setObjectName(QString::fromUtf8("yStartDoubleSpin"));
        yStartDoubleSpin->setMinimum(-1000000.000000000000000);
        yStartDoubleSpin->setMaximum(1000000.000000000000000);

        gridLayout->addWidget(yStartDoubleSpin, 3, 1, 1, 1);

        yEndDoubleSpin = new QDoubleSpinBox(graph);
        yEndDoubleSpin->setObjectName(QString::fromUtf8("yEndDoubleSpin"));
        yEndDoubleSpin->setMinimum(-1000000.000000000000000);
        yEndDoubleSpin->setMaximum(1000000.000000000000000);

        gridLayout->addWidget(yEndDoubleSpin, 4, 1, 1, 1);

        xStartDoubleSpin = new QDoubleSpinBox(graph);
        xStartDoubleSpin->setObjectName(QString::fromUtf8("xStartDoubleSpin"));
        xStartDoubleSpin->setMinimum(-1000000.000000000000000);
        xStartDoubleSpin->setMaximum(1000000.000000000000000);

        gridLayout->addWidget(xStartDoubleSpin, 1, 1, 1, 1);

        functionViewTextEdit = new QPlainTextEdit(graph);
        functionViewTextEdit->setObjectName(QString::fromUtf8("functionViewTextEdit"));
        functionViewTextEdit->setReadOnly(true);

        gridLayout->addWidget(functionViewTextEdit, 1, 2, 5, 1);

        graphWidget = new QCustomPlot(graph);
        graphWidget->setObjectName(QString::fromUtf8("graphWidget"));

        gridLayout->addWidget(graphWidget, 0, 0, 1, 3);

        gridLayout->setColumnStretch(1, 1);
        tabWidget->addTab(graph, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        divideButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        openBracketButton->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        num8Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        removeSymButton->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        num0Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        funcAtanButton->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        num2Button->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        funcCosButton->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        funcLogButton->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        scienceNotationButton->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        funcSinButton->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        funcLnButton->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        num3Button->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        num6Button->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        expButton->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pointButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        funcModButton->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        num5Button->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        num1Button->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        num4Button->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        allClearButton->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        closeBracketButton->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        funcAcosButton->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        num7Button->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        funcSqrtButton->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        num9Button->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        funcTanButton->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        varXButton->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        varXLabel->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        buildGraphButton->setText(QCoreApplication::translate("MainWindow", "Build graph", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mathCalcucator), QCoreApplication::translate("MainWindow", "Math", nullptr));
        xEndLabel->setText(QCoreApplication::translate("MainWindow", "X (end) = ", nullptr));
        stepLabel->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        yStartLabel->setText(QCoreApplication::translate("MainWindow", "Y (start = ", nullptr));
        yEndLabel->setText(QCoreApplication::translate("MainWindow", "Y (end) =", nullptr));
        xStartLabel->setText(QCoreApplication::translate("MainWindow", "X (start) = ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(graph), QCoreApplication::translate("MainWindow", "Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
