#include "waitingdia.h"
#include "ui_waitingdia.h"

waitingDia::waitingDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waitingDia)
{
    ui->setupUi(this);
}

waitingDia::~waitingDia()
{
    delete ui;
}
