#include"head.h"
//using namespace ns;

int main()
{
    double ar[ns::Quarters] = {1, 2, 3, 4};
	ns::sales_st x=ns::sales_st(ar, 4);
    ns::sales_st y(ar, 4);
    ns::sales_st z={ar, 4};
    ns::sales_st a={};
    ns::sales_st s;
    
    s.setsales_st();

    return 0;
}
