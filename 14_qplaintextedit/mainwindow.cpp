#include "mainwindow.h"
#include <QDir>
#include <QTextStream>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    this->setGeometry(0, 0, 800, 480);

    plainTextEdit = new QPlainTextEdit(this);
    plainTextEdit->setGeometry(0, 50, 800, 430);

    radioButton = new QRadioButton("readonly", this);
    radioButton->setGeometry(650, 20, 100, 20);

    QFile file("moc_mainwindow.cpp");
    file.open((QFile::ReadOnly | QFile::Text));
    QTextStream in(&file);
    plainTextEdit->insertPlainText(in.readAll());

    connect(radioButton, SIGNAL(clicked()), this, SLOT(radioButtonClicked()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::radioButtonClicked()
{
    if(radioButton->isChecked()){
        plainTextEdit->setReadOnly(true);
    }else {
        plainTextEdit->setReadOnly(false);
    }

}

