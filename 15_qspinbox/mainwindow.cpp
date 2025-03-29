#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("QMainWindow{background-color: rgb(100, 100, 100)}");
    spinBox = new QSpinBox(this);
    spinBox->setGeometry(350, 200, 150, 30);

    spinBox->setRange(0, 100);
    spinBox->setValue(100);
    spinBox->setSuffix("% Opacity");
    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBoxValueChanged(int)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::spinBoxValueChanged(int opacity)
{
    double doubleopacity = (double)opacity / 100;
    this->setWindowOpacity(doubleopacity);
}

