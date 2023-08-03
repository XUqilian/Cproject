#ifndef TRYCATCH_H
#define TRYCATCH_H

#include<iostream>
#include<exception>     // 处理异常专用类
using std::cout;
using std::cin;
using std::endl;
using std::exception;

class erone:public exception
{
    public:
        const char *  what(){return "error for a = -b";}

};

class ertwo : public exception
{
    public:
        const char * what(){return "error for a < b";}
};

#endif