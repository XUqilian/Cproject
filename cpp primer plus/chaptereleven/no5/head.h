#ifndef HEAD_H
#define HEAD_H
#include <iostream>

using std::ostream;

class ston
{
public:
	enum mode
	{
		estone,
		epound,
		epoundf
	};

private:
	enum{lps=14};//换算比
	int stone;//石
	double pound;//磅
	double stp;//磅减石
	mode md;

public:
	ston();
	ston(double);
	ston(int, double);
	~ston();
	void setmode(mode);
	double operator+(const ston &);
	double operator-(const ston &);
	double operator*(const double);

	// ston& operator+(const ston &);
	// ston& operator-(const ston &);
	// ston& operator*(const double);

	friend double operator*(double x, ston &y) {return y * x; };
	friend ostream &operator<<(ostream &, const ston &);
};
#endif
