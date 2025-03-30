#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QDoubleSpinBox * doubleSpingBox;

private slots:
    void doubleSpinBoxValueChanged(double value);
};
#endif // MAINWINDOW_H
