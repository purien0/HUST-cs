#ifndef WAITINGDIA_H
#define WAITINGDIA_H

#include <QDialog>

namespace Ui {
class waitingDia;
}

class waitingDia : public QDialog
{
    Q_OBJECT

public:
    explicit waitingDia(QWidget *parent = nullptr);
    ~waitingDia();

private:
    Ui::waitingDia *ui;
};

#endif // WAITINGDIA_H
