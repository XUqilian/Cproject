#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>

class Savers // Savers  储户
{
private:
    char name[20];
    char account[20]; // account  账户
    double money;

public:
    Savers()
    {
        account[0] = '\0';
        name[0] = '\0';
        money = 0;
    };
    // Savers()；  构造函数必须加大括号才能成为函数，要不然只是一个调用 也可以用Savers(){};
    Savers(const char *accounts, const char *names = "\0", double moneys = 0);
    // Savers(const char *accounts, const char *names = "\0", double moneys = 0);
    // c++c++可以在类的声明中，也可以在函数定义中声明缺省参数，但不能既在类声明中又在函数定义中同时声明缺省参数。
    //因此，将定义或声明中的任一个缺省参数删除即可。
    ~Savers(){};
    //在头文件指定默认参数，要不然主程序会无法识别有默认参数的函数，因为它只引入头文件
    void deposit(double moneys = 0); // deposit  存入
    void remove(double moneys = 0);  // remove   取出
    void display() const;
    // void Savers::display() const;  在类内就不能加这个类标签了
    // error: extra qualification 'Savers::' on member 'display'  成员身上有额外的标签
};

#endif
