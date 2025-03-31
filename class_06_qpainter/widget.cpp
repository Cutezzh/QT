#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QFontMetrics>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , textContent("cutezzh, zzhcute, super man! we are the same~~")
{
    ui->setupUi(this);
    font.setPixelSize(50);

    QFontMetrics fontMertics(font);
    textContentWidth = fontMertics.width(textContent);

    timer = new QTimer(this);
    timer->start(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(200, 190, 87));
    painter.setFont(font);
    painter.setPen(pen);

    QRect rectf = this->rect();

    rectf.setLeft(this->width() - offset);
    painter.drawText(rectf, Qt::AlignVCenter, textContent);

//    QPen pen;
//    pen.setWidth(3);
//    pen.setColor(QColor(200, 190, 87));

//    QBrush brush("#888888");

//    painter.setPen(pen);
//    painter.setBrush(brush);

//    painter.drawRect(50, 100, 100, 200);

//    QPolygon polygon;
//    polygon.setPoints(3, 350, 200, 250, 300, 450, 300);
//    painter.drawPolygon(polygon);

//    painter.drawLine(500, 300, 500, 100);

//    painter.drawEllipse(100, 400, 200, 100);

//    QRectF qrectf(50, 100, 100, 200);
//    painter.drawText(qrectf,Qt::AlignCenter, "cuteZZH");

//    QPainterPath path;
//    path.moveTo(20, 80);
//    path.lineTo(20, 30);
//    path.cubicTo(80, 0, 50, 50, 80, 80);

    //    painter.drawPath(path);
}

void Widget::onTimerTimeout()
{
    if(offset < this->width() + textContentWidth){
        offset += 5;
    }else offset = 0;

    this->update();

}

