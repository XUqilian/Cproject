#include "head.h"

ston::ston()
{
	stone = pound = stp = 0;
}

ston::ston(double t)
{
	stone = int(t) / lps;
	stp = t - stone;
	pound = t;
}
ston::ston(int a, double b)
{
	stone = a;
	stp = b;
	pound = a * lps + b;

}

ston::~ston() {}


bool ston::operator>(const ston &t)const
{
	return pound>t.pound;
}
bool ston::operator>=(const ston &t)const
{
	return pound>=t.pound;
}
bool ston::operator==(const ston &t)const
{
	return pound==t.pound;
}
bool ston::operator<(const ston &t)const
{
	return pound<t.pound;
}
bool ston::operator<=(const ston &t)const
{
	return pound<=t.pound;
}
bool ston::operator!=(const ston &t)const
{
	return pound!=t.pound;
}
// ostream &operator<<(ostream &os, const ston &t)
// {
// 	using std::endl;
// 	if (t.md == ston::estone)
// 	{
// 		os << "stone=" << t.stone << endl;
// 	}
// 	else if (t.md == ston::epound)
// 	{
// 		os << "stone=" << t.stone << "\tstp=" << t.stp << endl;
// 	}
// 	else if (t.md == ston::epoundf)
// 	{
// 		os << "pound=" << t.pound << endl;
// 	}
// 	return os;
// }