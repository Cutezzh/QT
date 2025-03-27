#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    /* declare a signal, not define */
    void pushButtonTextChanged();

public slots:
    /* declare a slot */
    void changeButtonText();
    /* declare a button click slot */
    void pushButtonClicked();

private:
    /* declare a pushButton object */
    QPushButton *pushButton;
};
#endif // MAINWINDOW_H
