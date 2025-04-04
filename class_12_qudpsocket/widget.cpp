#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);


    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));

    connect(udpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(mStateChanged(QAbstractSocket::SocketState)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readPendingDatagrams()
{
    QByteArray tmpByteArray;
    tmpByteArray.resize(udpSocket->pendingDatagramSize());
    QHostAddress ipaddr;
    quint16 port;
    while (udpSocket->hasPendingDatagrams()) {
        udpSocket->readDatagram(tmpByteArray.data(), tmpByteArray.size(), &ipaddr, &port);
        ui->textBrowser->append("receive from:" + ipaddr.toString() + ":" + QString::number(port) + tmpByteArray);
    }
}


void Widget::on_pushButton_3_clicked()
{
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress("127.0.0.1"), 7755);

}

void Widget::on_pushButton_clicked()
{
    udpSocket->bind(7755);
}

void Widget::on_pushButton_2_clicked()
{
    udpSocket->abort();
}

void Widget::on_pushButton_4_clicked()
{
    udpSocket->writeDatagram(ui->lineEdit->text().toUtf8(), QHostAddress::Broadcast, 7755);
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
