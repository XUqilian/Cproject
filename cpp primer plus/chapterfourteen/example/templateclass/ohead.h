#ifndef HEAD_H
#define HEAD_H

typedef int T;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
class Stack
{
    private:
        T * arr; // 栈位置指针
        const int cnt; // 栈大小
        int top; // 栈顶
    public:
        Stack(int s );
        ~Stack(){delete[]arr;};
        bool push(T &);
        bool pop();
        bool isfull();
        bool isempty();

};


Stack::Stack(int s )
:cnt(s)   // const 初始化固定大小
{
    arr = new T[cnt];
    top = 0;
}

bool Stack::push(T & t)
{
    if(!isfull())
    {
        arr[top] = t;
        top++ ; 
        cout << t << "is push!" << endl;
        return true;
    }else{
        cout << "stack is full" << endl;
        return false;
    }
}
bool Stack::pop()
{
    if(!isempty())
    {
        // arr[top] = 0;
        top--;
        cout << arr[top] << "is pop" << endl;
        return true;
    }else{
        cout << "stack is empty" << endl;
        return false; 
    } 
}
bool Stack::isfull()
{
    // if(arr[cnt-1])return true;
    if(top == cnt)return true;
    else return false;
}
bool Stack::isempty()
{
    if(0 == top)return true;
    else return false;
}

#endif