#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Tablea
{
    private:
        string fname;
        string lname;
        bool possess;
    public:
        Tablea(const string & str = "\0",const string &strl = "\0",bool ps = false);
        void name()const{ cout << fname << lname <<endl;}
        bool valps(){ return possess;}
        void retab();
        virtual ~Tablea(){};  //虚析构函数 确保进行各自的虚构
};

class Tableb :public Tablea
{
    private:
        int frection;
        Tableb(){};
    public:
        Tableb(const string &str,const string &strl,bool ps,int frn);
        Tableb(const Tablea & tb,int frn);
        int valfr()const{ return frection;}
        void retfre(const int fre){ frection = fre;}
        virtual ~Tableb(){};
};

#endif