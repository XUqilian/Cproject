#ifndef HEAD_H
#define HEAD_H
            //abc  一个纯虚基类
            //加入动态内存分配
#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::cout;
using std::endl;
//using std::string;
using std::ostream;

class User{
    private:
        char* name;
        double amount;

    protected:                              
        //在本类内与私有相同 但子类可以像 public 一样使用 
        // 多用于成员函数   类内可访问 子类好使用
        //这样本类在外部不能用 子类还可以使用 
        double valamount(){return amount;};  
                                            
    public:
        User(const char* n,double a = 0);  //{name = n;amount = a;}
        
        User(const User &);
        User & operator = (const User &);

        virtual ~User();

        //这个 纯虚函数我找不到好的实现方法 没什么作用 就为了展现一下虚函数定义
        // 纯虚函数不能再声明文件中定义 需在函数后面让其为零
        //但纯虚函数可以在定义文件中定义  就类似占位符
        // 纯虚函数主要是提供在不同子类中定义不同实现 定义一个统一的接口 接口通常由子类实现
        virtual void vir()=0;   //纯虚函数 指定本类为纯虚类 不可使用本类创建类对象
                                //但纯虚函数只是在声明中不能定义 但可以在定义文件定义内容

        virtual void vt(){cout << " in user." << endl;}
        // 重载和覆盖
        // 重载只存在于类内 不继承
        // 覆盖只存在于继承或块内外 
        // 我自己理解就是覆盖和 virtual 就是一种相互影响的属性
        virtual void add(double t){amount += t;}
        virtual void subtract(double t){ if(amount >= t) amount -= t;}

        //virtual void display(){ cout << name << " have:" << amount << " dollars" << endl;}
        friend ostream& operator<<(ostream &op,const User &t);
        
};


class Userp :public User
{   //需分配空间版本 //需要为自己的分配空间成员覆写默认赋值与复制和析构函数
    private:
        char * address;
                                            
    public:
        Userp(const char* ad , const char* n,double a = 0);  //{name = n;amount = a;}
        Userp(const char* ad , User& t);
        virtual ~Userp();
        Userp(const Userp &);
        Userp & operator = (const Userp &);

        virtual void vir(){cout << " this is pure virtual function in userp." << endl;};  // 在子类中定义与基类参数不同的函数会隐藏基类函数 使其无法调用

        virtual void vt(int){cout << " in userp." << endl;}
        
        // virtual void add(double t){amount += t;}
        // virtual void subtract(double t){ if(amount >= t) amount -= t;}

        //virtual void display(){ cout << name << " have:" << amount << " dollars" << endl;}
        friend ostream& operator<<(ostream &op,const Userp &t);
        
};


class Uservip :public User
{   //无需分配空间版本  //调用复制和赋值都会调用基类的相应函数 无需覆写默认函数 且析构是虚的
    private:
        double utmost;  //最大欠额
        double debt;    //已欠
        double rate;    //利率
        
    public:
        Uservip(const char* n,double a,double u=500,double r=0.12,double d = 0);
        Uservip(User &t,double u=500,double r=0.12,double d = 0); 
        //基类虽然无法实例 但子类可以被基类指针和引用 由此可以实现向上转换的赋值 
        //而且使用基类指针和引用还可以增强适用 只要都是基类产生的子类对象都可以使用

        virtual void vir(){cout << " this is pure virtual function in uservip." << endl;}
        //试试子类不提及纯虚函数会怎么样 结果就是都不让创建对象
        //不允许使用抽象类类型 "Uservip" 的对象:C/C++(322) main.cpp(15, 13): 纯虚拟 函数 "User::vir" 没有强制替代项
        // virtual void vir(int){}
        // 函数参数不同也会报这个错 

        virtual void vt(){cout << " in uservip." << endl;}

        virtual ~Uservip(){};
        // void altumost(double t){utmost = t;}
        // void altrate(double t){ rate = t;}
        virtual void add(double t);
        virtual void subtract(double t);

        // virtual void display(){ User::display();  cout << "utmost:" << utmost << " debt:" << debt << " rate:" << rate << endl;}
        friend ostream& operator<<(ostream &op,const Uservip &t);   //{t.display();}
};

#endif