#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>
using std::cin;
using std::cout;
using std::endl;



class Pp
{
    private:
        long intimes;
        int outimes;
    public:
        Pp(){intimes = outimes = 0;}

        void set(long t)
        {
            srand((unsigned)time(NULL));
            intimes = t;
            outimes = (rand()% 3) + 1;
            
        }
        int valin()const {return intimes;}
        int valout()const {return outimes;}
};

typedef Pp item;

class Fifo{
    private:
        struct sttf{
            item itm;
            sttf * next;
        };

    private:
        sttf * front;
        sttf * real;
        int num;
        const int cnt;
        // const int cnt = 0;  // 这一步可以直接减少外部的成员初始化 但外部初始化还是会覆盖本次赋值 
        // 类只有静态的数据和成员函数是构造前就存在的 存储于静态区域  而剩下的都是再构造时初始化 
        // 就等于创建对象时初始化 而成员初始化是存在于函数参数括号后花括号前  就等于会先执行 也就造就了成员初始化这一特性 先于构造函数的初始化   赋值
    private:
        Fifo(const Fifo &):cnt(0){}
        Fifo operator=(const Fifo &){ return *this;}
        // 在这里将赋值和复制构造设置为私有 可以使主程序无法显式调用 就等于限制了 复制和赋值操作
        // 但类对象作为函数参数或者引用传递时依旧不受影响
    public:
        Fifo(int n):cnt(n) 
        {
            num = 0;
            front = real = NULL;
        }
        ~Fifo();
        bool isfull(){ return num == cnt;}
        bool isempty(){return num == 0;}
        int add();
        int del();
        int valcnt(){return num;}

};


#endif