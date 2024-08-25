/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *time;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *length;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QString::fromUtf8("Dialog2"));
        Dialog2->resize(357, 211);
        buttonBox = new QDialogButtonBox(Dialog2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        time = new QPlainTextEdit(Dialog2);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(130, 70, 104, 31));
        label = new QLabel(Dialog2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 40, 181, 16));
        label_2 = new QLabel(Dialog2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 80, 54, 12));
        label_3 = new QLabel(Dialog2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 150, 231, 16));
        label_4 = new QLabel(Dialog2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 110, 54, 12));
        label_5 = new QLabel(Dialog2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 70, 54, 12));
        length = new QTextBrowser(Dialog2);
        length->setObjectName(QString::fromUtf8("length"));
        length->setGeometry(QRect(130, 110, 111, 31));

        retranslateUi(Dialog2);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog2, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Dialog", nullptr));
        time->setPlainText(QCoreApplication::translate("Dialog2", "999.99", nullptr));
        label->setText(QCoreApplication::translate("Dialog2", "\345\267\262\346\210\220\345\212\237\350\247\243\345\207\272\347\273\223\346\236\234", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog2", "ms", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog2", "\346\214\211OK\345\260\206\347\224\237\346\210\220\346\220\234\347\264\242\346\240\221\357\274\214\346\214\211Cancel\345\210\231\344\270\215\347\224\237\346\210\220", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog2", "\350\267\257\345\276\204\351\225\277\345\272\246\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog2", "\347\224\250\346\227\266:", nullptr));
        length->setHtml(QCoreApplication::translate("Dialog2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">99</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
