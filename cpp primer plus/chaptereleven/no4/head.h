#ifndef HEAD_H
#define HEAD_H
#include<iostream>

using std::ostream;

class shijian{
	private:
		int hour;
		int minutes;
	public:
		shijian();
		shijian(int ,int );
		~shijian();
		void addm(int );
		void addh(int );
		void reset(int ,int );
		friend shijian& operator+(shijian&,const shijian&);
		friend shijian& operator-(shijian&,const shijian&);
		friend shijian& operator*(shijian& ,const double);
		friend shijian& operator*(double x,shijian& y){return y*x;};
		friend ostream& operator<<(ostream &,const shijian&);
};
#endif
