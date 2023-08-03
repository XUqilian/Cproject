#include"head.h"

int main(void)
{
    Singer a;
    Singer b("tom", 10 , 10);
    cout << b;
    a.set();
    cout << a;

    Waiter c;
    Waiter d("tim", 10 ,10);
    cout << d;
    c.set();
    cout << c;

    return 0;
}