#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QLCDNumber>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLCDNumber *lcdNumber;
    QTimer *timer;

private slots:
    void timerTimeOut();

};
#endif // MAINWINDOW_H
