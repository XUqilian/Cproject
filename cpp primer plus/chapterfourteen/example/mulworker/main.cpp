#include"head.h"

int main(void)
{
    Singer a;
    Singer b("tom", 10 , 10);
    cout << "\nb:"<< b;
    // a.set(); 不使用proitected限定时使用
    cin >> a; // 使用protected 限定只能间接使用其他函数调用 因为保护限定函数只能在头文件和源文件使用
    cout << "\na:" << a;

    Waiter c;
    Waiter d("tim", 10 ,10);
    cout << "\nd:" << d;
    // c.set();
    cin >> c;
    cout << "\nc:" << c;

    Wsw e;
    Wsw f("titi",10,10,10);
    cout << "\nf:" << f;
    // e.set();
    cin >> e;
    cout << "\ne:" << e;

    return 0;
}