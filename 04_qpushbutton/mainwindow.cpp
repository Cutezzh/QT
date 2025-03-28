#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 480);
    pushButton1 = new QPushButton("window1_style", this);
    pushButton2 = new QPushButton("window2_style", this);
    pushButton1->setGeometry(100, 100, 150, 100);
    pushButton2->setGeometry(300, 100, 150, 100);

    connect(pushButton1, SIGNAL(clicked()), this, SLOT(pushButton1_Clicked()));
    connect(pushButton2, SIGNAL(clicked()), this, SLOT(pushButton2_Clicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButton1_Clicked()
{
    this->setStyleSheet("QMainWindow {background-color: rgb(255, 245, 238)}");
}

void MainWindow::pushButton2_Clicked()
{
    this->setStyleSheet("QMainWindow {background-color: rgb(238, 122, 233)}");
}

