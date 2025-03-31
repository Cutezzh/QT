/********************************************************************************
** Form generated from reading UI file 'file_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_DIALOG_H
#define UI_FILE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_File_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *File_Dialog)
    {
        if (File_Dialog->objectName().isEmpty())
            File_Dialog->setObjectName(QString::fromUtf8("File_Dialog"));
        File_Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(File_Dialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(File_Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(65, 30));
        pushButton->setMaximumSize(QSize(65, 30));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{ border: none; color: #ff862a}\n"
"QPushButton:pressed{ color: #ffba1a}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/back_press.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(File_Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(File_Dialog);

        QMetaObject::connectSlotsByName(File_Dialog);
    } // setupUi

    void retranslateUi(QDialog *File_Dialog)
    {
        File_Dialog->setWindowTitle(QApplication::translate("File_Dialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("File_Dialog", "Text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class File_Dialog: public Ui_File_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_DIALOG_H
