#ifndef TRYCATCH_H
#define TRYCATCH_H

#include<iostream>
// #include<excption>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::logic_error;

class errf : public logic_error
{
    private:
        int a;
        int b;
    public:
        errf(int x,int y,const char * str):a(x) , b(y) , logic_error(str){}
        virtual void dis()const{cout << "a:" << a << "\tb" << b << endl;}
};

class erone : public errf
{
    public:
        erone(int x,int y):errf( x , y , "argment error: the parameters are opp0site numbers."){}
        virtual void dis()const {    cout << what() << endl;    errf::dis(); }
};

class ertwo : public errf
{
    public:
        ertwo(int x,int y):errf( x , y , "argment error: there are partmeters <= 0."){}
        virtual void dis()const {   cout << what() << endl;     errf::dis(); }
};

#endif