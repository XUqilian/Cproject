#ifndef CLASSER_H
#define CLASSER_H

#include<iostream>
#include<stdexcept>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::logic_error;

class Sales
{
    public:
        enum{mont = 12};
    private:
        int years;
        int sal[mont]; 
    public:
        explicit Sales(int y ) : years(y){};
        Sales(int ,int * , int );
        virtual ~Sales(){}
        virtual int& operator[](int);

        class ersales:public logic_error
        {
            private:
                int lable; // lable 标签
            public:
                explicit ersales(int i,const string s = "sales has warn."):lable(i) , logic_error(s){}  // logic_error将会将字符串传入私有 what()可访问其内容
                virtual ~ersales() throw() {}
                // 本处不带任何参数的throw()表示 该函数不向外抛出异常 通过这个函数回溯的异常会中断在这里
                // throw(int ) 只抛出int型的异常
                // throw(string , int)  只抛出 string 和 int类型的异常 可叠加 并用 , 隔开
                // throw(...)       抛出所有类型的异常
                int lab()const {return lable;}
        };
};


class Talet : public Sales
{
    private:
        string strl;
    public:
        explicit Talet(const string & s , int i) : Sales(i) , strl(s){}
        Talet(const string & s , int i , int * ar , int ari) : Sales(i, ar ,ari) , strl(s){}
        virtual ~Talet(){}
        virtual int & operator[](int );
        const string & rts()const {return strl;}
        
        class ertalet : public Sales::ersales
        {
            private:
                string str;
            public:
                explicit ertalet(const string & sl , int i , const char * s = "talet has warn.") : ersales(i,s) , str(sl){}
                virtual ~ertalet() throw(){}
                const string & bak()const {return str;}
        };
};


#endif