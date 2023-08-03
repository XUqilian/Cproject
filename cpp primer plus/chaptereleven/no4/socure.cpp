#include "head.h"
//#include <iostream>

using std::endl;
// using std::ostream;
shijian::shijian(){}
shijian::~shijian() {}
shijian::shijian(int a, int b)
{
	hour = a;
	minutes = b;
}

void shijian::addm(int a)
{
	minutes += a;
	hour += (minutes / 60);
	minutes %= 60;
}
void shijian::addh(int a)
{
	hour += a;
}
void shijian::reset(int a, int b)
{
	hour = a;
	minutes = b;
}

shijian &operator+(shijian &a, const shijian &b)
{
	a.hour += b.hour;
	a.minutes += b.minutes;
	a.hour += (a.minutes / 60);
	a.minutes= (a.minutes % 60);
	return a;
}
shijian &operator-(shijian &a, const shijian &b)
{
	a.hour -= b.hour;
	a.minutes -= b.minutes;
	if (a.minutes < 0)
		a.hour--;
	a.minutes += 60;
	return a;
}
shijian &operator*(shijian &a, const double d)
{
	a.hour *= d;
	a.minutes *= d;
	a.hour += (a.minutes / 60);
	a.minutes= (a.minutes % 60);
	return a;
}
// shijian& operator*(const double x,const shijian& y)
// {
// 	return y*x;
// }

ostream &operator<<(ostream &os, const shijian&a)
{
	os << "hours is " << a.hour << ",minutes is " << a.minutes << "." << endl;
	return os;
}
