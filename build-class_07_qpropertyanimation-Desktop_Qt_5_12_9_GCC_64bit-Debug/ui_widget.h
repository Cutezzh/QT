/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *geometrywidget;
    QWidget *colorwidget;
    QWidget *opacitywidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 480);
        geometrywidget = new QWidget(Widget);
        geometrywidget->setObjectName(QString::fromUtf8("geometrywidget"));
        geometrywidget->setGeometry(QRect(180, 60, 120, 80));
        geometrywidget->setStyleSheet(QString::fromUtf8("QWidget{background-color: rgb(239, 41, 41); }\n"
""));
        colorwidget = new QWidget(Widget);
        colorwidget->setObjectName(QString::fromUtf8("colorwidget"));
        colorwidget->setGeometry(QRect(180, 150, 120, 80));
        colorwidget->setStyleSheet(QString::fromUtf8("QWidget{ background-color: blue}\n"
"\n"
""));
        opacitywidget = new QWidget(Widget);
        opacitywidget->setObjectName(QString::fromUtf8("opacitywidget"));
        opacitywidget->setGeometry(QRect(180, 240, 120, 80));
        opacitywidget->setStyleSheet(QString::fromUtf8("QWidget{ background-color: black}\n"
"\n"
""));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(610, 140, 161, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QApplication::translate("Widget", "geometric animation", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "color animation", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "opacity animation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
