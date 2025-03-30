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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 480);
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(150, 0, 650, 480));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(650, 480));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{width:20px;background: white }\n"
"QScrollBar::handle:vertical {background: rgba(200, 200, 200, 50%);border-radius:10px }\n"
"QScrollBar::handle:vertical:hover {background: rgba(200, 200, 200, 90%) }\n"
"QScrollBar::add-line:vertical {width: 0px; height: 0px }\n"
"QScrollBar::sub-line:vertical {width: 0px; height: 0px }"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -90, 800, 600));
        scrollAreaWidgetContents->setMinimumSize(QSize(800, 600));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget{background: white}"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
