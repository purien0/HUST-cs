#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int op;

private slots:
    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_buttonBox_accepted();
    void sendSignal(QString msg);

    void on_radioButton_3_clicked(bool checked);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
