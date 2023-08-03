#include"head.h"

User::User(const char* n,double a)
{   
    amount = a;
    name = new char[strlen(n)+1];
    strcpy(name , n);
}
  //{name = n;amount = a;}

User::User(const User& t)
{
    //if(this == &t) return;

    amount = t.amount;

    // delete [] name;
    name = NULL;
    
    name = new char[strlen(t.name)+1];
    strcpy(name , t.name);
}

User& User::operator = (const User& t)
{
    if(this == &t) return *this;

    amount = t.amount;

    delete [] name;
    name = NULL;
    
    name = new char[strlen(t.name)+1];
    strcpy(name , t.name);
    return *this;
}


User::~User()
{
    delete []name;
}


// void vir(){}; 
// 试试不实现纯虚函数会怎么样
// 在不实现纯虚函数的情况下 子类必须实现纯虚函数的定义 否则子类将不能创建对象
// 实现了依旧会那样 就等于纯虚函数在基类实现与不实现无差别  
// 基类纯虚函数的调用只有使用域解析运算符调用

ostream & operator<<(ostream &op,const User &t)
{
    return op << t.name << " have:" << t.amount << " dollars" << endl;
}



// void User::vir() // 试试子类实现
// {
//     cout << " this is pure virtual function in user." << endl;
// }
// void Userp::vir() // 试试子类实现
// {
//     cout << " this is pure virtual function in userp." << endl;
// }
// void Uservip::vir() // 试试子类实现
// {
//     cout << " this is pure virtual function in uservip." << endl;
// }





Userp::Userp(const char* ad , const char* n,double a)
:User(n,a)
{
    address = new char[strlen(ad)+1];
    strcpy(address , ad);
}
 
Userp::Userp(const char* ad , User& t)
:User(t)
{
    address = new char[strlen(ad)+1];
    strcpy(address , ad);
}

Userp::~Userp()
{
delete []address;
}


Userp::Userp(const Userp &t)
:User(t)
{
    //if(this == &t) return;
    //amount = t.amount;

    delete [] address;
    address = NULL;
    
    address = new char[strlen(t.address)+1];
    strcpy(address , t.address); 
}

Userp & Userp::operator = (const Userp &t)
{
    if(this == &t) return *this;
    //amount = t.amount;

    delete [] address;
    address = NULL;
    
    address = new char[strlen(t.address)+1];
    strcpy(address , t.address);
    return *this;
}


// void Userp::vir() // 试试子类实现
// {
//     cout << " this is pure virtual function in userp." << endl;
// }

// 试试利用同名但参数不同的方法覆盖基类函数是个什么样子

ostream& operator<<(ostream &op,const Userp &t)
{
    // op << (const User&)t;
    return op << (const User&)t << " address:" << t.address << endl;
}




Uservip::Uservip(const char* n,double a,double u,double r,double d)
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

ostream& operator<<(ostream &op,const Uservip &t)
{
    // op << (const User&)t;
    return op << (const User&)t << " utmost:" << t.utmost << "\t" << "debt:" << t.debt << endl;
}   // 这个函数会不会与基类函数冲突// 函数参数不同 属于重载 //调用规则是最匹配 先调用最匹配
    //需要加 virtual 限制吗  // virtual 不能用于友元函数
    // 子类无法调用父类的友元函数吗
