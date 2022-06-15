#include"head.h"

    move::move(double a, double b)
    {
        x=a;
        y=b;
    } // constructor

    void move::show() const
    {
        printf("x=%f\ty=%f",x,y);
    }                // show x ,y value

    void move::reset(double a, double b)
    {
        x=a;
        y=b;
    } // reset x y to a b

    move move::add(const move &temp) const
    {
        return  move{temp.x,temp.y};

    }
    //函数将创建一个临时结构对象，并用传入的对象实例来初始化，函数返回值为创建的对象实例

//question：出现有函数从堆上分配时怎么定义其内容，对类对象怎么确定是不是从堆上分配空间创建的对象呢？正常走构造函数就不需要delete了;