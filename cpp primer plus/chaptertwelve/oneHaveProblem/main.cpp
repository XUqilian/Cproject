#include"head.h"

int main(void)
{
    Cow a;
    Cow b("marry","eat",200.00);
    b.show();
    a = b;
    Cow c = b;  //这个版本是直接调用复制构造函数  并不会先调用构造函数 后调用赋值运算符
    a.show();
    b.show();
    c.show();

    return 0;
}