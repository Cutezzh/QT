#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    comboBox = new QComboBox(this);
    comboBox->setGeometry(300, 200, 150, 30);

    comboBox->addItem("one(defult)");
    comboBox->addItem("two");
    comboBox->addItem("three");

    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxInderChanged(int)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::comboBoxInderChanged(int index)
{
    qDebug() << "your choose is" << comboBox->itemText(index) << endl;
}

