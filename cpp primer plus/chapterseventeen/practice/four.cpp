#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char * argv[])
{
    if(argc != 3)
    {
        cout << "参数出错:需要参数为(a.out txt1 txt2)" << endl;
        exit(0);
    }

    ifstream fio(argv[1],ios::in);
    ifstream fit(argv[2],ios::in);
    ofstream fo("bats",ios::out | ios::trunc);
    
    if(fio && fit && fo)
    {
        string str;
        while(fio || fit)
        {
            if(fio)
            {
                // fio.getline(str,100,' '); 使用数组就要解决越界问题
                fio >> str;         // 使用cin的地方要解决跳过空白以及换行符的问题
                fo << str << ' ' ;
            }
            if(fit)
            {
                fit >> str;
                fo << str << '\n' ;
            }
        }

        fio.clear();
        fit.clear();
        fio.close();
        fit.close();
        cout << "ok!" << endl;
    }else 
    {
        if(!fio)
            cout << "fio cant open." << endl;
        if(!fit)
            cout << "fit cant open." << endl;
        if(!fo)
            cout << "fo cant open." << endl;
        exit(0);
    }

    return 0;
}