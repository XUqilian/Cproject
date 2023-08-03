#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main(void)
{
    ifstream fio("bat",ios::in);
    ifstream fit("bat1",ios::in);
    ofstream fo("bats",ios::out | ios::trunc);
    if(fio && fit && fo)
    {
        set<string> mat;
        set<string> pat;
        set<string> mpat;
        
        string str;
        while(fio >> str) mat.insert(str);
        while(fit >> str) pat.insert(str);
        mpat.insert(mat.begin(),mat.end());
        mpat.insert(pat.begin(),pat.end());

        // for(auto it = mpat.begin() ; it != mpat.end() ; it++)
        //     fo << it->c_str() << endl;
        for( auto it : mpat)
            fo << it.c_str() << endl;
        cout << "ok!" << endl;
    }else
    {
        cout << "have file cant open." << endl;
        exit(0);
    }

    return 0;
}