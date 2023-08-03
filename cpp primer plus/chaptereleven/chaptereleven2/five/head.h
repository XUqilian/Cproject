#ifndef HEAD_H
#define HEAD_H

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Stone
{
    public:
        enum Mode{usep,uses};
    private:
        const int pts = 14;//pounds to stone and lpds
        double pounds;
        int stone;
        double lpds;
        Mode md = usep;
    public:
        Stone(){ pounds = lpds = stone = 0;}
        //Stone(double);
        explicit Stone(double);
        //explicit 用在构造函数前表示禁止构造函数进行显式转换
        //    Stone a;
        //a = 123.123564; //can use Stone(double ) init
        //当被 explicit 限制后 只能接受显示初始化 a = Stone(211.3);  a = (Stone)211.3;
        //这种转换只适用于仅有一个 "可赋值" 的参数时
        Stone(int ,double);
        ~Stone(){}

        void setshow(Mode t){md = t;}
        friend ostream & operator << (ostream & , Stone &);

        explicit operator double()const { return pounds;}   
        explicit operator int()const { return int (pounds);}   
        //转换函数 没有返回和参数 将类实例转换为指定类型值 类似于强制转换 调用方法和强制转换一致
        //可被 explicit 限制必须进行显式转换

        //int todouble(){return pounds;}
        //you can use it keep safe


};


#endif