#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

template<class T,int n = 5> // 多参模板 非类型表达式参数 默认模板参数
class Array
{
    private:
        T arr[n];
    public:
        // Array();
        T & operator[](int);
};

// template<class T ,int n>
// Array<T,n>::Array(){}

template<class T,int n>
T & Array<T,n>::operator[](int i)  // 返回值类型是Array<T,n>
{
    return arr[i];
}



template<class T1,class T2>
class Stct
{
    private:
        T1 a;
        T2 b;
    public:
        Stct(){};
        Stct(T1 va,T2 vb):a(va),b(vb){}
        T1 & vala();
        T2 & valb();
};

template<class T1,class T2>
T1 & Stct<T1,T2>::vala()
{
    return a;
}

template<class T1,class T2>
T2 & Stct<T1,T2>::valb()
{
    return b;
}

#endif