#ifndef HEAD_H
#define HEAD_H

// typedef int T;
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

template<class T>
class Stack
{
    private:
        T * arr; // 栈位置指针
        const int cnt; // 栈大小
        int top; // 栈顶
    public:
        T temp;  // 临时变量 为方便临时赋值使用 兼容性和模块性更强
        //如果为保证数据安全可限制为保护或私有 但需为其提供修改使用的成员函数
    public:
        explicit Stack(int s = 5);
        ~Stack()
        {
            delete[]arr;
            delete[] temp;            错误tips error code: go to line 45
        };
        bool push(T &);
        bool pop();
        bool isfull()const;
        bool isempty()const;

};

template<class T>           // 函数需要模板限定
Stack<T>::Stack(int s )     //还需要添加类型限定
:cnt(s)   // const 初始化固定大小
{
    arr = new T[cnt];
    top = 0;
    // temp = arr[0]; 会破坏栈数据 结合push代码会破坏
    // temp = new T[];  //这个实现出现了问题
    // temp = new T;  // 也不行
   temp = new T[1]; //还是有问题
}

template<class T>
bool Stack<T>::push(T & t)
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

template<class T>
bool Stack<T>::pop()
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

template<class T>
bool Stack<T>::isfull()const
{
    // if(arr[cnt-1])return true;
    if(top == cnt)return true;
    else return false;
}
template<class T>
bool Stack<T>::isempty()const
{
    if(0 == top)return true;
    else return false;
}

#endif