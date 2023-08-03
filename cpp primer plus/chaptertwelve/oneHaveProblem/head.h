#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class Cow
{
    private:
        char name[20];
        char * hobby;
        double weight;
    public:
        Cow();
        Cow(const char * nm,const char * ho,double wt);
        Cow(const Cow &c);
        ~Cow(){ delete []hobby;  hobby = NULL;}
        Cow & operator=(const Cow &c);
        void show()const;
};



#endif