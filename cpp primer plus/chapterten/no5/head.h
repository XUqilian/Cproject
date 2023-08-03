#ifndef HEAD_H
#define HEAD_H

struct customer
{
    char fullname[35];
    double payment;
};

class stack  
{
private:
    static const int Len = 10; //栈能承载的结构个数
    customer st[Len];          //栈大小
    customer *tail=st;            //栈顶位置
    double sum=0;
public:
    //stack(){}; //该类无需进行初始化，不给其添加构造函数和析构函数，由编译器自行添加
    //~stack(){};

    // add customer to stack
    int add(customer &);
    // remove customer in stack
    int remove();
    // whether the stack is empty  //栈是否是空的
    int isempty()const;
    // whether the stack is full  //栈是否是满的
    int isfull()const;
};

#endif