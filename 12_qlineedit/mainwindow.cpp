#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(280, 200, 200, 20);

    pushButton = new QPushButton("Check", this);
    pushButton->setGeometry(500, 200, 50, 20);

    label1 = new QLabel("Please enter text below", this);
    label1->setGeometry(280, 180, 200, 20);
    label2 = new QLabel(this);
    label2->setGeometry(280, 250, 400, 20);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButtonClicked()
{
    QString str = "your scanf message is: ";
    str += lineEdit->text();
    label2->setText(str);
    lineEdit->clear();
}

