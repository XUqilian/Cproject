#include<iostream>
#include<iomanip>

using namespace std;
void f7()
{
    cout << "enter you name :";
    string name("hony");
    // cin >> name;

    cout << "enter you hourly wages :";
    int hw = 12;
    // cin >> hw;

    cout << "enter you hourly worked :";
    double hd = 8.5;
    // cin >> hd;

    cout << "\nfirst format:" << endl;
    // cout.setf(ios::showpoint);
    cout << setw(30) << right << name;
    cout << ":$" << setw(10) << right << fixed << setprecision(2) << (double)hw;
    cout << ":" << setw(10) << right << fixed << setprecision(1) << hd;
    // cout << (double)hw;
    cout << "\nsecond format:" << endl;
    cout << setw(30) << left << name;
    cout <<":$" << setw(10) << fixed << setprecision(2) << (double)hw;
    cout << ":" << setw(10) << fixed << setprecision(1) << hd;
}


int main(void)
{

    int n = 10 ;
    cout << showbase; // 显示前缀
    cout << setw(15) << hex << n << setw(15) << oct << n << setw(15) << dec << n << endl;

    char ch;
    int ct1 =0;
    cin >> ch;
    while(ch != 'q')
    {
        ct1++;
        cin >> ch;
    }
    // 此处换行未抛出缓冲 下一个获取将先接受换行符 
    
    int ct2 =0;
    ch = cin.get();
    while(ch != 'q')
    {
        ct2++;
        cout << ch << ct2 << endl;
        ch = cin.get();
    }


    cout << ct1 << ' ' << ct2  << endl;
    return 0;
}