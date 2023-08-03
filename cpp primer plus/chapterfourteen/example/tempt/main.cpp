#include".\..\templateclass\head.h"

///////////* 详细问题的请参阅./easytemplate.cpp */////////////////

// template<class TT> // 接受一个确定 "类型"
template<template<class T>class TT> // 接受一个不确定类型 "模板" 
class Nested 
{
    private:
    //  TT sa;  //标准模板类创建  // 在这里TT只是一个模板类 并不是类对象
        TT<int> stai; // TT<int> 类创建  //这里才是一个类对象
        // 是不是也可以运行时确定使用哪种类型 TT<T> sta;
        TT<double> stad;
    public:
        // Nested(TT t,TT tt) // have error 
        // Nested(TT t,TT tt) //接受参数与类成员类型相同 才能给类成员赋值 根据模板声明 此处接受的是模板
        //     :stai(t),stad(tt){} //此处将模板赋给类成员 

        // 后续就需要根据传入模板来确定使用的函数了
        // 这里先根据头文件引用 确定传入栈模板
        bool push(int a, double b){return stai.push(a) && stad.push(b);} 
        bool pop(){return stai.pop()&& stad.pop();}

};


int main(void)
{
    // Nesteds<Stack , int ,int> iista;  // perfect. its use Nesteds
    // Nested<Stack> use(Stack<int> s1, Stack<double> s2);  // 实例化 instantiation
    // Nested<Stack> use(Stack s1 , Stack s2);
    Nested<Stack> use;
    int a;
    double b;
    while(cin >> a >> b && a!=0 && b !=0)
        use.push(a,b);
    while(use.pop());


    return 0;
}









