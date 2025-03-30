#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(300, 200, 200, 60);
    progressBar->setRange(0, 100);
    value = 0;
    progressBar->setValue(value);
    progressBar->setFormat("on charge %p%");

    timer = new QTimer(this);
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerTimeOut()
{
    value ++;
    progressBar->setValue(value);
    if(value>100) value = 0;
}

