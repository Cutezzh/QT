#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setGeometry(200, 20, 400, 300);

    QFont font;
    font.setPixelSize(10);
    calendarWidget->setFont(font);

    pushButton = new QPushButton("back to today", this);
    pushButton->setGeometry(200, 350, 100, 30);

    label = new QLabel(this);
    label->setGeometry(400, 350, 400, 30);
    QString str = "current date:" + calendarWidget->selectedDate().toString();
    label->setText(str);

    connect(calendarWidget, SIGNAL(selsctionChanged()), this, SLOT(calendarWidgetSelectionChanged()));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::calendarWidgetSelectionChanged()
{
    QString str = "selection date" + calendarWidget->selectedDate().toString();
    label->setText(str);
}

void MainWindow::pushButtonClicked()
{
    calendarWidget->setSelectedDate(QDate::currentDate());
}

