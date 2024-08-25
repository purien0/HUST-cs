#include "widget.h"
#include "ui_widget.h"
#include "Head.h"
#include "dialog2.h"
#include "ui_dialog2.h"
int d[4] = {-1,1,-3,3};
char di[4] = {'l','r','u','d'};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
const int tar = 46234;//目标康托值
Widget::Widget(QWidget *parent)
    : QWidget(parent),dia(parent),dia2(parent),op(dia.op),scene(),view(&scene)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene.setBackgroundBrush(Qt::white);
    scene.setSceneRect(QRectF(0,0,INT_MAX,INT_MAX));
    view.resize(1000,1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::set()
{
    QString s;
    switch(op)
    {
    case 1:
        s=QString("not at the right position");
        break;
    case 2:
        s=QString("mamhatun");
        break;
    case 3:
        s =QString("linear conflict");
        break;
    default:
        s = QString("error");
    }
    ui->label->setText(s);
}

void Widget::display(int op,int c,int dis,int f)
{
    char state[9];
    incontor(state,c);
    QString str;
    if(op==1)
    ui->f1->setPlainText(QString::number(dis)+'+'+QString::number(f));
    else if(op==2)
    ui->f2->setPlainText(QString::number(dis)+'+'+QString::number(f));
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setBackgroundBrush(Qt::white);
    QPointF p[9] ;
    p[0].setX(-33),
    p[0].setY(-33);
    p[1].setX(0),
    p[1].setY(-33);
    p[2].setX(33),
    p[2].setY(-33);
    p[3].setX(-33),
    p[3].setY(0);
    p[4].setX(0),
    p[4].setY(0);
    p[5].setX(33),
    p[5].setY(0);
    p[6].setX(-33),
    p[6].setY(33);
    p[7].setX(0),
    p[7].setY(33);
    p[8].setX(33),
    p[8].setY(33);
    QFont *font = new QFont;
    font->setPointSize(20);
    for(int i = 0; i < 9; i++)
    {
        QGraphicsTextItem * text = new QGraphicsTextItem;
        text->setPlainText(QString::number(state[i]));
        text->setPos(p[i]);
        text->setFont(*font);
        scene->addItem(text);
    }
    if(op==1)
    ui->graphicsView->setScene(scene);
    else ui->graphicsView_2->setScene(scene);

}

void Widget::showtree()
{
    scene.addPixmap(QPixmap("Tree.png"));
    view.setScene(&scene);
    //开始显示
    view.show();
}

int Widget::one_step()
{
    struct node temp;
    int now;
    int c;//contor
    int cc;
    int x,y;
    int f;
    int d[4] = {-1,1,-3,3};
    char di[4] = {'l','r','u','d'};
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    const int tar = 46234;//目标康托值
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        if(visit[temp.state] != CLOSED)
        {//队列中同时存在OPEN，将open list内结点移入CLOSED list
        visit[temp.state] = CLOSED;
        closed_num++;
        open_num--;
        break;
        }else continue;
    }
        char state[9];
        incontor(state,temp.state);
        cc = temp.state;
        now = temp.now;
        for(int i = 0; i < 4; i++)//四个方向左，右
        {
            x=now%3+dir[i][0];
            y=now/3+dir[i][1];
            if(x<0||x>2||y<0||y>2)
            continue;//越界
            swap(state[now+d[i]],state[now]);//交换位置
            c = Contor(state);//记录康托值
            swap(state[now+d[i]],state[now]);//换回来
            if(visit[c]==CLOSED)//已经进入CLOSED则不再入队
            continue;
            switch(op)
            {//根据选用启发函数不同,更新启发函数的值
                case 1://不在正确位置的数量
                    if(state[now+d[i]]==now+d[i]+1)
                    f = temp.f+1;
                    else if(state[now+d[i]]==now+1)
                    f = temp.f-1;
                    else f = temp.f;
                    break;
                case 2://曼哈顿距离
                    f = temp.f - Mdis(x,y,state[now+d[i]]-1) + Mdis(now%3,now/3,state[now+d[i]]-1);
                    break;
                case 3://linear_conflict
                     f = temp.f - Mdis(x,y,state[now+d[i]]-1) + Mdis(now%3,now/3,state[now+d[i]]-1)-linear_conflict(cc)+linear_conflict(c);//dis更新
                     break;
                default:
                    printf("error!\n");
                    return 1;
            }
            Path[c].dis = temp.dis+1;
            Path[c].f = f;
            Path[c].k = cc;//上一个
            if(c==tar)
            {
                int j = 0;
                for(int i = c;i;i = Path[i].k)
                {
                    visit[i]=ANS;
                    p[j++] = di[Path[i].op];
                }
                path_length = j-1;
                for(int i = path_length-1; i >= 0; i--)
                {
                    printf("%c", p[i]);//输出路径
                 }
                printf("\n");
                ui->OPENNUM->setPlainText(QString::number(open_num));
                ui->CLOSEDNUM->setPlainText(QString::number(closed_num));
                display(1,c,temp.dis+1,f);
                display(2,cc,temp.dis,temp.f);
                return 1;
            }
            q.push({temp.dis+1,f,now+d[i],c});
            if(!visit[c])
            {
                visit[c]=OPEN;
                open_num++;
            }
        }
        ui->OPENNUM->setPlainText(QString::number(open_num));
        ui->CLOSEDNUM->setPlainText(QString::number(closed_num));
        display(2,cc,temp.dis,temp.f);
        temp = q.top();
        display(1,temp.state,temp.dis,temp.f);
        return 0;
}
void Widget::recvSignal(QString data)
{
    ui->label->setText(data);
}


void Widget::on_pushButton_clicked()
{
    //单步执行
    if(one_step())
    {
        dia2.ui->time->setPlainText(QString::number(0)+".000");
        dia2.ui->length->setPlainText(QString::number(path_length));
        dia2.exec();
    }
}

void Widget::on_pushButton_3_clicked()
{//连续执行至解出答案并输出时间
    LARGE_INTEGER start,finish,tc;
    struct node temp;
    int now;
    int c;//contor
    int cc;
    int x,y;
    int f;
    int d[4] = {-1,1,-3,3};
    char di[4] = {'l','r','u','d'};
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    const int tar = 46234;//目标康托值
    int flag = 0;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&start);
    while(!q.empty()&&!flag)
    {
        temp = q.top();
        q.pop();
        if(visit[temp.state] != CLOSED)
        {//队列中同时存在OPEN，将open list内结点移入CLOSED list
            visit[temp.state] = CLOSED;
            closed_num++;
            open_num--;
        }else continue;
        char state[9];
        incontor(state,temp.state);
        cc = temp.state;
        now = temp.now;
        for(int i = 0; i < 4; i++)//四个方向左，右
        {
            x=now%3+dir[i][0];
            y=now/3+dir[i][1];
            if(x<0||x>2||y<0||y>2)
            continue;//越界
            swap(state[now+d[i]],state[now]);//交换位置
            c = Contor(state);//记录康托值
            swap(state[now+d[i]],state[now]);//换回来
            if(visit[c]==CLOSED)//已经进入CLOSED则不再入队
            continue;
            switch(op)
            {//根据选用启发函数不同,更新启发函数的值
                case 1://不在正确位置的数量
                    if(state[now+d[i]]==now+d[i]+1)
                    f = temp.f+1;
                    else if(state[now+d[i]]==now+1)
                    f = temp.f-1;
                    else f = temp.f;
                    break;
                case 2://曼哈顿距离
                    f = temp.f - Mdis(x,y,state[now+d[i]]-1) + Mdis(now%3,now/3,state[now+d[i]]-1);
                    break;
                case 3://linear_conflict
                     f = temp.f - Mdis(x,y,state[now+d[i]]-1) + Mdis(now%3,now/3,state[now+d[i]]-1)-linear_conflict(cc)+linear_conflict(c);//dis更新
                     break;
                default:
                    printf("error!\n");
                    return;
            }
            Path[c].dis = temp.dis+1;
            Path[c].f = f;
            Path[c].k = cc;//上一个
            if(c==tar)
            {
                int j = 0;
                for(int i = c;i;i = Path[i].k)
                {
                    visit[i]=ANS;
                    j++;
                }
                path_length = j-1;
                for(int i = path_length-1; i >= 0; i--)
                {
                    printf("%c", p[i]);//输出路径
                 }
                printf("\n");
                QueryPerformanceCounter(&finish);
                ui->OPENNUM->setPlainText(QString::number(open_num));
                ui->CLOSEDNUM->setPlainText(QString::number(closed_num));
                display(1,c,temp.dis+1,f);
                display(2,cc,temp.dis,temp.f);
                flag = 1;
            }
            q.push({temp.dis+1,f,now+d[i],c});
            if(!visit[c])
            {
                visit[c]=OPEN;
                open_num++;
            }
        }
     }
    double dur = (double)(finish.QuadPart-start.QuadPart)/(double)tc.QuadPart * 1000.0;
    dia2.ui->time->setPlainText(QString::number(dur));
    dia2.ui->length->setPlainText(QString::number(path_length));
    switch(op)
    {
        case 1:
            ui->t1->setText(QString::number(dur));
            ui->l1->setText(QString::number(path_length));
            ui->o1->setText(QString::number(open_num));
            ui->c1->setText(QString::number(closed_num));
            break;
        case 2:
            ui->t2->setText(QString::number(dur));
            ui->l2->setText(QString::number(path_length));
            ui->o2->setText(QString::number(open_num));
            ui->c2->setText(QString::number(closed_num));
            break;
        case 3:
            ui->t3->setText(QString::number(dur));
            ui->l3->setText(QString::number(path_length));
            ui->o3->setText(QString::number(open_num));
            ui->c3->setText(QString::number(closed_num));
            break;
    }
    dia2.exec();
}
void Widget::on_pushButton_4_clicked()
{//随机初始化
    int now;
    now = randomize(ori);//当前状态
    int f = 0;
    reset();
    switch(op)
    {
        case 1:
            for(int i = 0; i<9; i++)
            {//统计不在正确位置的个数
                if(ori[i]&&ori[i]!=i+1)
                f++;
            }
            break;
        case 3:
            f+=linear_conflict(Contor(ori));
        case 2:
            for(int i = 0; i < 9;i++)
            {
            if(ori[i])
            f += Mdis(i%3,i/3,ori[i]-1);
            }//算出最初的曼哈顿距离
            break;
        default:
            printf("error!\n");
            return;
      }
      q.push({0,f,now,Contor(ori)});
      Path[now].dis = 0;
      Path[now].f = f;
      Path[now].k = 0;
      display(1,Contor(ori),0,f);
      ui->OPENNUM->setPlainText(QString::number(open_num));
      ui->CLOSEDNUM->setPlainText(QString::number(closed_num));
      QGraphicsScene *scene2 = new QGraphicsScene;
      scene2->setBackgroundBrush(Qt::white);
      ui->graphicsView_2->setScene(scene2);
}


void Widget::on_pushButton_2_clicked()
{//多步
    int times = ui->StepNum->value();
    if(times < 0)
    return ;
    while(times--)
    {
        if(one_step())
        {
            dia2.ui->time->setPlainText(QString::number(0)+".000");
            dia2.ui->length->setPlainText(QString::number(path_length));
            dia2.exec();
        }
    }
}

void Widget::on_searchTree_clicked()
{
    showtree();
}

void Widget::on_pushButton_6_clicked()
{
    return;
}

void Widget::on_reelect_clicked()
{
    dia.exec();
    set();
    on_reset_clicked();
}

void Widget::on_reset_clicked()
{
    //ori没有改变
    int now = 0;
    for(int i = 0; i < 9; i++)
    {
        if(!ori[i])
        {
            now = i;
            break;
        }
    }
    int f = 0;
        reset();
        switch(op)
        {
        case 1:
            for(int i = 0; i<9; i++)
            {//统计不在正确位置的个数
                if(ori[i]&&ori[i]!=i+1)
                f++;
            }
            break;
        case 3:
            f+=linear_conflict(Contor(ori));
        case 2:
            for(int i = 0; i < 9;i++)
            {
            if(ori[i])
            f += Mdis(i%3,i/3,ori[i]-1);
            }//算出最初的曼哈顿距离
            break;
        default:
            printf("error!\n");
            return;
      }
      q.push({0,f,now,Contor(ori)});
      Path[now].dis = 0;
      Path[now].f = f;
      Path[now].k = 0;
      ui->OPENNUM->setPlainText(QString::number(open_num));
      ui->CLOSEDNUM->setPlainText(QString::number(closed_num));
      display(1,Contor(ori),0,f);
      QGraphicsScene *scene2 = new QGraphicsScene;
      scene2->setBackgroundBrush(Qt::white);
      ui->graphicsView_2->setScene(scene2);
      ui->f2->setPlainText("");
}
