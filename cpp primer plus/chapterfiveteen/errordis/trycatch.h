#ifndef TRYCATCH_H
#define TRYCATCH_H

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class erone
{
    public:
        double a;
        double b;

        erone(double x,double y):a(x),b(y){}
        void edis();
};

void erone::edis()
{
    cout << " error for argment a = -b " << "a:" << a << "b:" << b << endl;     // 内部参数可调用
}

class ertwo
{
    public:
        double a;
        double b;

        ertwo(double x,double y):a(x),b(y){}
        const char * edis();
};

const char * ertwo::edis()
{
    return "error for a < b";
}

#endif