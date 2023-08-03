#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Stok
{
    private:
        char * company;
        int shares;
        double shareval;
        double totalval;
        void settot()   {totalval = shares * shareval;}
    public:
        Stok();
        // Stok(const char * co,long n, double pr);     //默认参数的函数应在声明处给定默认值 定义处无需再加
        Stok(const char * co,long n = 0 , double pr = 0.0);
        ~Stok(){delete []company;}                          //this error??? i was encounter 
        
        // Stok(const Stok &t){}
        // Stok operator=(const Stok &t){return *this;}

        void buy(long num , double price);
        void sell(long num , double price);
        void update(double price);
        const Stok & topval(const Stok & s) const;
        // void show()const;
        friend ostream & operator<<(ostream & os,const Stok & t);
};
#endif
