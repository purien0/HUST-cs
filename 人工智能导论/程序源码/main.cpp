#include "widget.h"
#include "Head.h"
#include "dialog.h"
int open_num,closed_num;
int path_length;
struct PATH Path[362881];
unsigned char visit[362881];
char p[362881];
int op;//记录当前选择的启发函数类型（1到3）
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.dia.exec();
    w.set();
    w.show();
    return a.exec();
}
