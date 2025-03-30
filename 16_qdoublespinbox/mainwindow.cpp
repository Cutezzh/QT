#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    doubleSpingBox = new QDoubleSpinBox(this);
    doubleSpingBox->setGeometry((this->width() - 200) / 2, (this->height() - 30) / 2, 200, 30);
    doubleSpingBox->setPrefix("window's size");
    doubleSpingBox->setSuffix("%");
    doubleSpingBox->setRange(50.0, 100.0);
    doubleSpingBox->setValue(100.0);
    doubleSpingBox->setSingleStep(0.1);
    connect(doubleSpingBox, SIGNAL(valueChanged(double)), this, SLOT(doubleSpinBoxValueChanged(double)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::doubleSpinBoxValueChanged(double value)
{
    int w = 800 * value / 100;
    int h = 480 * value /100;
    this->setGeometry(0, 0, w, h);
    doubleSpingBox->setGeometry((this->width() - 200) / 2, (this->height() - 30) / 2, 200, 30);
}

