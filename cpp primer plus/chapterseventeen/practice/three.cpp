#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc,char * argv[])
{
    if(argc != 3)
    {
        cout << "参数出错:需要参数为(a.out txt1 txt2)" << endl;
        exit(0);
    }

    ifstream fi;
    fi.open(argv[1],ios::in);
    ofstream fo(argv[2]);
    if(fi && fo)
    {
        string str;
        while(fi >> str) fo << str;

        fi.clear();
        fo.clear();
        fi.close();
        fo.close();
        cout << "ok!" << endl;
    }else 
    {
        if(!fi)
            cout << "fi cant open." << endl;
        if(!fo)
            cout << "fo cant open." << endl;
        exit(0);
    }

    return 0;
}