/********************************************************************************
** Form generated from reading UI file 'waitingdia.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGDIA_H
#define UI_WAITINGDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_waitingDia
{
public:
    QLabel *label;

    void setupUi(QDialog *waitingDia)
    {
        if (waitingDia->objectName().isEmpty())
            waitingDia->setObjectName(QString::fromUtf8("waitingDia"));
        waitingDia->resize(215, 96);
        label = new QLabel(waitingDia);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 141, 51));

        retranslateUi(waitingDia);

        QMetaObject::connectSlotsByName(waitingDia);
    } // setupUi

    void retranslateUi(QDialog *waitingDia)
    {
        waitingDia->setWindowTitle(QCoreApplication::translate("waitingDia", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("waitingDia", "<html><head/><body><p><span style=\" font-size:28pt;\">\350\257\267\347\255\211\345\276\205......</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class waitingDia: public Ui_waitingDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGDIA_H
