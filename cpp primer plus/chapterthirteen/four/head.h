#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::ostream;

class Port
{
    private:
        char* brand;
        char style[20];
        int bottles;
    
    public:
        Port(const char* br = "none",const char* st = "none",int b = 0);
        Port(const Port &t);
        virtual ~Port(){delete []brand;};
        Port & operator=(const Port & t);
        Port & operator+=(int b);
        Port & operator-=(int b);
        int valbottle()const {return bottles;}
        virtual void show()
            {cout << "brand:" << brand << "\nkind:" << style << "\nbottles:" << bottles << endl;}
        friend ostream & operator<<(ostream & op,const Port & t)
            {return op << t.brand << "," << t.style << "," << t.bottles << endl; }
};

class Vport
:public Port
{
    private:
        char* name;
        int year;
    
    public:
        Vport();
        Vport(const char* br,const char* st, int b,const char* nn, int y);  //按原参数无法实现初始化 故调整
        Vport(const Vport & t);
        virtual ~Vport(){delete []name;}
        Vport & operator=(const Vport& t);
        virtual void show()
            { Port::show(); cout << "name:" << name << "\nyear:" << year << endl;}
        // 错误 : 非静态成员引用必须与特定对象相对 结果 TMD 是没继承父类
        //    {((Port*)this)->show(); cout << "name:" << name << "\nyear:" << year << endl;}
        friend ostream& operator<<(ostream & op,Vport & t)
            { return op << (Port&)t << "\n" << t.name << "," << t.year << endl;}
};


#endif