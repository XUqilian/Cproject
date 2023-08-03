#include "head.h"

    Times::Times(int a,int b)
    {
        hours = a;
        minutes = b;
    }
    void Times::addh(int a)
    {
        hours += a;
    }
    void Times::addm(int a)
    {
        minutes += a;
        if(minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

    Times operator+(Times &a,Times &b)
    {
        int m = (a.hours + b.hours) * 60 ;
        m += (a.minutes + b.minutes);
        return Times(m/60,m%60);
    }
    Times operator-(Times &a,Times &b)
    {
        int m = (a.hours - b.hours) * 60 ;
        m += (a.minutes - b.minutes);
        return Times(m/60,m%60);
    }
    Times operator*(Times &a,int b )
    {
        int m = (a.hours * b) * 60 ;
        m += (a.minutes * b);
        return Times(m/60,m%60);
    }
    Times operator*(int b,Times &a)
    {
        return a * b;
    }