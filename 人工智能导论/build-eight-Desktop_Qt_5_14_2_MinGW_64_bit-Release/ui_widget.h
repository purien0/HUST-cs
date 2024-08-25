/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QLabel *openNum;
    QPlainTextEdit *OPENNUM;
    QGraphicsView *graphicsView;
    QPlainTextEdit *f1;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QLabel *ClosedNum;
    QPlainTextEdit *CLOSEDNUM;
    QGraphicsView *graphicsView_2;
    QPlainTextEdit *f2;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QSpinBox *StepNum;
    QPushButton *searchTree;
    QPushButton *reset;
    QPushButton *reelect;
    QGroupBox *groupBox_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *t1;
    QLabel *l1;
    QLabel *o1;
    QLabel *c1;
    QLabel *t2;
    QLabel *o2;
    QLabel *l3;
    QLabel *o3;
    QLabel *t3;
    QLabel *c3;
    QLabel *l2;
    QLabel *c2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(652, 323);
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 10, 111, 21));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 111, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        label->setFont(font);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 70, 75, 23));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 100, 75, 23));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 130, 151, 23));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(270, 20, 351, 291));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 10, 121, 271));
        openNum = new QLabel(groupBox);
        openNum->setObjectName(QString::fromUtf8("openNum"));
        openNum->setGeometry(QRect(10, 10, 91, 16));
        OPENNUM = new QPlainTextEdit(groupBox);
        OPENNUM->setObjectName(QString::fromUtf8("OPENNUM"));
        OPENNUM->setGeometry(QRect(10, 30, 104, 31));
        graphicsView = new QGraphicsView(groupBox);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 90, 111, 111));
        f1 = new QPlainTextEdit(groupBox);
        f1->setObjectName(QString::fromUtf8("f1"));
        f1->setGeometry(QRect(10, 230, 104, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 70, 54, 12));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 210, 91, 20));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 10, 121, 271));
        ClosedNum = new QLabel(groupBox_2);
        ClosedNum->setObjectName(QString::fromUtf8("ClosedNum"));
        ClosedNum->setGeometry(QRect(10, 10, 91, 16));
        CLOSEDNUM = new QPlainTextEdit(groupBox_2);
        CLOSEDNUM->setObjectName(QString::fromUtf8("CLOSEDNUM"));
        CLOSEDNUM->setGeometry(QRect(10, 30, 104, 31));
        graphicsView_2 = new QGraphicsView(groupBox_2);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 90, 111, 111));
        f2 = new QPlainTextEdit(groupBox_2);
        f2->setObjectName(QString::fromUtf8("f2"));
        f2->setGeometry(QRect(10, 230, 104, 31));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 70, 54, 12));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 210, 91, 20));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 250, 54, 12));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 54, 12));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 40, 75, 23));
        StepNum = new QSpinBox(Widget);
        StepNum->setObjectName(QString::fromUtf8("StepNum"));
        StepNum->setGeometry(QRect(20, 100, 42, 22));
        searchTree = new QPushButton(Widget);
        searchTree->setObjectName(QString::fromUtf8("searchTree"));
        searchTree->setGeometry(QRect(150, 70, 75, 23));
        reset = new QPushButton(Widget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(140, 40, 111, 23));
        reelect = new QPushButton(Widget);
        reelect->setObjectName(QString::fromUtf8("reelect"));
        reelect->setGeometry(QRect(20, 280, 121, 23));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 150, 251, 134));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 40, 21, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 80, 16, 16));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 110, 16, 16));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(130, 20, 42, 16));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(190, 20, 48, 16));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 20, 51, 16));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(80, 20, 36, 16));
        t1 = new QLabel(groupBox_4);
        t1->setObjectName(QString::fromUtf8("t1"));
        t1->setGeometry(QRect(30, 40, 61, 16));
        l1 = new QLabel(groupBox_4);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(90, 40, 21, 16));
        o1 = new QLabel(groupBox_4);
        o1->setObjectName(QString::fromUtf8("o1"));
        o1->setGeometry(QRect(140, 40, 31, 16));
        c1 = new QLabel(groupBox_4);
        c1->setObjectName(QString::fromUtf8("c1"));
        c1->setGeometry(QRect(200, 40, 31, 16));
        t2 = new QLabel(groupBox_4);
        t2->setObjectName(QString::fromUtf8("t2"));
        t2->setGeometry(QRect(30, 80, 51, 16));
        o2 = new QLabel(groupBox_4);
        o2->setObjectName(QString::fromUtf8("o2"));
        o2->setGeometry(QRect(140, 80, 31, 16));
        l3 = new QLabel(groupBox_4);
        l3->setObjectName(QString::fromUtf8("l3"));
        l3->setGeometry(QRect(90, 110, 21, 16));
        o3 = new QLabel(groupBox_4);
        o3->setObjectName(QString::fromUtf8("o3"));
        o3->setGeometry(QRect(140, 110, 31, 16));
        t3 = new QLabel(groupBox_4);
        t3->setObjectName(QString::fromUtf8("t3"));
        t3->setGeometry(QRect(30, 110, 61, 16));
        c3 = new QLabel(groupBox_4);
        c3->setObjectName(QString::fromUtf8("c3"));
        c3->setGeometry(QRect(200, 110, 31, 16));
        l2 = new QLabel(groupBox_4);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setGeometry(QRect(90, 80, 21, 16));
        c2 = new QLabel(groupBox_4);
        c2->setObjectName(QString::fromUtf8("c2"));
        c2->setGeometry(QRect(200, 80, 31, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\220\257\345\217\221\345\207\275\346\225\260\347\261\273\345\236\213\357\274\232</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\220\257\345\217\221\345\207\275\346\225\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\215\225\346\255\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\244\232\346\255\245", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\350\277\236\347\273\255\346\211\247\350\241\214\350\207\263\346\261\202\350\247\243\345\207\272\347\255\224\346\241\210", nullptr));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        openNum->setText(QCoreApplication::translate("Widget", "OPEN LIST NUM:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\267\261\345\272\246+\345\220\257\345\217\221\345\207\275\346\225\260\345\200\274", nullptr));
        groupBox_2->setTitle(QString());
        ClosedNum->setText(QCoreApplication::translate("Widget", "CLOSED LIST NUM:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\347\212\266\346\200\201\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\346\267\261\345\272\246+\345\220\257\345\217\221\345\207\275\346\225\260\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "f\357\274\232", nullptr));
        label_2->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Widget", "\351\232\217\346\234\272\345\210\235\345\247\213\345\214\226", nullptr));
        searchTree->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\220\234\347\264\242\346\240\221", nullptr));
        reset->setText(QCoreApplication::translate("Widget", "\345\233\236\345\210\260\345\210\235\345\247\213\345\214\226\345\220\216\347\212\266\346\200\201", nullptr));
        reelect->setText(QCoreApplication::translate("Widget", "\351\207\215\351\200\211\345\220\257\345\217\221\345\207\275\346\225\260", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "\345\210\206\346\236\220", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "1", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "2", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "3", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "opennum", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "closenum", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "time/ms", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "length", nullptr));
        t1->setText(QCoreApplication::translate("Widget", "0", nullptr));
        l1->setText(QCoreApplication::translate("Widget", "0", nullptr));
        o1->setText(QCoreApplication::translate("Widget", "0", nullptr));
        c1->setText(QCoreApplication::translate("Widget", "0", nullptr));
        t2->setText(QCoreApplication::translate("Widget", "0", nullptr));
        o2->setText(QCoreApplication::translate("Widget", "0", nullptr));
        l3->setText(QCoreApplication::translate("Widget", "0", nullptr));
        o3->setText(QCoreApplication::translate("Widget", "0", nullptr));
        t3->setText(QCoreApplication::translate("Widget", "0", nullptr));
        c3->setText(QCoreApplication::translate("Widget", "0", nullptr));
        l2->setText(QCoreApplication::translate("Widget", "0", nullptr));
        c2->setText(QCoreApplication::translate("Widget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
