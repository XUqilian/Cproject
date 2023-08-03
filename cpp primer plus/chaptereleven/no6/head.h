#ifndef HEAD_H
#define HEAD_H
#include <iostream>

//using std::ostream;

class ston
{
private:
	enum{lps=14};//换算比
	int stone;//石
	double pound;//磅
	double stp;//磅减石

public:
	ston();
	ston(double);
	ston(int, double);
	~ston();

	bool operator>(const ston &)const;
	bool operator>=(const ston &)const;
	bool operator==(const ston &)const;
	bool operator<(const ston &)const;
	bool operator<=(const ston &)const;
	bool operator!=(const ston &)const;

	//friend double operator*(double x, ston &y) {return y * x; };
	//friend ostream &operator<<(ostream &, const ston &);
};
#endif
