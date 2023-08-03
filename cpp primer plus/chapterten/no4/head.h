#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>

namespace ns
{
    const int Quarters = 4;
    class sales_st
    {
    private:
        double sales_d[Quarters]={0};
        double average;
        double max;
        double min;

    public:
        sales_st()
        {
            average=0;
            max=0;
            min=0;
        };  
        sales_st(const double *, int);
        ~sales_st(){};
        void setsales_st();
        void display()const;
    };
}

#endif