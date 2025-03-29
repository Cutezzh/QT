#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    textEdit = new QTextEdit(this);
    textEdit->setGeometry(0, 0, 800, 400);
    pushButton1 = new QPushButton("choose all", this);
    pushButton1->setGeometry(200, 420, 100, 20);
    pushButton2 = new QPushButton("clear all", this);
    pushButton2->setGeometry(500, 420, 100, 20);

    connect(pushButton1, SIGNAL(clicked()), this, SLOT(pushButtonSelectAllClicked()));
    connect(pushButton2, SIGNAL(clicked()), this, SLOT(pushButtonClearAllClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButtonSelectAllClicked()
{
    textEdit->setFocus();
    if(!textEdit->toPlainText().isEmpty()){
        textEdit->selectAll();
    }
}

void MainWindow::pushButtonClearAllClicked()
{
    textEdit->clear();
}

