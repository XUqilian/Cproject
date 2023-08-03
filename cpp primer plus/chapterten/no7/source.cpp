#include "head.h"

plorg::plorg(const char nam[20], int t)
{
    for (int i = 0; nam[i] != '\0'; i++)
    {
        name[i] = nam[i];
    }
    cl = t;
}

void plorg::set(int t)
{
    cl = t;
}

void plorg::display() const
{
    printf("name:%s\tcl:%d", name, cl);
}