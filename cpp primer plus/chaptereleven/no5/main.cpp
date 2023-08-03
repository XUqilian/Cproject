#include "head.h"
//#include<iostream>

int main()
{
    ston a;
    a=34.5;
    ston b(34.5);
    ston c(2,3.4);
    a.setmode(ston::estone);
    b.setmode(ston::epound);
    c.setmode(ston::epoundf);
    std::cout<<"a"<<a<<"b"<<b<<"c"<<c;
    a=a+b;
    std::cout<<"a"<<a<<"b"<<b<<"c"<<c;
    a=a-c;
    std::cout<<"a"<<a<<"b"<<b<<"c"<<c;
    a=a*3;
    std::cout<<"a"<<a<<"b"<<b<<"c"<<c;
    a=3*a;
    std::cout<<"a"<<a<<"b"<<b<<"c"<<c;
    std::cout<<"done!"<<std::endl;
}
