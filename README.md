# Qt_multi_threads
Qt最简单的多线程，开启了两个完全独立的子线程，主线程睡眠都不影响。
# 1依赖
```
QT += concurrent
#include<QtConcurrent> //要记得添加该头文件
```
# 2:用法
①类声明
```
class my_qth
{
public:
    int img=0;
    int result1;
    int result2;
    void f1();
    void f2();
    void star1();//要做的耗时间函数1
    void star2();//要做的耗时间函数2
    void star_all();
};
```
②类函数实现
```
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
```

```
void my_qth::star1()
{
    QtConcurrent::run(this,&my_qth::f1);//启动开始做分f1
}
```
③main使用
```
int main(int argc, char *argv[])
{
    my_qth w;
    qDebug()<<"main_id___###"<<QThread::currentThreadId();
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
```
```
查看线程id的方法
#include <QThread>
qDebug()<<"main_id___###"<<QThread::currentThreadId();
```
