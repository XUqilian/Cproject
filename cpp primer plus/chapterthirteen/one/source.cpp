#include "head.h"

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}

Cd::Cd(char* stro, char* strt,int n ,double x)
{
    strncpy(performers,stro,50);
    if(strlen(stro) >= 50)
        performers[50] = '\0';
    else performers[strlen(strt)] = '\0';

    strncpy(label,strt,20);
    if(strlen(strt) >= 20)
        label[19] = '\0';
    else label[strlen(strt)] = '\0';
    
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & t)
{
    strcpy(this->performers,t.performers);
    strcpy(this->label , t.label);
    selections = t.selections;
    playtime = t.playtime;
}

Cd & Cd::operator=(const Cd & t)
{
    if(this == &t) return *this;
    strcpy(this->performers,t.performers);
    strcpy(this->label , t.label);
    selections = t.selections;
    playtime = t.playtime;
    return *this;
}

Clsc::Clsc()
:Cd()
{
    opus = new char;
    opus[0] = '\0';
}

Clsc::Clsc(char* stro, char* strt,int n ,double x,char* s)
:Cd(stro,strt,n,x)
{
    opus = new char[strlen(s) + 1];
    strcpy(opus,s);
}

Clsc::Clsc(Cd & t,char* s)
:Cd(t)
{
    opus = new char[strlen(s) + 1];
    strcpy(opus,s);
}

Clsc::Clsc(const Clsc & t)
:Cd(t)
{   
    delete [] opus;
    opus = NULL;

    opus = new char[strlen(t.opus) + 1];
    strcpy(opus,t.opus);
}


Clsc & Clsc::operator = (const Clsc & t)
{
    if(this == &t) return *this;

    // Cd(t); // why can not do it ,t type is Cd& in this fun other code 
    
    // Cd((Cd&)t); //这种方法我是怎么想出来的  NB

    Cd::operator=(t);

    delete [] opus;
    opus =NULL;

    opus = new char[strlen(t.opus) + 1];
    strcpy(opus,t.opus);

    return *this;
}
