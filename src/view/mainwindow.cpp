#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::num0ButtonSignal, this, &MainWindow::slotButton());
}

MainWindow::~MainWindow()
{
    delete ui;
}

