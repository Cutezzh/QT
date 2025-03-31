#include "file_dialog.h"
#include "ui_file_dialog.h"

File_Dialog::File_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File_Dialog)
{
    ui->setupUi(this);
}

File_Dialog::~File_Dialog()
{
    delete ui;
}

QString File_Dialog::getTextEditContent()
{
    return ui->textEdit->toPlainText();
}

void File_Dialog::on_pushButton_pressed()
{
    ui->pushButton->setIcon(QIcon(":/icons/back.png"));
}

void File_Dialog::on_pushButton_released()
{
    ui->pushButton->setIcon(QIcon(":/icons/back_press.png"));
}

void File_Dialog::on_pushButton_clicked()
{
    this->close();
}
