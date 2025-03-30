#include "widget.h"
#include "ui_widget.h"
#include "qqitem.h"

#include <QListWidgetItem>

class QQItem;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    QQItem *qqItem0 = new QQItem(":/icons/icon1.jpg", true, "Timerliner_zzh");
    QQItem *qqItem1 = new QQItem(":/icons/icon0.jpg", false, "cutezzh");
    QQItem *qqItem2 = new QQItem(":/icons/icon3.jpg", false, "zzh");
    QQItem *qqItem3 = new QQItem(":/icons/icon2.jpg", true, "super man");

    QListWidgetItem *item0 = new QListWidgetItem;
    QListWidgetItem *item1 = new QListWidgetItem;
    QListWidgetItem *item2 = new QListWidgetItem;
    QListWidgetItem *item3 = new QListWidgetItem;

    ui->listWidget->addItem(item0);
    ui->listWidget->setItemWidget(item0, qqItem0);
    ui->listWidget->addItem(item1);
    ui->listWidget->setItemWidget(item1, qqItem1);
    ui->listWidget->addItem(item2);
    ui->listWidget->setItemWidget(item2, qqItem2);
    ui->listWidget->addItem(item3);
    ui->listWidget->setItemWidget(item3, qqItem3);



}

Widget::~Widget()
{
    delete ui;
}


