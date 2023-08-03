#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>

class golf
{
private:
    static const int Len = 40;
    char fname[Len];
    int handicp;

public:
    void setgolf(char *, int);
    int setgolf();
    void sethandicp(int);
    void showgolf() const;
};

#endif