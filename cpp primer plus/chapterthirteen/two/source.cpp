#include "head.h"

Cd::Cd()
{
    performers = new char;
    performers[0] = '\0';
    label = new char;
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}

Cd::Cd(char* stro, char* strt,int n ,double x)
{
    performers = new char[strlen(stro) + 1];
    label = new char[strlen(strt) + 1];
    strcpy(performers,stro);
    strcpy(label,strt);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & t)
{
    delete []performers;
    delete []label;
    performers = NULL;
    label = NULL;

    performers = new char[strlen(t.performers) + 1];
    label = new char[strlen(t.label) + 1];
    strcpy(this->performers,t.performers);
    strcpy(this->label , t.label);
    selections = t.selections;
    playtime = t.playtime;
}

Cd & Cd::operator=(const Cd & t)
{
    if(this == &t) return *this;

    delete []performers;
    delete []label;
    performers = NULL;
    label = NULL;
    
    performers = new char[strlen(t.performers) + 1];
    label = new char[strlen(t.label) + 1];
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
    
    //  Cd((Cd&)t);  why ok
    Cd::operator=(t);

    delete [] opus;
    opus =NULL;

    opus = new char[strlen(t.opus) + 1];
    strcpy(opus,t.opus);

    return *this;
}
