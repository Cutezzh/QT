#include "widget.h"
#include "ui_widget.h"
#include "file_dialog.h"
#include <QFile>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QFile file;
    file.setFileName(QDateTime::currentDateTime().toString("MMddhhmmss") + ".txt");
    file.open(QIODevice::ReadWrite);

    File_Dialog *filedialog = new File_Dialog(this);
    filedialog->resize(this->size());

    filedialog->show();
    filedialog->setModal(true);
    filedialog->exec();

    QString tmp = filedialog->getTextEditContent();
    file.write(tmp.toUtf8());
    file.close();

    if(tmp.length() == 0) file.remove();

    delete filedialog;

}
