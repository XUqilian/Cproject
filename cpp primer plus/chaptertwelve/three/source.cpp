#include "head.h"

// char * company;
// int shares;
// double shareval;
// double totalval;
// void settot()   {totalval = shares * shareval;}

Stok::Stok()
{
    shares = shareval = totalval = 0;
    company = NULL;
}
Stok::Stok(const char * co,long n, double pr)
//Stok::Stok(const char * co,long n = 0 , double pr = 0.0)
{
    company = new char[strlen(co) + 1];
    strcpy(company,co);

    if(n < 0) shares = 0 ;
    else shares = n ;
    
    shareval = pr;
    settot();
}
// Stok::~Stok(){}


void Stok::buy(long num , double price)
{
    if( num >= 0)
    {
        shares += num;
        shareval = price;
        settot();
    }
}

void Stok::sell(long num , double price)
{
    if(num > 0 && num <= shares)
    {
        shares -= num;
        shareval = price;
        settot();
    }
}
void Stok::update(double price)
{
    shareval = price;
    settot();
}
// void Stok::show()const
// {
//     cout << company << ":" << shares << "\t" << shareval << " \t " << totalval << endl;
// }
const Stok & Stok::topval(const Stok & s) const
{
    return s.totalval > totalval ? s : *this ;
}

ostream & operator<<(ostream & os,const Stok & t)
{
    return os << t.company << ":" << t.shares << "\t" << t.shareval << " \t " << t.totalval << endl;
}