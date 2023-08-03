#include"head.h"

Stone::Stone(double a)
{
    pounds = a;
    stone = int(a / pts);
    lpds = a - stone * pts ;
}

Stone::Stone(int a,double b)
{
    stone = a;
    lpds = b;
    pounds = a * pts + b;
}

ostream & operator << (ostream & os, Stone & b)
{
    os << "pounds:"<< b.pounds<< "\tstone:" << b.stone <<",lpds:" << b.lpds << endl;
    return os;
}