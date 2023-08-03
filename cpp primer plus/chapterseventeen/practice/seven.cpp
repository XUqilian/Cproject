#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

class Wf
{
    private:
        ofstream & wfo;
    public:
        Wf(ofstream & fo) : wfo(fo) {}
        void operator()(const string & );
};

void Wf::operator()(const string & str)
{
    // wfo.write((char*) & str.data() ,str.size()); //data 已经是str了 无需转换
    // wfo.write(str.data() ,str.size());
    wfo << str.c_str() << endl;
}

void getstrs(ifstream & fi , vector<string> & vs)
{
    string str;
    while(fi >> str) vs.push_back(str); //**

    // 原本写入是还带一个字符串长度的
    // int len ;
    // char * pt;
    // while(fi.read((char *) & len , sizeof(len)))
    // {
    //     pt = new char[len];
    //     fi.read(pt,len);
    //     vs.push_back(pt);
    //     delete [] pt;
    // }
}

void showstr(const string & str)
{
    cout << str << endl;
}

int main(void)
{
    vector<string> varstr;
    string str;

    while(cout << "enter a string(blank to quit):" && getline(cin,str) && str != "\0")
    {
        varstr.push_back(str);
    }

    ofstream fo("seven");
    if(fo)
    {
        for_each(varstr.begin(),varstr.end(),Wf(fo));
        fo.clear();
        fo.close();
    }else{
        cout << "cant open file." << endl;
        exit(0);
    }

    ifstream fi("seven",ios::in);
    vector<string> vistr;
    if(fi)
    {
        getstrs(fi,vistr);
    }else{
        cout << "cant open file." << endl;
        exit(0);
    }

    for_each(vistr.begin(),vistr.end(),showstr);

    return 0;
}