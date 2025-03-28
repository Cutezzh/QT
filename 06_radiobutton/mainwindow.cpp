#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("QMainWindow {background-color:rgb(200, 50, 100)}");

    radioButton1 = new QRadioButton(this);
    radioButton2 = new QRadioButton(this);

    radioButton1->setGeometry(300, 200, 100, 50);
    radioButton2->setGeometry(400, 200, 100, 50);

    radioButton1->setText("button1");
    radioButton2->setText("button2");

    radioButton1->setChecked(true);
    radioButton2->setChecked(false);

}

MainWindow::~MainWindow()
{
}

