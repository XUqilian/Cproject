#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class User{
    private:
        string name;
        double amount;

    protected:          //在本类内与私有相同 但子类可以像 public 一样使用 
                        // 多用于成员函数   类内可访问 子类好使用
        int temp;   
        double valamount(){return amount;};  //这样本类在外部不能用 子类还可以使用

    public:
        User(const string &n,double a = 0){name = n;amount = a;}
        virtual ~User(){};
        
        virtual void add(double t){amount += t;}
        virtual void subtract(double t){ if(amount >= t) amount -= t;}

        virtual void display(){ cout << name << " have:" << amount << " dollars" << endl;}
        // friend ostream& operator<<(ostream &op,User &t);
        
};

class Uservip :public User
{
    private:
        double utmost;  //最大欠额
        double debt;    //已欠
        double rate;    //利率
        
    public:
        Uservip(const string &n,double a,double u=500,double r=0.12,double d = 0);
        Uservip(User &t,double u=500,double r=0.12,double d = 0);
        virtual ~Uservip(){};
        // void altumost(double t){utmost = t;}
        // void altrate(double t){ rate = t;}
        virtual void add(double t);
        virtual void subtract(double t);

        virtual void display(){ User::display();  cout << "utmost:" << utmost << " debt:" << debt << " rate:" << rate << endl;}
        // friend ostream& operator<<(ostream &op,Uservip &t){t.display();}
};

#endif