#include "head.h"

cpx::cpx(double a, double b)
{
    x = a;
    y = b;
}
cpx cpx::operator+(const cpx &t)
{
    cpx p;
    p.x = x + t.x;
    p.y = y + t.y;
    return p;
}
cpx cpx::operator-(const cpx &t)
{
    cpx p;
    p.x = x - t.x;
    p.y = y - t.y;
    return p;
}
cpx cpx::operator*(const cpx &t)
{
    cpx p;
    p.x = x * t.x - y * t.y;
    p.y = x * t.y + y * t.x;
    return p;
}
cpx cpx::operator*(double t)
{
    cpx p;
    p.x = x * t;
    p.y = y * t;
    return p;
}

// void cpx::operator>>(cpx & t)
// {
//     scanf("%f %f",&t.x,&t.y);
//}


// ostream &operator<<(ostream &os, const cpx &t)
// {
//     os << "t.x = " << t.x << "\tt.y = " << t.y;
//     return os;
// }
// istream &operator>>(istream &is, cpx &t)
// {
//     is >> t.x >> t.y;
//     return is;
// }
//将这两个友元函数定义写到外面就会在 t.x t.y 上出现错误  不知道什么原因
//成员 "cpx::x" (已声明 所在行数:11，所属文件:"D:\githubrepository\Cproject\cpp\chapetereleven\no7\head.h") 不可访问