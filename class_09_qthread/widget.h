#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>

class MyThread;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    MyThread *mythread;
};

class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread(QWidget *parent = nullptr){
        Q_UNUSED(parent)
    }
    ~MyThread(){

    }
    void run() override{

    }
};
#endif // WIDGET_H
