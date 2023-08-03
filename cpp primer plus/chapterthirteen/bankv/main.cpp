#include "head.h"

int main(void)
{
    Userp a("shanghai","tony");
    Userp b("beijing","tom",100);

    Uservip c("jary",100);
    Uservip d("jim",100);

    // User p; // 不允许使用抽象类类型 "User" 的对象
    User * p;

    a.vt(10);
    c.vt();

    p = &b;
    p->vt();

    p = &c;
    p->vt();

    Userp e("nanjing",c); // use uservip init userp
    
    

    return 0;
}