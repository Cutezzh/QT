#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsColorizeEffect>
#include <QGraphicsOpacityEffect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    propertyAnimation0 = new QPropertyAnimation(ui->geometrywidget, "geometry");

    propertyAnimation0->setStartValue(QRect(0, 0, 100, 100));
    propertyAnimation0->setKeyValueAt(0.5, QRect(400, 0, 100, 100));
    propertyAnimation0->setEndValue(QRect(400, 200, 200, 200));
    propertyAnimation0->setDuration(2000);

    propertyAnimation0->setLoopCount(1);
    propertyAnimation0->setEasingCurve(QEasingCurve::OutCubic);

    QGraphicsColorizeEffect *graphicsColorizeEffect = new QGraphicsColorizeEffect(this);
    ui->colorwidget->setGraphicsEffect(graphicsColorizeEffect);
    propertyAnimation1 = new QPropertyAnimation(graphicsColorizeEffect, "color");
    propertyAnimation1->setStartValue(QColor(Qt::yellow));
    propertyAnimation1->setEndValue(QColor(Qt::darkRed));
    propertyAnimation1->setDuration(3000);
    //propertyAnimation1->setEasingCurve(QEasingCurve::InOutQuart);

    QGraphicsOpacityEffect *graphicsOpacityEffect = new QGraphicsOpacityEffect(this);
    ui->opacitywidget->setGraphicsEffect(graphicsOpacityEffect);
    propertyAnimation2 = new QPropertyAnimation(graphicsOpacityEffect, "opacity");
    propertyAnimation2->setStartValue(0.0);
    propertyAnimation2->setEndValue(1.0);
    propertyAnimation2->setDuration(3000);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    propertyAnimation0->start();
}

void Widget::on_pushButton_2_clicked()
{
    propertyAnimation1->start();
}

void Widget::on_pushButton_3_clicked()
{
    propertyAnimation2->start();
}
