#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    dial = new QDial(this);
    dial->setGeometry(300, 100, 200, 200);
    dial->setPageStep(10);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(1.00);
    dial->setRange(0, 100);
    label = new QLabel("0km/h", this);
    label->setGeometry(370, 300, 200, 50);

    connect(dial, SIGNAL(valueChanged(int)), this, SLOT(dialValueChanged(int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::dialValueChanged(int value)
{
    label->setText(QString::number(value) + "km/h");
}

