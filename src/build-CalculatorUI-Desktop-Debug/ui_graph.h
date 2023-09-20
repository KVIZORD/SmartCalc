/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include "include/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *graphWidget;
    QLabel *xStartLabel;
    QDoubleSpinBox *xStartDoubleSpin;
    QLabel *xEndLabel;
    QDoubleSpinBox *xEndDoubleSpin;
    QLabel *yStartLabel;
    QDoubleSpinBox *yStartDoubleSpin;
    QLabel *yEndLabel;
    QDoubleSpinBox *yEndDoubleSpin;
    QLabel *stepLabel;
    QDoubleSpinBox *stepDoubleSpin;
    QLineEdit *expressionLineEdit;

    void setupUi(QWidget *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->resize(771, 544);
        gridLayout = new QGridLayout(Graph);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphWidget = new QCustomPlot(Graph);
        graphWidget->setObjectName(QString::fromUtf8("graphWidget"));

        gridLayout->addWidget(graphWidget, 0, 0, 1, 3);

        xStartLabel = new QLabel(Graph);
        xStartLabel->setObjectName(QString::fromUtf8("xStartLabel"));

        gridLayout->addWidget(xStartLabel, 1, 0, 1, 1);

        xStartDoubleSpin = new QDoubleSpinBox(Graph);
        xStartDoubleSpin->setObjectName(QString::fromUtf8("xStartDoubleSpin"));
        xStartDoubleSpin->setMinimum(-1000000.000000000000000);
        xStartDoubleSpin->setMaximum(1000000.000000000000000);
        xStartDoubleSpin->setValue(-10.000000000000000);

        gridLayout->addWidget(xStartDoubleSpin, 1, 1, 1, 1);

        xEndLabel = new QLabel(Graph);
        xEndLabel->setObjectName(QString::fromUtf8("xEndLabel"));

        gridLayout->addWidget(xEndLabel, 2, 0, 1, 1);

        xEndDoubleSpin = new QDoubleSpinBox(Graph);
        xEndDoubleSpin->setObjectName(QString::fromUtf8("xEndDoubleSpin"));
        xEndDoubleSpin->setMinimum(-1000000.000000000000000);
        xEndDoubleSpin->setMaximum(1000000.000000000000000);
        xEndDoubleSpin->setValue(10.000000000000000);

        gridLayout->addWidget(xEndDoubleSpin, 2, 1, 1, 1);

        yStartLabel = new QLabel(Graph);
        yStartLabel->setObjectName(QString::fromUtf8("yStartLabel"));

        gridLayout->addWidget(yStartLabel, 3, 0, 1, 1);

        yStartDoubleSpin = new QDoubleSpinBox(Graph);
        yStartDoubleSpin->setObjectName(QString::fromUtf8("yStartDoubleSpin"));
        yStartDoubleSpin->setMinimum(-1000000.000000000000000);
        yStartDoubleSpin->setMaximum(1000000.000000000000000);
        yStartDoubleSpin->setValue(-3.000000000000000);

        gridLayout->addWidget(yStartDoubleSpin, 3, 1, 1, 1);

        yEndLabel = new QLabel(Graph);
        yEndLabel->setObjectName(QString::fromUtf8("yEndLabel"));

        gridLayout->addWidget(yEndLabel, 4, 0, 1, 1);

        yEndDoubleSpin = new QDoubleSpinBox(Graph);
        yEndDoubleSpin->setObjectName(QString::fromUtf8("yEndDoubleSpin"));
        yEndDoubleSpin->setMinimum(-1000000.000000000000000);
        yEndDoubleSpin->setMaximum(1000000.000000000000000);
        yEndDoubleSpin->setValue(3.000000000000000);

        gridLayout->addWidget(yEndDoubleSpin, 4, 1, 1, 1);

        stepLabel = new QLabel(Graph);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));

        gridLayout->addWidget(stepLabel, 5, 0, 1, 1);

        stepDoubleSpin = new QDoubleSpinBox(Graph);
        stepDoubleSpin->setObjectName(QString::fromUtf8("stepDoubleSpin"));
        stepDoubleSpin->setDecimals(5);
        stepDoubleSpin->setMinimum(0.000010000000000);
        stepDoubleSpin->setMaximum(1000000.000000000000000);
        stepDoubleSpin->setValue(0.010000000000000);

        gridLayout->addWidget(stepDoubleSpin, 5, 1, 1, 1);

        expressionLineEdit = new QLineEdit(Graph);
        expressionLineEdit->setObjectName(QString::fromUtf8("expressionLineEdit"));
        expressionLineEdit->setAlignment(Qt::AlignCenter);
        expressionLineEdit->setReadOnly(true);

        gridLayout->addWidget(expressionLineEdit, 3, 2, 1, 1);


        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QWidget *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "Graphic", nullptr));
        xStartLabel->setText(QCoreApplication::translate("Graph", "X (min) = ", nullptr));
        xEndLabel->setText(QCoreApplication::translate("Graph", "X (max) = ", nullptr));
        yStartLabel->setText(QCoreApplication::translate("Graph", "Y (min) = ", nullptr));
        yEndLabel->setText(QCoreApplication::translate("Graph", "Y (max) =", nullptr));
        stepLabel->setText(QCoreApplication::translate("Graph", "Step =", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
