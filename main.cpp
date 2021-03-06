#include "my_th.h"
#include <QApplication>
#include<QTime>
#include<QDebug>
#include<iostream>
#include <QThread>
#include <windows.h>

using namespace std;
int main(int argc, char *argv[])
{
    my_qth w;
    qDebug()<<"main_id___###"<<QThread::currentThreadId();
//    t1.start();
//    w.star1();

//    qDebug()<<t1.elapsed()/1000.0<<"s";

//    t2.start();
//    w.star2();
//    qDebug()<<t2.elapsed()/1000.0<<"s";
    qDebug()<<"i am main thread";
    w.star_all();
    while(1)
    {
        if(w.f1_end_flag==1)
        {
            qDebug()<<"w.result1"<<w.result1;
        }
        if(w.f2_end_flag==1)
        {
            qDebug()<<"w.result2"<<w.result2;
        }
        if((w.f1_end_flag==1)&&(w.f2_end_flag==1))
        {
            break;
        }
    }

    qDebug()<<w.result1<<w.result2;
}
