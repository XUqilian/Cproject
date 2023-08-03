#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>

class move
{
private:
    double x;
    double y;

public:
    move(double a = 0, double b = 0); // constructor
    ~move(){};  //destructor
    void show() const; // show x ,y value
    move add(const move &temp) const;
    //函数将创建一个新结构对象，并用传入的对象实例来初始化，函数返回值为创建的新对象实例
    void reset(double a = 0, double b = 0); // reset x y to a b
};

#endif