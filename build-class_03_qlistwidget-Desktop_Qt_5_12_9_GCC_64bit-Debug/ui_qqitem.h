/********************************************************************************
** Form generated from reading UI file 'qqitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQITEM_H
#define UI_QQITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQItem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QLabel *picture;
    QLabel *phone;
    QSpacerItem *horizontalSpacer_3;
    QLabel *name;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *QQItem)
    {
        if (QQItem->objectName().isEmpty())
            QQItem->setObjectName(QString::fromUtf8("QQItem"));
        QQItem->resize(350, 65);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QQItem->sizePolicy().hasHeightForWidth());
        QQItem->setSizePolicy(sizePolicy);
        QQItem->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(QQItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 351, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(48, 48));
        widget->setMaximumSize(QSize(48, 48));
        widget->setStyleSheet(QString::fromUtf8("QWidget{ background-color: darkgrey}"));
        picture = new QLabel(widget);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(0, 0, 48, 48));
        picture->setMinimumSize(QSize(48, 48));
        picture->setMaximumSize(QSize(48, 48));
        picture->setStyleSheet(QString::fromUtf8("QLabel{ background-color: darkgrey}"));
        phone = new QLabel(widget);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setGeometry(QRect(20, 20, 25, 25));
        phone->setMinimumSize(QSize(25, 25));
        phone->setMaximumSize(QSize(25, 25));
        phone->setStyleSheet(QString::fromUtf8("QLabel{ background:transparent}"));

        horizontalLayout->addWidget(widget);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        name = new QLabel(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(150, 30));
        name->setMaximumSize(QSize(150, 30));
        name->setStyleSheet(QString::fromUtf8("QLabel{ color: darkgrey; font-size: 20px}"));

        horizontalLayout->addWidget(name);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(QQItem);

        QMetaObject::connectSlotsByName(QQItem);
    } // setupUi

    void retranslateUi(QWidget *QQItem)
    {
        QQItem->setWindowTitle(QApplication::translate("QQItem", "Form", nullptr));
        picture->setText(QString());
        phone->setText(QString());
        name->setText(QApplication::translate("QQItem", "default name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QQItem: public Ui_QQItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQITEM_H
