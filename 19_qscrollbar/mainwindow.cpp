#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    horizontalScrollBar = new QScrollBar(Qt::Horizontal, this);
    horizontalScrollBar->setGeometry(0, 450, 800, 30);

    verticalScrollBar = new QScrollBar(Qt::Vertical, this);
    verticalScrollBar->setGeometry(700, 0, 30, 480);

    label = new QLabel("this is a test", this);
    label->setGeometry(300, 200, 100, 20);
}

MainWindow::~MainWindow()
{
}

