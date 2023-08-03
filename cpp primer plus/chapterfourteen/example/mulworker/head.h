#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
#include<string>
using std::string;
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

//  抽象基类ABC 与 虚基类MI不同

class Worker
{
    private:
        // char * name;
        string name;
        int id;
    protected:
        virtual void set() = 0;  //onle this 
        virtual void show() const = 0;  // onle this 
    public:
        Worker():name(),id(){};
        Worker(const char *str, int idnum) : name(str) , id(idnum){};
        virtual ~Worker(){}

        // operator<< is put all
        // operator >> is set all 
};

class Singer:virtual public Worker // 虚基类 继承将只会产生一个父类对象
{
    private:
        int panache;
    protected:
        virtual void set();
        virtual void show()const;
    public:
        Singer():Worker(){};            //    要对虚基类进行单独构造赋值
        Singer(const char* str, int id, int pce):Worker(str ,id){};
        Singer(const Worker &t, int pce):Worker(t),panache(pce){};

        friend istream& operator >> (istream & , Singer &);
        friend ostream & operator<<(ostream & , const Singer &);
};

class Waiter:public virtual Worker
{
    protected:
        enum{one ,two , three , four , five , six , seven};
        enum{Vtypes};
        virtual void set();
        virtual void show()const;
    private:
        static char* pv[Vtypes];
        int voice;
    public:
        Waiter():Worker(){};
        Waiter(const char* str, int id, int vi):Worker(str,id),voice(vi){};
        Waiter(const Worker & t,int vi) : Worker(t),voice(vi){}
        virtual ~Waiter(){}

        friend istream& operator >> (istream & , Waiter &);
        friend ostream & operator<<(ostream & ,const Waiter &);

};

class Wsw:public Waiter ,Singer
{
    protected:
        virtual void set();
        virtual void show()const;
    public:
        Wsw(){}
        Wsw(const char* str,int id,int pce,int vi) : Worker(str,id) , Singer(str,id,pce),Waiter(str,id,vi){};
        Wsw(const Worker & t, int pce,int vi) : Worker(t) , Singer(t,pce),Waiter(t,vi){};
        virtual ~Wsw(){}
        
        friend istream& operator >> (istream & , Wsw &);
        friend ostream & operator<<(ostream & ,const Wsw &);
};

#endif