#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include <QDialog>

namespace Ui {
class File_Dialog;
}

class File_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit File_Dialog(QWidget *parent = nullptr);
    ~File_Dialog();

    QString getTextEditContent();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_clicked();

private:
    Ui::File_Dialog *ui;
};

#endif // FILE_DIALOG_H
