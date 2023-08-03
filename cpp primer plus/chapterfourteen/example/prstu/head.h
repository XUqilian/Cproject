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
:private string , valarray<double>  
// 私有继承 继承类模块而非类 会生成无名类对象 所以不用类内声明对象 
// 但好像只能生成一个该类型对象 
// 使用或调用将基于类型名加域解析运算符
{
    private:
        // string name;
        // valarray<double> scores;
        // typedef valarray<double> vad;   // can  do it simple 

    public:
        using std::valarray<double>::operator[];

        Stu(){}  // 试试不用初始化会不会出问题

        explicit Stu(const char* t)
        :string(t) , valarray<double>(){} 
        // 利用类型名赋值生成无名对象 因为对象无名 所以使用只能依靠类型名加域解析运算符
        // 而且因为是直接用类型名使用的无名对象 所以在类中无法存在第二个同类对象 使用时会混乱
        // 如果没有用 using std::string  这里就得 std::string(t)
        // typedef 不会受影响 依旧可以用其缩短书写代码类型长度

        explicit Stu(int t)
        :string() , valarray<double>(t){} 

        Stu(int t,int tt)
        :string() , valarray<double>(t,tt){} 

        Stu(double * t,int tt)
        :string() , valarray<double>(t,tt){} 

        Stu(const char* t ,int tt)
        :string(t) , valarray<double>(tt){} 


        double & operator[](int);  // i think this is ok ,it can be left or right value
        // double operator[](int);  //无法重载仅按返回类型区分的函数
        // double operator[](int) const; // 加上 const 可通过 但什么时候调用这个函数什么时候调用另一个呢
        friend ostream & operator << (ostream & os,const Stu &);
        friend istream & operator>>(istream & is,Stu &);
        // can classify element. input  按成员定义相应的输入函数
        // istream & getname(istream &, Stu &); 到时候直接分开使用
};


#endif