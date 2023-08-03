#include"head.h"

int main(void)
{
    Lack a;
    a.show();
    Lack aa("hello" , a);
    cout << aa ;

    Has b;
    b.show();
    Has bb("world" , b);
    Has bbb(bb);
    bb.show();
    bbb.show();
    
    return 0;
}