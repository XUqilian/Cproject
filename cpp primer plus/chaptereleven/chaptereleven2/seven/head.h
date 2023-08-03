#ifndef HEAD_H
#define HEAD_H

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
class Cpx{
    private:
        double real;
        double imagin;
    public:
        Cpx(){real = imagin = 0;}
        Cpx(double a, double b)
        {
            real = a;
            imagin = b;
        }

        Cpx operator+(const Cpx &t)const { return Cpx(real + t.real,imagin + t.imagin);}
        Cpx operator-(const Cpx &t)const { return Cpx(real - t.real,imagin - t.imagin);}
        Cpx operator*(const Cpx &t)const { return Cpx(real * t.imagin ,imagin * t.real);}
        friend Cpx operator*(double a,Cpx & t){ return Cpx( a * t.real , a * t.imagin);}
        //void operator~(){ imagin = -imagin;}
        Cpx operator~()
        { 
            imagin = -imagin;
            return *this;
        }

        friend ostream & operator<<(ostream &os ,const Cpx &t){ return os << "real:" << t.real <<"\timagin:"<< t.imagin << endl;}
        friend istream & operator>>(istream &os ,Cpx &t){ return os >> t.real >> t.imagin;}
};

#endif