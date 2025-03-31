#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "open the file", "/home/book");
    qDebug() << filename << endl;

    file.setFileName(filename);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "open the file fail" << endl;
        return;
    }

    ui->textEdit->setPlainText(file.readAll());
    file.close();
}

void Widget::on_pushButton_2_clicked()
{
    if(file.fileName().isEmpty())
        return;
    if(!file.open(QIODevice::ReadWrite)){
        qDebug() << "open the file fail" << endl;
        return;
    }
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
    ui->textEdit->clear();
}
