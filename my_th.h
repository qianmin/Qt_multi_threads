#ifndef MY_TH_H
#define MY_TH_H

#include <QMainWindow>

class my_qth
{
public:
    int img=0;
    int result1;
    int result2;
    int f1_end_flag=0;
    int f2_end_flag=0;
    void f1();
    void f2();
    void star1();//多线程启动函数，在原有的代码基础上增加该函数
    void star2();//多线程启动函数，在原有的代码基础上增加该函数
    void star_all();
};

#endif // MY_TH_H
