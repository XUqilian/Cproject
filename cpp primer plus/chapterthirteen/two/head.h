#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Cd{
    private:
        char* performers;
        char* label;
        int selections;
        double playtime;
    
    public:
        Cd();
        Cd(char* stro, char* strt,int n ,double x);  //should alt type "char*"to "const char*" 
        Cd(const Cd &);
        virtual ~Cd(){delete []performers;delete []label;}
        Cd & operator=(const Cd &);

        virtual void report()const  //report 报告  大致意思就是输出数据
            { cout << "performers:"<< performers << "\tlabel:" << label << "\tselections:" << selections << "\tplaytime:" << playtime << endl;}
        
};

class Clsc
: public Cd
{
    private:
        char* opus;

    public:
        Clsc();
        Clsc(char* stro, char* strt,int n ,double x,char* s);
        Clsc(Cd & t,char* s);
        Clsc(const Clsc &);
        virtual ~Clsc(){delete [] opus;};
        Clsc & operator = (const Clsc &);
        
        virtual void report()const{ Cd::report(); cout << "opus:"  << opus << endl;}

};


#endif