#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
    ui->pushButton_2->setEnabled(false);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(mReceiveMessage()));
    connect(tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(mStateChanged(QAbstractSocket::SocketState)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mReceiveMessage()
{
    ui->textBrowser->append("Server:" + tcpSocket->readAll());
}

void Widget::mStateChanged(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        ui->textBrowser->append("scoket state: UnconnectedState");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        break;
    case QAbstractSocket::HostLookupState:
        ui->textBrowser->append("scoket state: HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        ui->textBrowser->append("scoket state: ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textBrowser->append("scoket state: ConnectedState");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        break;
    case QAbstractSocket::BoundState:
        ui->textBrowser->append("scoket state: BoundState");
        break;
    case QAbstractSocket::ListeningState:
        ui->textBrowser->append("scoket state: ListeningState");
        break;
    case QAbstractSocket::ClosingState:
        ui->textBrowser->append("scoket state: ClosingState");
        break;
    default:
        break;
    }
}


void Widget::on_pushButton_3_clicked()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    tcpSocket->write(ui->lineEdit->text().toUtf8());
    else {
        ui->textBrowser->append("please connect the Server first!");
        return;
    }
    ui->lineEdit->clear();
}

void Widget::on_pushButton_clicked()
{
    tcpSocket->connectToHost(QHostAddress("192.168.146.128"), 9999);
}

void Widget::on_pushButton_2_clicked()
{
    tcpSocket->disconnectFromHost();
}
