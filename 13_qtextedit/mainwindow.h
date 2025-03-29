#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *pushButton1, *pushButton2;
    QTextEdit *textEdit;

private slots:
    void pushButtonSelectAllClicked();
    void pushButtonClearAllClicked();
};
#endif // MAINWINDOW_H
