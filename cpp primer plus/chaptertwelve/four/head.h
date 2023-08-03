#ifndef HEAD_H
#define HEAD_H

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

typedef unsigned long Item;

class Stack
{
    private:
        enum{max = 10};
    private:
        Item * pitem;
        int size;
        int top;
    public:
        Stack(int n = max);
        Stack(const Stack &st);
        ~Stack();
        bool isempty()const;
        bool isfull()const;
        bool push(const Item &it);
        bool pop(Item & it);
        Stack & operator=(const Stack & st);
};

#endif
