#include<iostream>

using std::cin;

int main(void)
{
    char ch;
    int cnt = 0;
    while(cin >> ch && ch !='$') cnt++;   // while('$' != cin.peek() && cin >> ch)
    std::cin.putback(ch);
    cin.clear();
    return 0;
}