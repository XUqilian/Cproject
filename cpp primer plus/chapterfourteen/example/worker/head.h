#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<string>
using std::string;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

// int printf(const string & t){
//     printf(t.c_str());
//     // string::c_str() return a const char* .end add '\0' 
//     return 0;
// }  //error : multiple definetion  重复定义


class Worker
{
    private:
        // char * name;
        string name;
        int id;
    public:
        Worker():name(),id(){};
        Worker(const char *str, int idnum) : name(str) , id(idnum){};
        virtual ~Worker(){}

        virtual void set() = 0;
        void show() const;
};

class Singer
:public Worker
{
    private:
        int panache;
    public:
        Singer():Worker(){};
        Singer(const char* str, int id, int pce):Worker(str ,id){};
        Singer(const Worker &t, int pce):Worker(t),panache(pce){};

        virtual void set();
        friend ostream & operator<<(ostream & , const Singer &);
};

class Waiter
:public Worker
{
    protected:
        enum{one ,two , three , four , five , six , seven};
        enum{Vtypes};
    private:
        static char* pv[Vtypes];
        int voice;
    public:
        Waiter():Worker(){};
        Waiter(const char* str, int id, int vi):Worker(str,id),voice(vi){};
        virtual ~Waiter(){}

        virtual void set();
        friend ostream & operator<<(ostream & ,const Waiter &);

};

#endif