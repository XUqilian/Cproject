#include"head.h"

int main(void)
{
    Port a("aaa","aaaaaaa",10);
    a.show();
    a += 10;
    cout << a;
    a -=5;
    cout << a;
    Port c = a;
    Port d;
    d = a;
    cout << c << d;



    Vport b("bbb","bbbbbbb",10,"bbbbb",10);
    b.show();
    b += 10;

    cout<< "\n" << b;
    b -= 5;
    cout << b;

    Vport e = b;
    Vport f;
    f = b;
    cout << e << f;

    return 0;
}