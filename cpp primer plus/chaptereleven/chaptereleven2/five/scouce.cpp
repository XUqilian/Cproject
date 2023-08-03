#include "head.h"

Stone::Stone(double a)
{
    pounds = a;
    stone = int(a / pts);
    lpds = a - stone * pts;
}

Stone::Stone(int a, double b)
{
    stone = a;
    lpds = b;
    pounds = a * pts + b;
}

ostream &operator<<(ostream &os, Stone &b)
{
    if (b.md == Stone::Mode::usep)
    {
        os << "pounds:" << b.pounds << endl;
    }
    else
    {
        os << "stone:" << b.stone << ",lpds:" << b.lpds << endl;
    }

    return os;
}
