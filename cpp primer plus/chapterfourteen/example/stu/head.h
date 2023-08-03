#ifndef HEAD_H
#define HEAD_H

// has-a

#include<iostream>
#include<string>
#include<valarray>
using std::string;
using std::valarray;
using std::istream;
using std::ostream;
using std::endl;
using std::cout;
using std::cin;

class Stu
{
    private:
        string name;
        valarray<double> scores;
        // typedef valarray<double> vad;   // can  do it simple 
    public:
        Stu();
        //
        explicit Stu(const char*);
        explicit Stu(int);
        Stu(int ,int);
        Stu(double * ,int);
        Stu(const char* ,int);
        ~Stu(){}

        double & operator[](int);  // i think this is ok ,it can be left or right value
        // double operator[](int);  //无法重载仅按返回类型区分的函数
        // double operator[](int) const; // 加上 const 可通过 但什么时候调用这个函数什么时候调用另一个呢
        friend ostream & operator << (ostream & os,const Stu &);
        friend istream & operator>>(istream & is,Stu &);
        // can classify element. input  按成员定义相应的输入函数
        // istream & getname(istream &, Stu &); 到时候直接分开使用
};


#endif