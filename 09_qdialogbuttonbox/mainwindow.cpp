#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    dialogButtonBox = new QDialogButtonBox(this);
    dialogButtonBox->setGeometry(300, 200, 200, 30);
    dialogButtonBox->addButton(QDialogButtonBox::Cancel);

    pushButton = new QPushButton("Custom", this);
    dialogButtonBox->addButton(pushButton, QDialogButtonBox::ActionRole);

    connect(dialogButtonBox, SIGNAL(clicked(QAbstractButton *)), this, SLOT(dialogButtonBoxClicked(QAbstractButton *)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::dialogButtonBoxClicked(QAbstractButton* button)
{
    if(button == dialogButtonBox->button(QDialogButtonBox::Cancel)){
        qDebug() << "click the cancel" << endl;
    }else if(button == pushButton){
        qDebug() << "click the custom" << endl;
    }
}

