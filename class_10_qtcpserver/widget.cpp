#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(m_NewConnetion()));
    ui->pushButton_2->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::m_NewConnetion()
{
    QTcpSocket *tmpTcpSocket = tcpServer->nextPendingConnection();

    ui->textBrowser->append("Client's IP:" + tmpTcpSocket->peerAddress().toString());
    ui->textBrowser->append("Client's PORT:" + QString::number(tmpTcpSocket->peerPort()));
    connect(tmpTcpSocket, SIGNAL(readyRead()), this, SLOT(mReceiveMessages()));
    connect(tmpTcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(mStateChanged(QAbstractSocket::SocketState)));
}

void Widget::mReceiveMessages()
{
    QTcpSocket *tmpTcpSocket = (QTcpSocket *)sender();
    ui->textBrowser->append("Client:" + tmpTcpSocket->readAll());
}

void Widget::mStateChanged(QAbstractSocket::SocketState state)
{
    QTcpSocket *tmpTcpSocket = (QTcpSocket *)sender();
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        ui->textBrowser->append("scoket state: UnconnectedState");
        tmpTcpSocket->deleteLater();
        break;
    case QAbstractSocket::HostLookupState:
        ui->textBrowser->append("scoket state: HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        ui->textBrowser->append("scoket state: ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textBrowser->append("scoket state: ConnectedState");
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
    QList <QTcpSocket *> socketList = tcpServer->findChildren<QTcpSocket *>();
    if(socketList.count() == 0){
        ui->textBrowser->append("No Client!");
        return;
    }
    foreach (QTcpSocket *tmpTcpSocket, socketList) {
     tmpTcpSocket->write(ui->lineEdit->text().toUtf8());
    }
    ui->lineEdit->clear();
}

void Widget::on_pushButton_clicked()
{
    tcpServer->listen(QHostAddress("192.168.146.128"), 9999);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void Widget::on_pushButton_2_clicked()
{
    tcpServer->close();
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}
