#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QLabel * label;

private slots:
    void horzontalSliderValueChanged(int value);
    void verticalSliderValueChanged(int value);
};
#endif // MAINWINDOW_H
