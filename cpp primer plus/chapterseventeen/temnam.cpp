#include<iostream>

using namespace std;

int main(void)
{
    char tname[L_tmpnam] = {"\0"};  //创建一个存储名字的数组
    for(int i = 0 ; i < 10 ; i++)
    {
        tmpnam(tname);  //随机一个有规律的字符串存入数组
        cout << tname  << endl;
    }
    return 0;
}