#include"head.h"


int main()
{
    move a;
    a.show();
    move b{2.0,4.0};
    b.show();
    a.reset(3.0,4.0);
    b.add(a);
    return 0;
}