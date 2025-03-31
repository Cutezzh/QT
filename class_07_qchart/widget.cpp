#include "widget.h"
#include "ui_widget.h"
#include <QValueAxis>
#include <QSplineSeries>
//#include <QLineSeries>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QChartView *charView = new QChartView();

    QChart *chart = new QChart();
    QValueAxis *valueAxisX = new QValueAxis();
    QValueAxis *valueAxisY = new QValueAxis();

    valueAxisX->setRange(0, 5000);
    valueAxisY->setRange(0, 100);

    valueAxisX->setTitleText("Time/ms");
    valueAxisY->setTitleText("Temperature/oC");
    valueAxisX->setLabelFormat("%d");
    valueAxisY->setLabelFormat("%d");

    chart->createDefaultAxes();
    chart->addAxis(valueAxisX, Qt::AlignBottom);
    chart->addAxis(valueAxisY, Qt::AlignLeft);

    chart->setTitle("temperature versus time curve");
    chart->legend()->setVisible(false);

    QSplineSeries *splineSeries = new QSplineSeries();
    splineSeries->append(0, 20);
    splineSeries->append(1000, 40);
    splineSeries->append(2000, 50);
    splineSeries->append(3000, 20);
    splineSeries->append(4000, 60);
    splineSeries->append(5000, 30);

    QPen pen(QColor(0x888888));
    splineSeries->setPen(pen);

    chart->addSeries(splineSeries);

    splineSeries->attachAxis(valueAxisX);
    splineSeries->attachAxis(valueAxisY);

    ui->qchartview->setChart(chart);

}

Widget::~Widget()
{
    delete ui;
}

