#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QRadioButton *radioButton;
    QPlainTextEdit *plainTextEdit;

private slots:
    void radioButtonClicked();
};
#endif // MAINWINDOW_H
