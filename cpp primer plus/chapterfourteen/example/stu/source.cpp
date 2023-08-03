#include"head.h"

Stu::Stu()
// :name(),scores()  //if i dont do it.  i cant use operator>> 
{}

//
Stu::Stu(const char* t)
:name(t) , scores(){} 
// you can dont use scores create fun ,but use can make fun better clear

Stu::Stu(int t)
:name(),scores(t){}
// :name("nnn") , scores(t){}
// you can assignment name in here , compile is passed 
Stu::Stu(int t,int tt)
:name(),scores(t,tt){}

Stu::Stu(double * t,int tt)
:scores(t,tt) , name(){}

Stu::Stu(const char* t ,int tt)
:name(t) , scores(tt){}

double & Stu::operator[](int t)
{
    return scores[t];
}

ostream & operator << (ostream & os,const Stu & t)
{
    os << "name:" << t.name << endl;
    for(int i = 0 ; i < t.scores.size() ; i++ )
    {
        os << t.scores[i] << "\t";
    }
    return os << endl;
}

istream & operator>>(istream & is,Stu & t)
{
    cout << "now name is:" << t.name << "\nenter name:";
    is >> t.name;
    while (getchar() != '\n');

    cout << "have " << t.scores.size() << "element,need add please enter(dont want enter yuanlai size)" << ":";
    int n;
    is >> n;
    while (getchar() != '\n');
    
    t.scores.resize(n);
    cout << endl;    
    for(int i = 0 ; i < t.scores.size() ; i++)
    {
        is >> t.scores[i];
    }
    cout << endl;
    return is;
}

