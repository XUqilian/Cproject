#include "head.h"

ston::ston()
{
	stone = pound = stp = 0;
	md = estone;
}

ston::ston(double t)
{
	stone = int(t) / lps;
	stp = t - stone;
	pound = t;

	md = epoundf;
}
ston::ston(int a, double b)
{
	stone = a;
	stp = b;
	pound = a * lps + b;

	md = epoundf;
}

ston::~ston() {}

void ston::setmode(mode t)
{
	md = t;
}

// ston &ston::operator+(const ston &t)
// {
// 	//ston x(pound + t.pound);  return x; //但返回局部变量时，局部变量将会在退出函数时销毁
// 	//而且函数返回类型是引用，并不具有存储空间
// 	//return pound+t.pound;  //可以改变返回类型为double，但在历经等号时，会再次调用对象的构造函数，占空间和时间
// 	// return ston(pound+t.pound);  不能这样返回是因为这样匿名的对象生存周期就这一句，活不到返回出去
// 	//返回最终是要a=a+b；属于赋值，总不能a+b；就结束吧
// }
// ston &ston::operator-(const ston &t)
// {
// 	ston x(pound + t.pound);
// 	return x;
// }
// ston &ston::operator*(const double t)
// {
// 	ston x(pound * t);
// 	return x;
// }


double ston::operator+(const ston &t)
{
	return pound+t.pound;
}
double ston::operator-(const ston &t)
{
	return pound-t.pound;
}
double ston::operator*(const double t)
{
return pound*t;}

ostream &operator<<(ostream &os, const ston &t)
{
	using std::endl;
	if (t.md == ston::estone)
	{
		os << "stone=" << t.stone << endl;
	}
	else if (t.md == ston::epound)
	{
		os << "stone=" << t.stone << "\tstp=" << t.stp << endl;
	}
	else if (t.md == ston::epoundf)
	{
		os << "pound=" << t.pound << endl;
	}
	return os;
}