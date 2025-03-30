#include "qqitem.h"
#include "ui_qqitem.h"

QQItem::QQItem(QString icon, bool flag, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQItem)
{
    ui->setupUi(this);

    QImage image1(icon);
    ui->picture->setPixmap(QPixmap::fromImage(image1.scaled(ui->picture->width(), ui->picture->height())));

    QImage image2(":/icons/phone.png");
    ui->phone->setPixmap(QPixmap::fromImage(image2.scaled(ui->phone->width(), ui->phone->height())));
    ui->phone->setVisible(flag);

    ui->name->setText(name);
}

QQItem::~QQItem()
{
    delete ui;
}
