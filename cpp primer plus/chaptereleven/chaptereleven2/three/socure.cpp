#include "head.h"

namespace Vtr{

    // void Vector::setcoo() 
    // {
    //     y = sin(ang) * mag;
    //     x = cos(ang) * mag;
        
    // }
    // void Vector::setvec() 
    // {
    //     mag = sqrt(x * x + y * y);
    //     ang = atan2( x , y );
        
    // }

    //Vector::Vector() { x = y = ang = mag = 0; }
    Vector::Vector(double a, double b , Mode m)
    {
        if(int(m))
        {
            md = m;
            y = sin(b * Atr) * a;
            x = cos(b * Atr) * a;
            // mag=a;
            // ang=b * Atr;
            // setcoo();
        }else
        {
            md = m;
            x=a;
            y=b;
            // setvec();
        }
    }

    // double Vector::valx() const { return x; }
    // double Vector::valy() const { return y; }
    // double Vector::valmag() const { return mag; }
    // double Vector::valang() const { return ang; }

    // void Vector::setmdc() { md = coo; } // set mode coordinate
    // void Vector::setmdv() { md = vec; } // set mode vector

    Vector Vector::operator+(Vector &t) const { return Vector(x + t.x, y + t.y); }
    Vector Vector::operator-(Vector &t) const { return Vector(x - t.x, y - t.y); }
    Vector Vector::operator-() { return Vector(-x, -y); }
    Vector Vector::operator*(double t) const { return Vector(x * t, y * t); }

    Vector operator*(double f, Vector &t) { return t * f; }

    // ostream & operator << (ostream &os){ os << "x value:"<< x << "y value:" << y << endl;}        //   t << cout no!
    ostream &operator<<(ostream &os, Vector &t) //{ os << "x value:"<< t.x << "y value:" << t.y << endl;}  //need output by mode
    {
        if(t.md == Vector::coo)
            os << "x=" << t.x << ",y=" << t.y <<endl;
        else if (t.md == Vector::vec)
            os << "mag=" << t.valmag() << ",ang=" << t.valang() * Rta <<endl;
        return os;
    }

}