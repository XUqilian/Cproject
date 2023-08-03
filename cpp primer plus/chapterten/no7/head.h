#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>

class plorg
{
private:
    char name[20] = {'\0'};
    int cl;

public:
    ~plorg(){};
    plorg(const char nam[20] = "plorg", int t = 50);
    //如果确认要传入字符串常量，要对其进行限定
    void set(int);
    void display() const;
};

#endif