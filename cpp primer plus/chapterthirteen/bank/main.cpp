#include "head.h"
void text(User &t)
{
    t.display();
    t.add(100);
    t.display();
    t.subtract(100);
    t.display();
}
void ptext(User *t)
{
    t->display();
    t->add(100);
    t->display();
    t->subtract(100);
    t->display();
}
int main(void)
{
    User a("duo");
    a.display();
    User b("tom",1000);
    a.add(1024);
    a.subtract(1000);
     
    a.display();
    b.display();

    Uservip c("jery",1000,500);
    Uservip aa(a,500);
    c.subtract(1050);
    c.display();

    aa.subtract(510);    //成功
    aa.display();

    aa.subtract(500);  //超出失败
    aa.display();

    aa.add(100000);
    aa.display();



    User *pa = &a;
    pa = &aa;           //基类指针和引用可以指向子类对象
    User &pb = a;       //但基类指针只能调用基类的方法
    pb = aa;



    text(a);
    ptext(&a);

    text(aa);           //使用父类引用指向子类
    ptext(&aa);         //使用父类指针指向子类
    aa.User::display(); //子类调用父类函数

    User d(aa);         //用子类初始化父类
    User e = aa;


    return 0;
}