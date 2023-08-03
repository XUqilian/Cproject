#include "head.h"
//#include<iostream>

int main()
{
	using std::cout;
	using std::endl;
	//shijian a,b,t;
	//a(3,35);
	//b(2,48);
	
	shijian a(3,35);
	shijian b(2,48);
	shijian t;
	cout<<"a="<<a<<"b="<<b<<endl;
	t=a+b;
	cout<<"t="<<t<<endl;
	t=a*1.17;
	cout<<"a*1.17="<<t<<endl;
	cout<<"b*10.0="<<b*10.0<<endl;
	return 0;
}
