#include "dialog.h"
#include "ui_dialog.h"
#include "Head.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_radioButton_clicked(bool checked)
{
    if(checked)
    op = 1;
}

void Dialog::on_radioButton_2_clicked(bool checked)
{
    if(checked)
    op = 2;
}

void Dialog::on_buttonBox_accepted()
{
    if(!op)
    {
        op = 1;
        //this->exec();
     }
}

void Dialog::sendSignal(QString msg)
{
    return;
}

void Dialog::on_radioButton_3_clicked(bool checked)
{
    if(checked)
    op = 3;
}
