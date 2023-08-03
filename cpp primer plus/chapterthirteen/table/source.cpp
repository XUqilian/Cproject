#include"head.h"

Tablea::Tablea(const string & str,const string &strl,bool ps)
{
    fname = str;
    lname = strl;
    possess = ps;
}

void Tablea::retab()
{
    fname = "\0";
    lname = "\0";
    possess = false;
}



Tableb::Tableb(const string &str,const string &strl,bool ps,int frn)
:Tablea(str,strl,ps)        //调用构造函数
{
    frection = frn;
    cout << "create Tableb4" << endl;
}

Tableb::Tableb(const Tablea & tb,int frn)
:Tablea(tb)     //直接调用默认的复制构造函数
{
    frection = frn;
    cout << "create Tableb2" << endl;
}

