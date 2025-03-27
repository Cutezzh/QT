#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 480);//set the window's size
    pushButton = new QPushButton(this);//create a QPushButton object
    pushButton->setText("I am a button");//function call setText()
    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));//connect the slot and signal
    connect(this, SIGNAL(pushButtonTextChanged()), this, SLOT(changeButtonText()));
}
/* pushbutton slots */
void MainWindow::pushButtonClicked(){
    emit pushButtonTextChanged();
}
/* implement a change button text */
void MainWindow::changeButtonText(){
    pushButton->setText("be clicked!");
}

MainWindow::~MainWindow()
{
}

