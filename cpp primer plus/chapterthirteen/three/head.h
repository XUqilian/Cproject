#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::ostream;



class Dma{
    private:
        char * label;
        int rataing;
    
    public:
        Dma(const char* , const int);
        Dma(const Dma &);
        virtual ~Dma();
        Dma & operator=(const Dma &);
        virtual void show() = 0;
        friend ostream & operator<<(ostream & ,const Dma &);

};

// Base 毫无意义 能做的就是创建一个可创建的父类对象罢了 内部无数据 很多函数都可以不写
// class Base
// :public Dma{

//     public:
//         Base(const char* , const int);
//         Base(const Base &);
//         virtual ~Base();
//         // Base & operator=(const Base &);
//         virtual void show();
//         // friend ostream & operator<<(ostream & ,const Base &);

// };


class Lack
:public Dma
{
    private:
        enum{Coll = 40};
        char color[Coll];

    public:
        Lack(const char * lab = "blank", const char * str = "mull", int ra = 0);
        Lack(const char * ,const Dma &);
        virtual ~Lack();
        virtual void show();
        friend ostream & operator<<(ostream &,const Lack &);

};

class Has
:public Dma
{
    private:
        char * style;

    public:
        Has(const char * lab = "none", const char * sty = "null" ,int ra = 0);
        Has(const char * , const Dma &);
        Has(const Has &);
        virtual void show();
        virtual ~Has();
};
#endif