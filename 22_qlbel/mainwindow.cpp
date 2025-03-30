#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    QPixmap pixmap(":/image/logo.png");
    labelImage = new QLabel(this);
    labelImage->setGeometry(180, 150, 452, 132);
    labelImage->setPixmap(pixmap);
    labelImage->setScaledContents(true);

    labelString = new QLabel("show text", this);
    labelString->setGeometry(300, 300, 100, 20);
}

MainWindow::~MainWindow()
{
}

