#include"head.h"

int main(void)
{
    Times a;
    Times b(1,3);
    a = b;
    b.reset();
    b.addh(2);
    b.addm(59);
    a = a*3;
    a = a - b;
    cout<< a << b << endl;

    return 0;
}