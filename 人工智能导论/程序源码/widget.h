#include "dialog.h"
#include "dialog2.h"
#include "waitingdia.h"
#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Dialog dia;
    Dialog2 dia2;
    QGraphicsScene scene;
    QGraphicsView view;
    waitingDia wdia;
    int &op;
    char ori[9];
    void set();
    void display(int op,int c,int dis,int f);
    void showtree();
    int one_step();

private slots:
    void recvSignal(QString data);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();


    void on_searchTree_clicked();

    void on_pushButton_6_clicked();

    void on_reelect_clicked();

    void on_reset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
