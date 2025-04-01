#include "rich.h"
#include "ui_rich.h"

Rich::Rich(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rich)
{
    ui->setupUi(this);
}

Rich::~Rich()
{
    delete ui;
}

qreal Rich::money() const
{
    return richMoney;
}

void Rich::setMoney(qreal money)
{
    richMoney = money;
    ui->moneylabel->setText(QString::number(richMoney) + "W");
}
