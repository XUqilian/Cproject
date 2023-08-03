#include"head.h"

// ostream& operator<<(ostream &op,User &t)
// {
//     return op << t.name << " have:" << t.amount << " dollars" << endl;
// }


Uservip::Uservip(const string &n,double a,double u,double r,double d)
:User(n,a)      //如不设置将调用默认构造函数构造无值的基类对象  这里是已定义了构造函数必须用
{
    utmost = u;
    rate = r;
    debt = d;
}   

Uservip::Uservip(User &t,double u,double r,double d)
:User(t)
{
    utmost = u;
    rate = r;
    debt = d;
}

void Uservip::add(double t)
{
    if( 0 == debt ) 
    {
        User::add(t);
    }
    else if(debt >= t){
        debt -= t;
    }else{
        t =t - debt;
        debt =0;
        utmost = 500;
        User::add(t);   //注意调用对象  函数需用作用域符号限制  不然将产生死循环
    }
}

void Uservip::subtract(double t)
{
    if(t <= User::valamount()) User::subtract(t);
    else if(t <= User::valamount() + utmost )
    {
        t -= User::valamount();
        User::subtract(User::valamount());
        debt = t+(t*rate);
        utmost = 0;
    }
}

// ostream& operator<<(ostream &op,Uservip &t)
// {
//     User::operator<<(op,t) ;
//     return op << " utmost:" << t.utmost << "\t" << "debt:" << t.debt << endl;
//     // op << (user&) t <<  
// }   // 这个函数会不会与基类函数冲突 需要加 virtual 限制吗  // virtual 不能用于友元函数
//     // 子类无法调用父类的友元函数吗
