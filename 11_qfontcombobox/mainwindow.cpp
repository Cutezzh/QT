#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    fontComboBox = new QFontComboBox(this);
    label = new QLabel(this);

    fontComboBox->setGeometry(280, 200, 200, 30);
    label->setGeometry(280, 250, 300, 50);

    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(fontComoboBoxFontChanged(QFont)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::fontComoboBoxFontChanged(QFont font)
{
    label->setFont(font);
    QString str = "use this label show the font's style\n font set for:" + fontComboBox->itemText(fontComboBox->currentIndex());
    label->setText(str);
}

