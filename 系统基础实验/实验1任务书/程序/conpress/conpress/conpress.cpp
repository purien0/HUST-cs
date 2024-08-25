#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
#define N 5
#define N1 2
#define N2 3
struct student {
    char  name[8];
    short  age;//2字节，压缩为1字节
    float  score;//4字节
    char  remark[200];  // 备注信息
};
/*以下为输入内容，程序运行后复制以下内容输入即可
tql
19
42
cs2208
hanabi
18
99.6
a
purein
19
86.3
b
npc3
19
64.8
c
npc4
15
59.9
d
*/
struct student old_s[N], new_s[N];
int  pack_student_bytebybyte(student* s, int sno, char* buf)
{
    int cnt = 0;//计数压缩后字节数
    char* p;
    for (int i = 0; i < sno; i++){
        p = (char*)s[i].name;
        for (int i = 0; i < 8; i++) {
            if (*p) {
                *(buf++) = *(p++);//只储存有非0字符，并假设最后一个非零字符后全为0
            }
            else {
                *(buf++) = 0;//用'\0'或0来标志字符串的结束
                break;
            }
            cnt++;
        }

        p = (char*)&s[i].age;//小端存储，现在指向低位
        *(buf++) = *(p++);//存低位，舍弃高位
        cnt++;

        p = (char*)&s[i].score;//小段法的表示[DDDDDDDD] [DDDDDDDD] [EDDDDDDD] [SEEEEEEE]
        for (int i = 0; i < 4; i++) {
            *(buf++) = *(p++);
        }
        cnt += 4;

        p = (char*)s[i].remark;
        for (int i = 0; i < 200; i++) {
            if (*p) {
                *(buf++) = *(p++);//只储存有非0字符，并假设最后一个非零字符后全为0
            }
            else {
                *(buf++) = 0;//用'\0'或0来标志字符串的结束
                break;
            }
            cnt++;
        }
    }
    return cnt;
}
int  pack_student_whole(student* s, int sno, char* buf)
{
    int cnt = 0;
    char* p;
    for (int i = 0; i < sno; i++) {
        //name[8]
        p = (char*)s[i].name;
        strcpy(buf+cnt, p);
        cnt += strlen(p)+1;//strlen()不计入结尾的'/0'
        //age
        p = (char*)&s[i].age;
        *(buf + cnt) = *p;
        cnt++;
        //score
        p = (char*)&s[i].score;
        memcpy(buf + cnt, p, sizeof(float));
        cnt += 4;
        //remark
        p = (char*)s[i].remark;
        strcpy(buf + cnt, p);
        cnt += strlen(p) + 1;
    }
    return cnt;
}
int restore_student(char* buf, int len, student* s)
{
    int cnt = 0;
    int i = 0;
    while ( i < len){
        strcpy(s[cnt].name, buf + i);
        i += strlen(buf + i)+1;
        
        s[cnt].age = *(buf + i);
        i++;
        memcpy((char*)&s[cnt].score, buf + i, sizeof(float));
        i += sizeof(float);
        strcpy(s[cnt].remark, buf + i);
        i += strlen(buf + i) + 1;
        cnt++;
    }
    return cnt;
}
int main()
{
    int before_cnt = 0, after_cnt = 0;
    char message[N * sizeof(struct student)];
    for (int i = 0; i < N; i++)
    {//输入
        printf("name:");
        scanf("%s", old_s[i].name);
        getchar();
        printf("age:");
        scanf("%hd", &old_s[i].age);
        getchar();
        printf("score:");
        scanf("%f", &old_s[i].score);
        getchar();
        printf("remark:");
        scanf("%s", old_s[i].remark);
        getchar();
    }
    printf("压缩前的内容如下:\n");
    for (int i = 0; i < N; i++)
    {
        printf("student %d\nname:%s\nage:%hd\nscore:%f\nremark:%s\n\n",i+1,old_s[i].name, old_s[i].age, old_s[i].score, old_s[i].remark);
    }
    before_cnt = sizeof(old_s);
    after_cnt = pack_student_bytebybyte(&old_s[0], N1, message);
    after_cnt += pack_student_whole(&old_s[N1], N2, &message[after_cnt]);
    restore_student(message, after_cnt, new_s);
    printf("压缩后的内容如下:\n");
    for (int i = 0; i < N; i++)
    {
        printf("student %d\nname:%s\nage:%hd\nscore:%f\nremark:%s\n\n", i + 1, old_s[i].name, old_s[i].age, old_s[i].score, old_s[i].remark);
    }
    printf("压缩前存放数据长度:%d\n压缩后存放数据长度:%d\n", before_cnt, after_cnt);
    printf("输出message的前20个字节内容：");
    for (int i = 0; i < 20; i++)
        printf("%x", message[i]);
    return 0;
}
