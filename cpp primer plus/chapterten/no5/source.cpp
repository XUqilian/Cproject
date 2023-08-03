#include "head.h"
#include<stdio.h>

// add customer to stack
int stack::add(customer &temp)
{
    if(isfull())
    {
        int i = 0;
        for(;temp.fullname[i]!='\0';i++)
        {
            tail->fullname[i]=temp.fullname[i];
        }
        tail->fullname[i]='\0';
        tail++; //指向st数组下一位置
    }
    else
    {
        printf("stack is full!\n");
        return 1;
    }    
}
// remove customer in stack
int stack::remove()
{
    if(isempty())
    {
        tail--;  //覆盖式使用
        tail->fullname[0]='\0';
        printf("the stack dispose customer payment sum:%f\n",sum+=tail->payment);
        tail->payment=0;
        //也可以再加一个返回函数让调用者自行统计
        //或者这个函数返回就是payment值让调用者自行统计
    }
    else
    {
        printf("stack is empty!\n");
        return 1;
    } 
    return 0;
}
// whether the stack is empty  //栈是否是空的
int stack::isempty() const
{
    if (tail == st)
        return 0;
    else
        return 1;
}
// whether the stack is full  //栈是否是满的
int stack::isfull() const
{
    if (tail == &st[Len])  //指针已经指出数组范围，需注意使用,
    //或许用const限定它不能更改指向内容是更好的选择
        return 0;
    else
        return 1;
}