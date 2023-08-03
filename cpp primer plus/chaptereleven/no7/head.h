#ifndef HEAD_H
#define HEAD_H
#include <iostream>

using std::istream;
using std::ostream;

class cpx
{
private:
    double x;
    double y;

public:
    cpx(){};
    cpx(double, double);
    ~cpx(){};
    cpx operator+(const cpx &);
    cpx operator-(const cpx &);
    cpx operator*(const cpx &);
    cpx operator*(double);

    friend void operator~(cpx &t) { t.y = -t.y; }; // 不加friend调用就是a~b，还仅仅只是改变后对象，不能改的调用对象

    friend cpx operator*(const double d, cpx &t) { return t * d; };

    // friend ostream &operator<<(const ostream &, const cpx &);
    // friend istream &operator>>(const istream &, cpx &);
    
    friend ostream &operator<<(ostream &os, const cpx &t)
    {
        os << "t.x = " << t.x << "\tt.y = " << t.y;
        return os;
    }
    friend istream &operator>>(istream &is, cpx &t)
    {
        is >> t.x >> t.y;
        return is;
    }
};

#endif