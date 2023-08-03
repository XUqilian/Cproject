#include"head.h"

int main(void)
{
    Tablea a;

    Tablea b("aa","aaa",1);
    
    b.name();
    b.retab();
    cout << b.valps() << endl;


    Tableb c("bb","bbb",1,10);
    Tableb d(b,10);

    cout << c.valfr() << endl;
    d.retfre(10);
    cout << "done!" << endl;

    // Tableb e();   //这个地方怎么通过了 //默认构造还存在吗 我已经重写构造函数了啊
    // 这应该可能是调用了复制构造函数将空值赋给类型对象
    // 类似于 int z();  给变量赋予空值

    cout << "done!" << endl;

    return 0;
}