#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main(void)
{
    char ch;
    
    // char tname[L_tmpnam] = {"\0"};
    // tmpnam(tname);

    ofstream fo("bat",ios::out | ios::trunc);
    if(fo)
    {
        while(cin >> ch) fo << ch ;     // 此处应解决换行和空白字符保存问题 因为cin不读取空白字符等 换cin.get
        fo.clear();
        fo.close();
    }
    else exit(0);
    return 0;
}