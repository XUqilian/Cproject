#include "head.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{

    cpx a(12, 13);
    cpx b(14, 15);
    cpx c;

    cout<<"enter c";
    cin>>c;
    cout<<"c:"<<endl;

    c = a + b; //这个地方这么会通过呢？我并没有声明定义重载=号
    cout << "c=a+b" << endl;
    cout << "a:" << a << "b:" << b << "c:" << c << endl;

    b = b - a;
    cout << "b=b-a" << endl;
    cout << "a:" << a << "b:" << b << "c:" << c << endl;

    c = b * a;
    cout << "c=b*a" << endl;
    cout << "a:" << a << "b:" << b << "c:" << c << endl;

    b = b * 2;
    cout << "b=b*2" << endl;
    cout << "a:" << a << "b:" << b << "c:" << c << endl;

    b = 3 * b;
    cout << "b=3*b" << endl;
    cout << "a:" << a << "b:" << b << "c:" << c << endl;

    ~c;
    cout << "~c" << endl;
    cout << "a:" << a << "b:" << b << "c:" << c << endl;

    return 0;
}