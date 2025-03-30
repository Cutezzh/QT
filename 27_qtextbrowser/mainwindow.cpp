#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 800, 480);
    this->setWindowTitle("文本浏览器");

    textBrowser = new QTextBrowser(this);
    this->setCentralWidget(textBrowser);
    openAction = new QAction("打开",this);

    ui->menubar->addAction(openAction);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openActionTriggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionTriggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),"", tr("Files(*.txt *.cpp *.h *.html *.htm)"));
    QFile myFile(fileName);
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in (&myFile);
    QString myText = in.readAll();

    if(fileName.endsWith("html") || fileName.endsWith("htm")){
    textBrowser->setHtml(myText);
    } else {
    textBrowser->setPlainText(myText);
    }

    /* ui 窗口自带有 statusbar（状态栏），设置打开的文件名 */
    ui->statusbar->showMessage("文件名： " + fileName);
}

