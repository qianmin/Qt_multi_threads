#include "my_th.h"
#include<QDebug>
#include<QtConcurrent>//要记得添加该头文件
#include<iostream>
#include <QThread>
using namespace std;
void my_qth::f1()
{
    qDebug()<<"f1_id___###"<<QThread::currentThreadId();
    int tmp=img;
    qDebug()<<"f1_star_tmp"<<tmp;
    for(tmp;tmp<2000;tmp++)
    {
        tmp++;
        qDebug()<<1;
    }
    result1=tmp;
    f1_end_flag=1;
    qDebug()<<"f1_end##################################################";
}
void my_qth::f2()
{
    qDebug()<<"f2_id___###"<<QThread::currentThreadId();
    int tmp=img;
    qDebug()<<"f2_star_tmp"<<tmp;
    for(tmp;tmp<4000;tmp++)
    {
        tmp++;
        qDebug()<<2;
    }
    result2=tmp;
    f2_end_flag=1;
    qDebug()<<"f2_end##################################################";
}
void my_qth::star1()
{
    QtConcurrent::run(this,&my_qth::f1);//多线程执行死循环启动，可以带参数，具体格式可以查阅网上其它资料
}
void my_qth::star2()
{
    QtConcurrent::run(this,&my_qth::f2);//多线程执行死循环启动，可以带参数，具体格式可以查阅网上其它资料
}
void my_qth::star_all()
{
    star1();
    star2();
}
