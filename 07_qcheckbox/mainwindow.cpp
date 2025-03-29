#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("QMainWindow {background-color: rgb(100, 100, 100);}");
    checkBox = new QCheckBox(this);
    checkBox->setGeometry(350, 200, 250, 50);
    checkBox->setCheckState(Qt::Checked);
    checkBox->setText("initial");
    checkBox->setTristate();

    connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChanged(int)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::checkBoxStateChanged(int state)
{
    switch (state) {
    case Qt::Checked:
        checkBox->setText("checked");
        break;
    case Qt::Unchecked:
        checkBox->setText("unchecked");
        break;
    case Qt::PartiallyChecked:
        checkBox->setText("partiallychecked");
        break;
    default:
        break;
    }
}
