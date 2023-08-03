#include"head.h"

int main(void)
{
    Cpx a(3.0,4.0);
    Cpx c;
    cout << "enter a Cpx number:(q to quit)";

    while(cin >> c)
    {
        cout << "\nc is " << c << endl;
        cout << "Cpx cjt is " << ~c <<endl;
        cout << "a + c is " << a + c << endl;
        cout << "a + c is " << a - c << endl;
        cout << "a + c is " << a * c << endl;
        cout << "a + c is " << 2 * c << endl;
        cout << " enter next Cpx number:(q to quit) " << endl;
    }



    return 0;
}