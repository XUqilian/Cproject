#include<iostream>
// Consolas, 'Courier New', monospace

class A{};
class B : public A {};


int main(void)
{
    A a;
    B b;
    
    A * pa = dynamic_cast<A *>(& b);  // 判断类能否转换成指定类型 ？ 返回该类指针 ：返回NULL；

    int inter = 10;
    const int * pci = & inter;
    int * pi = const_cast<int *> (pci);     // 将const转变为可更改

    pa = static_cast<A *> (& b);      // 当两种类型可隐式转换时 成立
    B * pb = static_cast<B *> (& a);
    // 基类与子类 int与double int与enum...

    reinterpret_cast<A * > (& inter);   //用于危险的类型转换 不推荐用

    return 0;
}